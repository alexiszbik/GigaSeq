#include "WaterInMidiRules.h"

#include "InMidiRules.h"

namespace {

bool isBlackKeyPitchClass(uint8_t pitchClass)
{
    switch (pitchClass) {
        case 1:
        case 3:
        case 6:
        case 8:
        case 10:
            return true;
        default:
            return false;
    }
}

uint8_t snapToBlackKey(uint8_t note)
{
    if (isBlackKeyPitchClass(note % 12)) {
        return note;
    }

    for (int candidate = static_cast<int>(note) + 1; candidate <= 127; ++candidate) {
        if (isBlackKeyPitchClass(static_cast<uint8_t>(candidate % 12))) {
            return static_cast<uint8_t>(candidate);
        }
    }

    return 127;
}

} // namespace

WaterChordInMidiRules kWaterChordInRules;

int8_t WaterChordInMidiRules::findHeld(uint8_t channel, uint8_t inputNote) const
{
    for (uint8_t i = 0; i < heldInputCount_; ++i) {
        if (heldInputs_[i].channel == channel && heldInputs_[i].inputNote == inputNote) {
            return static_cast<int8_t>(i);
        }
    }

    return -1;
}

int8_t WaterChordInMidiRules::allocateHeld(uint8_t channel, uint8_t inputNote)
{
    const int8_t existing = findHeld(channel, inputNote);
    if (existing >= 0) {
        return existing;
    }

    if (heldInputCount_ >= kMaxHeldInputs) {
        return -1;
    }

    HeldInput& held = heldInputs_[heldInputCount_];
    held.channel = channel;
    held.inputNote = inputNote;
    held.outputCount = 0;
    ++heldInputCount_;
    return static_cast<int8_t>(heldInputCount_ - 1);
}

void WaterChordInMidiRules::releaseHeld(HeldInput& held, MidiInOut& midi)
{
    for (uint8_t i = 0; i < held.outputCount; ++i) {
        midi.sendNoteOff(held.channel, held.outputNotes[i], 0);
    }

    held.outputCount = 0;
}

void WaterChordInMidiRules::emitChord(
    uint8_t channel,
    uint8_t note,
    uint8_t velocity,
    const InMidiRulesConfig& config,
    HeldInput& held,
    MidiInOut& midi)
{
    const uint8_t root = transposeMidiNote(note, config.transposeSemitones);
    const int fifthNote = static_cast<int>(root) + kFifthInterval;
    const uint8_t fifth = fifthNote > 127 ? 127 : static_cast<uint8_t>(fifthNote);

    const uint8_t rootOut = snapToBlackKey(root);
    const uint8_t fifthOut = snapToBlackKey(fifth);

    held.outputCount = 0;
    held.outputNotes[held.outputCount++] = rootOut;

    if (fifthOut != rootOut && held.outputCount < kMaxOutputs) {
        held.outputNotes[held.outputCount++] = fifthOut;
    }

    for (uint8_t i = 0; i < held.outputCount; ++i) {
        midi.sendNoteOn(channel, held.outputNotes[i], velocity);
    }
}

void WaterChordInMidiRules::processNoteOn(
    uint8_t channel,
    uint8_t note,
    uint8_t velocity,
    const InMidiRulesConfig& config,
    MidiInOut& midi)
{
    const int8_t heldIndex = allocateHeld(channel, note);
    if (heldIndex < 0) {
        return;
    }

    HeldInput& held = heldInputs_[heldIndex];
    releaseHeld(held, midi);
    emitChord(channel, note, velocity, config, held, midi);
}

void WaterChordInMidiRules::processNoteOff(
    uint8_t channel,
    uint8_t note,
    uint8_t velocity,
    const InMidiRulesConfig& config,
    MidiInOut& midi)
{
    const int8_t heldIndex = findHeld(channel, note);
    if (heldIndex < 0) {
        return;
    }

    HeldInput& held = heldInputs_[heldIndex];
    releaseHeld(held, midi);

    for (uint8_t i = static_cast<uint8_t>(heldIndex); i + 1 < heldInputCount_; ++i) {
        heldInputs_[i] = heldInputs_[i + 1];
    }

    --heldInputCount_;
}

void WaterChordInMidiRules::reset()
{
    heldInputCount_ = 0;
}

void WaterChordInMidiRules::releaseHeldNotes(MidiInOut& midi)
{
    for (uint8_t i = 0; i < heldInputCount_; ++i) {
        releaseHeld(heldInputs_[i], midi);
    }

    heldInputCount_ = 0;
}

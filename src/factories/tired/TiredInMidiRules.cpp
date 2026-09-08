#include "TiredInMidiRules.h"

#include "midiinrules/InMidiRules.h"

namespace {

uint8_t snapToRange(uint8_t note, uint8_t minNote, uint8_t maxNote)
{
    const uint8_t pitchClass = note % 12;

    for (uint8_t candidate = minNote; candidate <= maxNote; ++candidate) {
        if (candidate % 12 == pitchClass) {
            return candidate;
        }
    }

    return minNote;
}

} // namespace

TiredChordInMidiRules kTiredChordInRules;

int8_t TiredChordInMidiRules::findHeld(uint8_t channel, uint8_t inputNote) const
{
    for (uint8_t i = 0; i < heldInputCount_; ++i) {
        if (heldInputs_[i].channel == channel && heldInputs_[i].inputNote == inputNote) {
            return static_cast<int8_t>(i);
        }
    }

    return -1;
}

int8_t TiredChordInMidiRules::allocateHeld(uint8_t channel, uint8_t inputNote)
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
    held.outputNote = 0;
    ++heldInputCount_;
    return static_cast<int8_t>(heldInputCount_ - 1);
}

void TiredChordInMidiRules::releaseHeld(HeldInput& held, MidiInOut& midi)
{
    midi.sendNoteOff(held.channel, held.outputNote, 0);
    held.outputNote = 0;
}

void TiredChordInMidiRules::processNoteOn(
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

    const uint8_t outputNote = heldInputCount_ == 1
        ? snapToRange(transposeMidiNote(note, config.transposeSemitones), kMinRootNote, kMaxRootNote)
        : note;

    held.outputNote = outputNote;
    midi.sendNoteOn(channel, outputNote, velocity);
}

void TiredChordInMidiRules::processNoteOff(
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

void TiredChordInMidiRules::reset()
{
    heldInputCount_ = 0;
}

void TiredChordInMidiRules::releaseHeldNotes(MidiInOut& midi)
{
    for (uint8_t i = 0; i < heldInputCount_; ++i) {
        releaseHeld(heldInputs_[i], midi);
    }

    reset();
}

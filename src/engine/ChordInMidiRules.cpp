#include "ChordInMidiRules.h"

ChordInMidiRules::ChordInMidiRules(const int8_t* intervals, uint8_t intervalCount)
{
    intervalCount_ = intervalCount > kMaxIntervals ? kMaxIntervals : intervalCount;

    for (uint8_t i = 0; i < intervalCount_; ++i) {
        intervals_[i] = intervals[i];
    }
}

int8_t ChordInMidiRules::findHeld(uint8_t channel, uint8_t inputNote) const
{
    for (uint8_t i = 0; i < heldInputCount_; ++i) {
        if (heldInputs_[i].channel == channel && heldInputs_[i].inputNote == inputNote) {
            return static_cast<int8_t>(i);
        }
    }

    return -1;
}

int8_t ChordInMidiRules::allocateHeld(uint8_t channel, uint8_t inputNote)
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

void ChordInMidiRules::releaseHeld(HeldInput& held, MidiInOut& midi)
{
    for (uint8_t i = 0; i < held.outputCount; ++i) {
        midi.sendNoteOff(held.channel, held.outputNotes[i], 0);
    }

    held.outputCount = 0;
}

void ChordInMidiRules::processNoteOn(
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

    const uint8_t root = transposeMidiNote(note, config.transposeSemitones);
    held.outputCount = intervalCount_;

    for (uint8_t i = 0; i < intervalCount_; ++i) {
        const uint8_t outNote = transposeMidiNote(root, intervals_[i]);
        held.outputNotes[i] = outNote;
        midi.sendNoteOn(channel, outNote, velocity);
    }
}

void ChordInMidiRules::processNoteOff(
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

void ChordInMidiRules::reset()
{
    heldInputCount_ = 0;
}

void ChordInMidiRules::releaseHeldNotes(MidiInOut& midi)
{
    for (uint8_t i = 0; i < heldInputCount_; ++i) {
        releaseHeld(heldInputs_[i], midi);
    }

    heldInputCount_ = 0;
}

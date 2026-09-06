#pragma once

#include "InMidiRules.h"

#include <cstdint>

class ChordInMidiRules : public InMidiRules
{
public:
    ChordInMidiRules(const int8_t* intervals, uint8_t intervalCount);

    void processNoteOn(
        uint8_t channel,
        uint8_t note,
        uint8_t velocity,
        const InMidiRulesConfig& config,
        MidiInOut& midi) override;

    void processNoteOff(
        uint8_t channel,
        uint8_t note,
        uint8_t velocity,
        const InMidiRulesConfig& config,
        MidiInOut& midi) override;

    void reset() override;
    void releaseHeldNotes(MidiInOut& midi) override;

private:
    static constexpr uint8_t kMaxIntervals = 4;
    static constexpr uint8_t kMaxHeldInputs = 16;

    struct HeldInput
    {
        uint8_t channel = 0;
        uint8_t inputNote = 0;
        uint8_t outputCount = 0;
        uint8_t outputNotes[kMaxIntervals] = {};
    };

    int8_t findHeld(uint8_t channel, uint8_t inputNote) const;
    int8_t allocateHeld(uint8_t channel, uint8_t inputNote);
    void releaseHeld(HeldInput& held, MidiInOut& midi);

    int8_t intervals_[kMaxIntervals] = {};
    uint8_t intervalCount_ = 0;
    HeldInput heldInputs_[kMaxHeldInputs] = {};
    uint8_t heldInputCount_ = 0;
};

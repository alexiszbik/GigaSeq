#pragma once

#include "midiinrules/InMidiRules.h"

#include <cstdint>

class TiredChordInMidiRules : public InMidiRules
{
public:
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
    static constexpr uint8_t kMinRootNote = 36;
    static constexpr uint8_t kMaxRootNote = 48;
    static constexpr uint8_t kMaxHeldInputs = 10;

    struct HeldInput
    {
        uint8_t channel = 0;
        uint8_t inputNote = 0;
        uint8_t outputNote = 0;
    };

    int8_t findHeld(uint8_t channel, uint8_t inputNote) const;
    int8_t allocateHeld(uint8_t channel, uint8_t inputNote);
    void releaseHeld(HeldInput& held, MidiInOut& midi);

    HeldInput heldInputs_[kMaxHeldInputs] = {};
    uint8_t heldInputCount_ = 0;
};

extern TiredChordInMidiRules kTiredChordInRules;

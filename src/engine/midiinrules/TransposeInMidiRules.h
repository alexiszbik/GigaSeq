#pragma once

#include "midiinrules/InMidiRules.h"

class TransposeInMidiRules : public InMidiRules
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
};

extern TransposeInMidiRules kTransposeInMidiRules;

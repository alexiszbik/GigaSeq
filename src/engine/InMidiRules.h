#pragma once

#include "MidiInOut.h"

#include <cstdint>

struct InMidiRulesConfig
{
    int8_t transposeSemitones = 0;
};

class InMidiRules
{
public:
    virtual ~InMidiRules() = default;

    virtual void processNoteOn(
        uint8_t channel,
        uint8_t note,
        uint8_t velocity,
        const InMidiRulesConfig& config,
        MidiInOut& midi) = 0;

    virtual void processNoteOff(
        uint8_t channel,
        uint8_t note,
        uint8_t velocity,
        const InMidiRulesConfig& config,
        MidiInOut& midi) = 0;

    virtual void reset() {}

    virtual void releaseHeldNotes(MidiInOut& midi) {}
};

uint8_t transposeMidiNote(uint8_t note, int8_t semitones) noexcept;

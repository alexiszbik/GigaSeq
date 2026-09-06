#pragma once

#include <cstdint>

class MidiInputHandler
{
public:
    virtual ~MidiInputHandler() = default;

    virtual void handleNoteOn(uint8_t channel, uint8_t note, uint8_t velocity) = 0;
    virtual void handleNoteOff(uint8_t channel, uint8_t note, uint8_t velocity) = 0;
};

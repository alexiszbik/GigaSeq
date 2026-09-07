#pragma once

#include "OutMidiRules.h"

class FallingLedRules : public OutMidiRules
{
public:
    void processNoteOn(const Note& note, uint8_t channel, tick_t durationTicks, MidiInOut& midi) override;
};

extern FallingLedRules kFallingLedRules;

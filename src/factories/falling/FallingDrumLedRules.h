#pragma once

#include "OutMidiRules.h"

class FallingDrumLedRules : public OutMidiRules
{
public:
    void processNoteOn(const Note& note, uint8_t channel, tick_t durationTicks, MidiInOut& midi) override;
};

extern FallingDrumLedRules kFallingDrumLedRules;

#pragma once

#include "OutMidiRules.h"

class CloserLedRules : public OutMidiRules
{
public:
    void processNoteOn(const Note& note, uint8_t channel, tick_t durationTicks, MidiInOut& midi) override;
};

extern CloserLedRules kCloserLedRules;

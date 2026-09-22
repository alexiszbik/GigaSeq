#pragma once

#include "outmidirules/OutMidiRules.h"

class TiredLedRules : public OutMidiRules
{
public:
    void processNoteOn(const Note& note, uint8_t channel, tick_t durationTicks, MidiInOut& midi) override;
};

extern TiredLedRules kTiredLedRules;

#pragma once

#include "OutMidiRules.h"

class WaterLedRules : public OutMidiRules
{
public:
    void processNoteOn(const Note& note, uint8_t channel, tick_t durationTicks, MidiInOut& midi) override;
};

extern WaterLedRules kWaterFmbassLedRules;

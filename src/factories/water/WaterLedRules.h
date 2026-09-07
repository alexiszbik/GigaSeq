#pragma once

#include "OutMidiRules.h"

class WaterLedRules : public OutMidiRules
{
public:
    void processNoteOn(const Note& note, uint8_t channel, tick_t durationTicks, MidiInOut& midi) override;
    void reset() override;

private:
    uint8_t rngState_ = 1;
};

extern WaterLedRules kWaterFmbassLedRules;

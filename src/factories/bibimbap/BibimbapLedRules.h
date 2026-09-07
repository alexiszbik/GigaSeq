#pragma once

#include "OutMidiRules.h"

class BibimbapLedRules : public OutMidiRules
{
public:
    void processNoteOn(const Note& note, uint8_t channel, tick_t durationTicks, MidiInOut& midi) override;

private:
    uint8_t rngState_ = 1;
    uint8_t rngState_B = 1;
};

extern BibimbapLedRules kBibimbapLedRules;

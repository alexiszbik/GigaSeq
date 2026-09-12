#pragma once

#include "MidiInOut.h"
#include "Tick.h"

#include <cstdint>

struct ActiveNote
{
    uint8_t channel = 0;
    uint8_t note = 0;
    tick_t remainingTicks = 0;
};

class ActiveNotePool
{
public:
    void startNote(
        uint8_t channel,
        uint8_t note,
        uint8_t velocity,
        tick_t durationTicks,
        MidiInOut& midi);

    void processTick(MidiInOut& midi);
    void releaseAll(MidiInOut& midi);
    void reset();

private:
    static constexpr uint8_t kMaxActiveNotes = 32;

    ActiveNote activeNotes_[kMaxActiveNotes];
    uint8_t activeNoteCount_ = 0;
};

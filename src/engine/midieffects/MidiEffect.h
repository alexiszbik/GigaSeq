#pragma once

#include "ActiveNotePool.h"
#include "MidiInOut.h"
#include "Note.h"
#include "Tick.h"

#include <cstdint>

class MidiEffect
{
public:
    virtual ~MidiEffect() = default;
    virtual void reset() {}

    // Called when a pattern note fires — stores trigger info, does not send MIDI.
    virtual void onSourceNote(const Note& note, tick_t durationTicks, tick_t startTick) = 0;

    // Called every clock tick within pattern bounds — local is position - patternStart.
    virtual void processTick(
        tick_t local,
        uint8_t channel,
        ActiveNotePool& activeNotes,
        MidiInOut& midi) = 0;
};

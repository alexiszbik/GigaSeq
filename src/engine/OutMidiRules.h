#pragma once

#include "ActiveNotePool.h"
#include "MidiInOut.h"
#include "Note.h"
#include "Tick.h"

class OutMidiRules
{
public:
    virtual ~OutMidiRules() = default;

    virtual void processNoteOn(const Note& note, uint8_t channel, tick_t durationTicks, MidiInOut& midi) = 0;
    virtual void reset();

    void processTick(MidiInOut& midi);
    void releaseActiveNotes(MidiInOut& midi);

protected:
    void addNote(uint8_t targetChannel, uint8_t note, uint8_t velocity, tick_t durationTicks, MidiInOut& midi);

private:
    ActiveNotePool activeNotes_;
};

#include "OutMidiRules.h"

void OutMidiRules::reset()
{
    activeNotes_.reset();
}

void OutMidiRules::addNote(
    uint8_t targetChannel,
    uint8_t note,
    uint8_t velocity,
    tick_t durationTicks,
    MidiInOut& midi)
{
    activeNotes_.startNote(targetChannel, note, velocity, durationTicks, midi);
}

void OutMidiRules::processTick(MidiInOut& midi)
{
    activeNotes_.processTick(midi);
}

void OutMidiRules::releaseActiveNotes(MidiInOut& midi)
{
    activeNotes_.releaseAll(midi);
}

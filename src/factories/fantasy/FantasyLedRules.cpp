#include "FantasyLedRules.h"
#include "FantasySamples.h"
#include "MidiChannel.h"
#include "MidiConst.h"

FantasyLedRules kFantasyLedRules;

bool isPolySynth(uint8_t channel)
{
    return channel == MidiChannel::kPoly;
}

void FantasyLedRules::processNoteOn(
    const Note& note,
    uint8_t channel,
    tick_t durationTicks,
    MidiInOut& midi)
{
    if (isPolySynth(channel)) {
        addNote(MidiChannel::kLedStrips, LedStrips::kBlue_ALL, note.velocity, durationTicks * 0.75, midi);
        return;
    }
}

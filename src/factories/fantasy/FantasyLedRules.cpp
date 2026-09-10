#include "FantasyLedRules.h"
#include "FantasySamples.h"
#include "MidiChannel.h"
#include "MidiConst.h"

FantasyLedRules kFantasyLedRules;

bool isPolySynth(uint8_t channel)
{
    return channel == MidiChannel::kPoly;
}


bool is909SnareNote(uint8_t channel, uint8_t note)
{
    return channel == MidiChannel::kDrums && note == Fantasy::fant909;
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
    if (is909SnareNote(channel, note.note)) {
        addNote(MidiChannel::kLedStrips, LedStrips::kWhiteLeds[whiteLedIndex], note.velocity, 12, midi);
        whiteLedIndex++;
        if (whiteLedIndex >= LedStrips::kWhiteLedCount) {
            whiteLedIndex = 0;
        }
        return;
    }
}

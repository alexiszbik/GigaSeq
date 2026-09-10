#include "FantasyLedRaveRules.h"
#include "FantasySamples.h"
#include "MidiChannel.h"
#include "MidiConst.h"

FantasyLedRaveRules kFantasyLedRaveRules;

bool is909SnareNote(uint8_t channel, uint8_t note)
{
    return channel == MidiChannel::kDrums && note == Fantasy::fant909;
}


void FantasyLedRaveRules::processNoteOn(
    const Note& note,
    uint8_t channel,
    tick_t durationTicks,
    MidiInOut& midi)
{
    if (is909SnareNote(channel, note.note)) {
        addNote(MidiChannel::kLedStrips, LedStrips::kWhiteLeds[whiteLedIndex], note.velocity, 24, midi);
        whiteLedIndex++;
        if (whiteLedIndex >= LedStrips::kWhiteLedCount) {
            whiteLedIndex = 0;
        }
        return;
    }
}

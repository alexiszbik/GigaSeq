#include "TiredLedRules.h"

#include "MidiChannel.h"
#include "MidiConst.h"
#include "TiredSamples.h"

TiredLedRules kTiredLedRules;

bool isKick(uint8_t channel, uint8_t note)
{
    return channel == MidiChannel::kDrums
        && (note == Tired::tiredKick);
}

bool isSnareDrop(uint8_t channel, uint8_t note)
{
    return channel == MidiChannel::kDrums
        && (note == Tired::shortsnr);
}

void TiredLedRules::processNoteOn(
    const Note& note,
    uint8_t channel,
    tick_t durationTicks,
    MidiInOut& midi)
{
    if (isKick(channel, note.note) ) {
        addNote(MidiChannel::kLedStrips, LedStrips::kRed_ALL, note.velocity, 24, midi);
        return;
    }
    if (isSnareDrop(channel, note.note) ) {
        const uint8_t ledNote = LedStrips::kWhiteLedsRandom.nextRandom();
        addNote(MidiChannel::kLedStrips, ledNote, note.velocity, durationTicks, midi);
        return;
    }
}

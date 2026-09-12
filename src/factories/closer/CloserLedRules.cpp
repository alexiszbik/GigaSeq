#include "CloserLedRules.h"
#include "CloserSamples.h"

#include "MidiChannel.h"
#include "MidiConst.h"

CloserLedRules kCloserLedRules;

bool isClapNote(uint8_t channel, uint8_t note)
{
    return note == Closer::triClp
        && (channel == MidiChannel::kDrums || channel == MidiChannel::kSampler);
}

bool isSnareNote(uint8_t channel, uint8_t note)
{
    return note == Closer::discoSnr
        && (channel == MidiChannel::kDrums || channel == MidiChannel::kSampler);
}

void CloserLedRules::processNoteOn(
    const Note& note,
    uint8_t channel,
    tick_t durationTicks,
    MidiInOut& midi)
{
    if (isClapNote(channel, note.note)) {
        addNote(MidiChannel::kLedStrips, LedStrips::kBlue_ALL, note.velocity, durationTicks, midi);
        addNote(MidiChannel::kLedStrips, LedStrips::kGreen_ALL, note.velocity, durationTicks, midi);
    }

    if (isSnareNote(channel, note.note)) {
        addNote(MidiChannel::kLedStrips, LedStrips::kWhite_ALL, note.velocity, durationTicks, midi);
    }
}

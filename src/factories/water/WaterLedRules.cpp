#include "WaterLedRules.h"

#include "MidiChannel.h"
#include "MidiConst.h"
#include "WaterSamples.h"

namespace {

bool isFmbassNote(uint8_t note)
{
    return note == Water::fmbassgd
        || note == Water::fmbasscd
        || note == Water::fmbassad;
}

} // namespace

WaterLedRules kWaterFmbassLedRules;

void WaterLedRules::processNoteOn(
    const Note& note,
    uint8_t channel,
    tick_t durationTicks,
    MidiInOut& midi)
{
    if (channel == MidiChannel::kSampler && isFmbassNote(note.note)) {
        const uint8_t ledNote = LedStrips::kWhiteLedsRandom.nextRandom();
        addNote(MidiChannel::kLedStrips, ledNote, note.velocity, durationTicks, midi);
    } else if (channel == MidiChannel::kMicrofreak) {
        addNote(MidiChannel::kLedStrips, LedStrips::kBlue_D, note.velocity, durationTicks, midi);
        addNote(MidiChannel::kLedStrips, LedStrips::kGreen_D, note.velocity, durationTicks, midi);
    }
}

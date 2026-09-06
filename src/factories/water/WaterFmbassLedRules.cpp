#include "WaterFmbassLedRules.h"

#include "MidiChannel.h"
#include "MidiConst.h"
#include "RandomHelper.h"
#include "WaterSamples.h"

namespace {

constexpr uint8_t kWhiteLeds[] = {
    LedStrips::kWhite_A,
    LedStrips::kWhite_B,
    LedStrips::kWhite_C,
    LedStrips::kWhite_D,
};

constexpr uint8_t kWhiteLedCount = sizeof(kWhiteLeds) / sizeof(kWhiteLeds[0]);

bool isFmbassNote(uint8_t note)
{
    return note == Water::fmbassgd
        || note == Water::fmbasscd
        || note == Water::fmbassad;
}

} // namespace

WaterFmbassLedRules kWaterFmbassLedRules;

void WaterFmbassLedRules::processNoteOn(
    const Note& note,
    uint8_t channel,
    tick_t durationTicks,
    MidiInOut& midi)
{
    if (channel == MidiChannel::kSampler && isFmbassNote(note.note)) {
        const uint8_t ledNote = kWhiteLeds[RandomHelper::nextRandomIndex(rngState_, kWhiteLedCount)];
        addNote(MidiChannel::kLedStrips, ledNote, note.velocity, durationTicks, midi);
    } else if (channel == MidiChannel::kMicrofreak) {
        addNote(MidiChannel::kLedStrips, LedStrips::kBlue_D, note.velocity, durationTicks, midi);
        addNote(MidiChannel::kLedStrips, LedStrips::kGreen_D, note.velocity, durationTicks, midi);
    }
}

void WaterFmbassLedRules::reset()
{
    OutMidiRules::reset();
    rngState_ = 1;
}

#include "FallingDrumLedRules.h"

#include "factories/falling/FallingSamples.h"
#include "MidiChannel.h"
#include "MidiConst.h"

namespace {

constexpr uint8_t kSnareLeds[] = {
    LedStrips::kBlue_A,
    LedStrips::kBlue_B,
    LedStrips::kBlue_D,
};

bool isKickNote(uint8_t channel, uint8_t note)
{
    return note == Falling::faKick
        && (channel == MidiChannel::kDrums || channel == MidiChannel::kSampler);
}

bool isSnareNote(uint8_t channel, uint8_t note)
{
    return channel == MidiChannel::kDrums
        && (note == Falling::faSnr || note == Falling::faClap);
}

} // namespace

FallingDrumLedRules kFallingDrumLedRules;

void FallingDrumLedRules::processNoteOn(
    const Note& note,
    uint8_t channel,
    tick_t durationTicks,
    MidiInOut& midi)
{
    if (isKickNote(channel, note.note)) {
        addNote(MidiChannel::kLedStrips, LedStrips::kBlue_C, note.velocity, durationTicks, midi);
        return;
    }

    if (isSnareNote(channel, note.note)) {
        for (uint8_t ledNote : kSnareLeds) {
            addNote(MidiChannel::kLedStrips, ledNote, note.velocity, durationTicks, midi);
        }
    }
}

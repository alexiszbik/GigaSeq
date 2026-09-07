#include "FriendshipLedRules.h"

#include "MidiChannel.h"
#include "MidiConst.h"

#include "FriendshipSamples.h"

FriendshipLedRules kFriendshipLedRules;

bool isPerc(uint8_t channel, uint8_t note)
{
    return channel == MidiChannel::kDrums
        && (note == Friendship::fbrClp || note == Friendship::n707cow);
}

bool isBravery(uint8_t channel, uint8_t note)
{
    return channel == MidiChannel::kDrums
        && (note == Friendship::fbrSpl2);
}

bool isVocalHit(uint8_t channel, uint8_t note)
{
    return channel == MidiChannel::kDrums
        && (note == Friendship::fbV1 || note == Friendship::fbV2 || note == Friendship::fbV3 || note == Friendship::fbV4);
}

bool isSnare909(uint8_t channel, uint8_t note)
{
    return channel == MidiChannel::kDrums
        && (note == Friendship::snr909);
}

void FriendshipLedRules::processNoteOn(
    const Note& note,
    uint8_t channel,
    tick_t durationTicks,
    MidiInOut& midi)
{
    if (isPerc(channel, note.note) ) {
        addNote(MidiChannel::kLedStrips, LedStrips::kWhite_ALL, note.velocity, 12, midi);
        return;
    }

    if (isSnare909(channel, note.note) ) {
        addNote(MidiChannel::kLedStrips, LedStrips::kWhiteLeds[whiteLedIndex], note.velocity, 12, midi);
        whiteLedIndex++;
        if (whiteLedIndex >= LedStrips::kWhiteLedCount) {
            whiteLedIndex = 0;
        }
        return;
    }

    if (isBravery(channel, note.note) ) {
        addNote(MidiChannel::kLedStrips, LedStrips::kWhite_ALL, note.velocity, durationTicks, midi);
        return;
    }
    if (isVocalHit(channel, note.note) ) {
        addNote(MidiChannel::kLedStrips, LedStrips::kWhiteLedsRandom.nextRandom(), note.velocity, 12, midi);
        return;
    }

}

#pragma once

#include "SequenceTrack.h"

class FriendshipTrackFactory
{
public:

    static SequenceTrack friendshipStabs(tick_t lengthInTicks, tick_t startInTicks);
    static SequenceTrack friendshipHats(tick_t lengthInTicks, tick_t startInTicks);
    static SequenceTrack friendshipVoiceSynth(tick_t lengthInTicks, tick_t startInTicks);
    static SequenceTrack friendshipRiser(tick_t lengthInTicks, tick_t startInTicks);
    static SequenceTrack friendshipCowClap(tick_t lengthInTicks, tick_t startInTicks);
    static SequenceTrack friendshipBravery(tick_t lengthInTicks, tick_t startInTicks);
    static SequenceTrack friendshipXylo(tick_t lengthInTicks, tick_t startInTicks);
    static SequenceTrack friendshipChords(tick_t lengthInTicks, tick_t startInTicks);
    static SequenceTrack friendshipBalafon(tick_t lengthInTicks, tick_t startInTicks);
    static SequenceTrack friendshipDrop(tick_t lengthInTicks, tick_t startInTicks);
    static SequenceTrack friendshipSeqVoice(tick_t lengthInTicks, tick_t startInTicks);
    static SequenceTrack friendshipTrance(tick_t lengthInTicks, tick_t startInTicks);
};

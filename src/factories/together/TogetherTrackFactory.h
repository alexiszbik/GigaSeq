#pragma once

#include "SequenceTrack.h"

class TogetherTrackFactory
{
public:
    static SequenceTrack togetherArp(tick_t lengthInTicks);
    static SequenceTrack togetherHiDrum(tick_t lengthInTicks);
    static SequenceTrack togetherSample(tick_t lengthInTicks);
    static SequenceTrack togetherDX7(tick_t lengthInTicks);
    static SequenceTrack togetherVocoder(tick_t lengthInTicks);

    static SequenceTrack togetherSampleRepeat(tick_t lengthInTicks);
    static SequenceTrack togetherKickRepeat(tick_t lengthInTicks);
    static SequenceTrack togetherExtraBass(tick_t lengthInTicks);
    static SequenceTrack togetherEndRiser(tick_t lengthInTicks);

    static SequenceTrack togetherPartBSampleCut(tick_t lengthInTicks);
    static SequenceTrack togetherPartBSynth(tick_t lengthInTicks);
    static SequenceTrack togetherPartBAh(tick_t lengthInTicks);
    static SequenceTrack togetherPartBDaDaDa(tick_t lengthInTicks);
    static SequenceTrack togetherHatsOnly(tick_t lengthInTicks);

    static SequenceTrack togetherPartBJC(tick_t lengthInTicks);
    static SequenceTrack togetherPartBTambourin(tick_t lengthInTicks);
    static SequenceTrack togetherPartBCymbal(tick_t lengthInTicks);
};

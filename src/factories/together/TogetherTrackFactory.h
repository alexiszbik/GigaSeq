#pragma once

#include "SequenceTrack.h"

class TogetherTrackFactory
{
public:
    static SequenceTrack togetherArp(tick_t lengthInTicks, tick_t startInTicks);
    static SequenceTrack togetherHiDrum(tick_t lengthInTicks, tick_t startInTicks);
    static SequenceTrack togetherSample(tick_t lengthInTicks, tick_t startInTicks);
    static SequenceTrack togetherDX7(tick_t lengthInTicks, tick_t startInTicks);
    static SequenceTrack togetherVocoder(tick_t lengthInTicks, tick_t startInTicks);

    static SequenceTrack togetherSampleRepeat(tick_t lengthInTicks, tick_t startInTicks);
    static SequenceTrack togetherKickRepeat(tick_t lengthInTicks, tick_t startInTicks);
    static SequenceTrack togetherExtraBass(tick_t lengthInTicks, tick_t startInTicks);
    static SequenceTrack togetherEndRiser(tick_t lengthInTicks, tick_t startInTicks);

    static SequenceTrack togetherPartBSampleCut(tick_t lengthInTicks, tick_t startInTicks);
    static SequenceTrack togetherPartBSynth(tick_t lengthInTicks, tick_t startInTicks);
    static SequenceTrack togetherPartBAh(tick_t lengthInTicks, tick_t startInTicks);
    static SequenceTrack togetherPartBDaDaDa(tick_t lengthInTicks, tick_t startInTicks);
    static SequenceTrack togetherHatsOnly(tick_t lengthInTicks, tick_t startInTicks);

    static SequenceTrack togetherPartBJC(tick_t lengthInTicks, tick_t startInTicks);
    static SequenceTrack togetherPartBTambourin(tick_t lengthInTicks, tick_t startInTicks);
    static SequenceTrack togetherPartBCymbal(tick_t lengthInTicks, tick_t startInTicks);
};

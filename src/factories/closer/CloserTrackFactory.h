#pragma once

#include "SequenceTrack.h"

class CloserTrackFactory
{
public:
 static SequenceTrack closerHats(tick_t lengthInTicks, tick_t startInTicks);

    static SequenceTrack closerLoopHat(tick_t lengthInTicks, tick_t startInTicks);
    static SequenceTrack closerTambourin(tick_t lengthInTicks, tick_t startInTicks);
    static SequenceTrack closerClapTom(tick_t lengthInTicks, tick_t startInTicks);
    static SequenceTrack closerRiser(tick_t lengthInTicks, tick_t startInTicks);
    static SequenceTrack closerModular(tick_t lengthInTicks, tick_t startInTicks);
    static SequenceTrack closerStab(tick_t lengthInTicks, tick_t startInTicks);
    static SequenceTrack closerFill808(tick_t lengthInTicks, tick_t startInTicks);
    static SequenceTrack closerChords(tick_t lengthInTicks, tick_t startInTicks);
    static SequenceTrack closerSing(tick_t lengthInTicks, tick_t startInTicks);
    static SequenceTrack closerTop(tick_t lengthInTicks, tick_t startInTicks);
};

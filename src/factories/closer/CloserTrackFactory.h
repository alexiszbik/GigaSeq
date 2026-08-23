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
};

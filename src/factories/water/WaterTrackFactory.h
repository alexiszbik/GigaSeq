#pragma once

#include "SequenceTrack.h"

class WaterTrackFactory
{
public:
    static SequenceTrack waterHats(tick_t lengthInTicks);
    static SequenceTrack waterArp(tick_t lengthInTicks);

};

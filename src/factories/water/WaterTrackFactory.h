#pragma once

#include "SequenceTrack.h"

class WaterTrackFactory
{
public:
    static SequenceTrack waterHats(tick_t lengthInTicks);
    static SequenceTrack waterMarimba(tick_t lengthInTicks);

    static SequenceTrack waterFreak(tick_t lengthInTicks);
    static SequenceTrack waterBass(tick_t lengthInTicks);
    static SequenceTrack waterChorus(tick_t lengthInTicks);
    static SequenceTrack waterXmas(tick_t lengthInTicks);
};

#pragma once

#include "SequenceTrack.h"

class SequenceTrackFactory
{
public:
    static SequenceTrack kickFour(tick_t lengthInTicks, tick_t startInTicks);
    static SequenceTrack clapFour(tick_t lengthInTicks, tick_t startInTicks);
};

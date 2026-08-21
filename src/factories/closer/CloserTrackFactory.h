#pragma once

#include "SequenceTrack.h"

class CloserTrackFactory
{
public:
 static SequenceTrack closerArp(tick_t lengthInTicks, tick_t startInTicks);

};

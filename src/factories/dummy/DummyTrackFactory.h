#pragma once

#include "SequenceTrack.h"

class DummyTrackFactory
{
public:
 static SequenceTrack dummyArp(tick_t lengthInTicks, tick_t startInTicks);

};

#pragma once

#include "SequenceTrack.h"

class SequenceTrackFactory
{
public:
    static SequenceTrack kickFour(tick_t lengthInTicks, tick_t startInTicks);
    static SequenceTrack clapFour(tick_t lengthInTicks, tick_t startInTicks);
    static SequenceTrack snareFour(tick_t lengthInTicks, tick_t startInTicks);
    static SequenceTrack rideOff(tick_t lengthInTicks, tick_t startInTicks);

    static SequenceTrack gtrPedal(tick_t lengthInTicks, tick_t startInTicks);
};

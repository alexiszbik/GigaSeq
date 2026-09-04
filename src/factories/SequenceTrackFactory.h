#pragma once

#include "SequenceTrack.h"

class SequenceTrackFactory
{
public:
    static SequenceTrack sampler(tick_t lengthInTicks, tick_t startInTicks);

    static SequenceTrack kickFour(tick_t lengthInTicks, tick_t startInTicks);
    static SequenceTrack clapFour(tick_t lengthInTicks, tick_t startInTicks);
    static SequenceTrack snareFour(tick_t lengthInTicks, tick_t startInTicks);
    static SequenceTrack rideOff(tick_t lengthInTicks, tick_t startInTicks);

    static SequenceTrack gtrPedal(tick_t lengthInTicks, tick_t startInTicks);

    static SequenceTrack gtrLoop(tick_t lengthInTicks, tick_t startInTicks);
    static SequenceTrack gtrLoopMute(tick_t lengthInTicks, tick_t startInTicks);
    static SequenceTrack gtrLoopUnmute(tick_t lengthInTicks, tick_t startInTicks);
    static SequenceTrack gtrLoopErase(tick_t lengthInTicks, tick_t startInTicks);

    static SequenceTrack polySynth(tick_t lengthInTicks, tick_t startInTicks);
    static SequenceTrack bass(tick_t lengthInTicks, tick_t startInTicks);
    static SequenceTrack vocoder(tick_t lengthInTicks, tick_t startInTicks);
    static SequenceTrack microfreak(tick_t lengthInTicks, tick_t startInTicks);

    static SequenceTrack midiLoop(tick_t lengthInTicks, tick_t startInTicks);

    static SequenceTrack modularA(tick_t lengthInTicks, tick_t startInTicks);
    static SequenceTrack drumMachine(tick_t lengthInTicks, tick_t startInTicks);

    static SequenceTrack matrix(tick_t lengthInTicks, tick_t startInTicks);

    static SequenceTrack ledStrips(tick_t lengthInTicks, tick_t startInTicks);
    static SequenceTrack ledStripsTest(tick_t lengthInTicks, tick_t startInTicks);
};

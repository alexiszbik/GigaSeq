#pragma once

#include "SequenceTrack.h"

class FallingTrackFactory
{
public:
    static SequenceTrack fallingHats(tick_t lengthInTicks, tick_t startInTicks);
    static SequenceTrack fallingPads(tick_t lengthInTicks, tick_t startInTicks);
    static SequenceTrack fallingKick(tick_t lengthInTicks, tick_t startInTicks);
    static SequenceTrack fallingRiser(tick_t lengthInTicks, tick_t startInTicks);
    static SequenceTrack fallingBass(tick_t lengthInTicks, tick_t startInTicks);
    static SequenceTrack fallingBigClap(tick_t lengthInTicks, tick_t startInTicks);
    static SequenceTrack fallingHarp(tick_t lengthInTicks, tick_t startInTicks);
    static SequenceTrack fallingTambourin(tick_t lengthInTicks, tick_t startInTicks);
    static SequenceTrack fallingPreInterlude(tick_t lengthInTicks, tick_t startInTicks);
};

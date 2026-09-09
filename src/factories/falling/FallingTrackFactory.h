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
    static SequenceTrack fallingInterlude(tick_t lengthInTicks, tick_t startInTicks);
    static SequenceTrack fallingSnareFill(tick_t lengthInTicks, tick_t startInTicks);
    static SequenceTrack fallingHandTamb(tick_t lengthInTicks, tick_t startInTicks);
    static SequenceTrack fallingKickFill(tick_t lengthInTicks, tick_t startInTicks);
    static SequenceTrack fallingPiano(tick_t lengthInTicks, tick_t startInTicks);
    static SequenceTrack fallingRimTom(tick_t lengthInTicks, tick_t startInTicks);
    static SequenceTrack fallingSynthEnd(tick_t lengthInTicks, tick_t startInTicks);
};

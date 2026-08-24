#pragma once

#include "SequenceTrack.h"

class UandiTrackFactory
{
public:
    static SequenceTrack uandiWavetableA(tick_t lengthInTicks, tick_t startInTicks);
    static SequenceTrack uandiWavetableB(tick_t lengthInTicks, tick_t startInTicks);
    static SequenceTrack uandiHatLoop(tick_t lengthInTicks, tick_t startInTicks);
    static SequenceTrack uandiWant(tick_t lengthInTicks, tick_t startInTicks);
    static SequenceTrack uandiBassA(tick_t lengthInTicks, tick_t startInTicks);
    static SequenceTrack uandiBassB(tick_t lengthInTicks, tick_t startInTicks);
    static SequenceTrack uandiFreak(tick_t lengthInTicks, tick_t startInTicks);
    static SequenceTrack uandiRiser(tick_t lengthInTicks, tick_t startInTicks);
};

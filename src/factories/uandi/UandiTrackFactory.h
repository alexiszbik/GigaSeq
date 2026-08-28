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
    static SequenceTrack uandiDiscoAB(tick_t lengthInTicks, tick_t startInTicks);
    static SequenceTrack uandiDiscoB(tick_t lengthInTicks, tick_t startInTicks);
    static SequenceTrack uandiBassAB(tick_t lengthInTicks, tick_t startInTicks);
    static SequenceTrack uandiWavetableAB(tick_t lengthInTicks, tick_t startInTicks);
    static SequenceTrack uandiOpenHat(tick_t lengthInTicks, tick_t startInTicks);
    static SequenceTrack uandiShaker(tick_t lengthInTicks, tick_t startInTicks);
    static SequenceTrack uandiTomEvent(tick_t lengthInTicks, tick_t startInTicks);
    static SequenceTrack uandiPiano(tick_t lengthInTicks, tick_t startInTicks);
    static SequenceTrack uandiRiserCrash(tick_t lengthInTicks, tick_t startInTicks);
    static SequenceTrack uandiRimFill(tick_t lengthInTicks, tick_t startInTicks);
    static SequenceTrack uandiExplode(tick_t lengthInTicks, tick_t startInTicks);
    static SequenceTrack uandiSweep(tick_t lengthInTicks, tick_t startInTicks);
};

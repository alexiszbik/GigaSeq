#pragma once

#include "SequenceTrack.h"

class WaterTrackFactory
{
public:
    static SequenceTrack waterHats(tick_t lengthInTicks, tick_t startInTicks);
    static SequenceTrack waterMarimba(tick_t lengthInTicks, tick_t startInTicks);

    static SequenceTrack waterFreak(tick_t lengthInTicks, tick_t startInTicks);
    static SequenceTrack waterBass(tick_t lengthInTicks, tick_t startInTicks);
    static SequenceTrack waterChorus(tick_t lengthInTicks, tick_t startInTicks);
    static SequenceTrack waterXmas(tick_t lengthInTicks, tick_t startInTicks);
    static SequenceTrack waterCongas(tick_t lengthInTicks, tick_t startInTicks);
    static SequenceTrack waterClaves(tick_t lengthInTicks, tick_t startInTicks);
    static SequenceTrack waterFm(tick_t lengthInTicks, tick_t startInTicks);
    static SequenceTrack waterBalafon(tick_t lengthInTicks, tick_t startInTicks);
    static SequenceTrack waterShakes(tick_t lengthInTicks, tick_t startInTicks);
    static SequenceTrack waterFmbass(tick_t lengthInTicks, tick_t startInTicks);
    static SequenceTrack waterKickPreChorus(tick_t lengthInTicks, tick_t startInTicks);
    static SequenceTrack waterChorus2(tick_t lengthInTicks, tick_t startInTicks);
    static SequenceTrack waterChorusFMBass(tick_t lengthInTicks, tick_t startInTicks);
    static SequenceTrack waterKickPartB(tick_t lengthInTicks, tick_t startInTicks);
    static SequenceTrack waterEventsPartB(tick_t lengthInTicks, tick_t startInTicks);
    static SequenceTrack waterFreakChorusB(tick_t lengthInTicks, tick_t startInTicks);
    static SequenceTrack waterKickPartC(tick_t lengthInTicks, tick_t startInTicks);
    static SequenceTrack waterEventsPartC(tick_t lengthInTicks, tick_t startInTicks);
    static SequenceTrack waterEventsEnd(tick_t lengthInTicks, tick_t startInTicks);
    static SequenceTrack waterChorusEnd(tick_t lengthInTicks, tick_t startInTicks);
};

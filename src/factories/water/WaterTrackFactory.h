#pragma once

#include "SequenceTrack.h"

class WaterTrackFactory
{
public:
    static SequenceTrack waterHats(tick_t lengthInTicks);
    static SequenceTrack waterMarimba(tick_t lengthInTicks);

    static SequenceTrack waterFreak(tick_t lengthInTicks);
    static SequenceTrack waterBass(tick_t lengthInTicks);
    static SequenceTrack waterChorus(tick_t lengthInTicks);
    static SequenceTrack waterXmas(tick_t lengthInTicks);
    static SequenceTrack waterCongas(tick_t lengthInTicks);
    static SequenceTrack waterClaves(tick_t lengthInTicks);
    static SequenceTrack waterFm(tick_t lengthInTicks);
    static SequenceTrack waterBalafon(tick_t lengthInTicks);
    static SequenceTrack waterShakes(tick_t lengthInTicks);
    static SequenceTrack waterFmbass(tick_t lengthInTicks);
    static SequenceTrack waterKickPreChorus(tick_t lengthInTicks);
};

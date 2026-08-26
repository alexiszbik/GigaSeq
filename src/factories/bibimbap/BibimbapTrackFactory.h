#pragma once

#include "SequenceTrack.h"

class BibimbapTrackFactory
{
public:
 static SequenceTrack bibimbapArp(tick_t lengthInTicks, tick_t startInTicks);

    static SequenceTrack bibimbapKickHi(tick_t lengthInTicks, tick_t startInTicks);
    static SequenceTrack bibimbapTom(tick_t lengthInTicks, tick_t startInTicks);
    static SequenceTrack bibimbapTomB(tick_t lengthInTicks, tick_t startInTicks);
    static SequenceTrack bibimbapShaker(tick_t lengthInTicks, tick_t startInTicks);
    static SequenceTrack bibimbapVocals(tick_t lengthInTicks, tick_t startInTicks);
    static SequenceTrack bibimbapMarimbaVerb(tick_t lengthInTicks, tick_t startInTicks);
    static SequenceTrack bibimbapRim(tick_t lengthInTicks, tick_t startInTicks);
    static SequenceTrack bibimbapPercs(tick_t lengthInTicks, tick_t startInTicks);
    static SequenceTrack bibimbapPercsB(tick_t lengthInTicks, tick_t startInTicks);
    static SequenceTrack bibimbapDizee(tick_t lengthInTicks, tick_t startInTicks);
    static SequenceTrack bibimbapDizee4bars(tick_t lengthInTicks, tick_t startInTicks);
    static SequenceTrack bibimbapXyloLoop(tick_t lengthInTicks, tick_t startInTicks);
    static SequenceTrack bibimbapBass(tick_t lengthInTicks, tick_t startInTicks);
    static SequenceTrack bibimbapHats(tick_t lengthInTicks, tick_t startInTicks);
    static SequenceTrack bibimbapRiser(tick_t lengthInTicks, tick_t startInTicks);
    static SequenceTrack bibimbapSnareRoll(tick_t lengthInTicks, tick_t startInTicks);
};

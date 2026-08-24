#pragma once

#include "SequenceTrack.h"

class TiredTrackFactory
{
public:
    static SequenceTrack tiredIntro(tick_t lengthInTicks, tick_t startInTicks);
    static SequenceTrack tiredHatSolo(tick_t lengthInTicks, tick_t startInTicks);
    static SequenceTrack tiredCongas(tick_t lengthInTicks, tick_t startInTicks);
    static SequenceTrack tiredRoboto(tick_t lengthInTicks, tick_t startInTicks);
    static SequenceTrack tiredHats(tick_t lengthInTicks, tick_t startInTicks);
    static SequenceTrack tiredSync(tick_t lengthInTicks, tick_t startInTicks);
    static SequenceTrack tiredPhazeHat(tick_t lengthInTicks, tick_t startInTicks);
    static SequenceTrack tiredUpRising(tick_t lengthInTicks, tick_t startInTicks);
    static SequenceTrack tiredRiserA(tick_t lengthInTicks, tick_t startInTicks);
};

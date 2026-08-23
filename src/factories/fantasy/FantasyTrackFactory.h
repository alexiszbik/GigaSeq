#pragma once

#include "SequenceTrack.h"

class FantasyTrackFactory
{
public:
    static SequenceTrack fantasyArp(tick_t lengthInTicks, tick_t startInTicks);
    static SequenceTrack fantasySnare909(tick_t lengthInTicks, tick_t startInTicks);
    static SequenceTrack fantasySample(tick_t lengthInTicks, tick_t startInTicks);
    static SequenceTrack fantasyDrums(tick_t lengthInTicks, tick_t startInTicks);
    static SequenceTrack fantasyShake(tick_t lengthInTicks, tick_t startInTicks);
    static SequenceTrack fantasyChords(tick_t lengthInTicks, tick_t startInTicks);
    static SequenceTrack fantasyHiDrum(tick_t lengthInTicks, tick_t startInTicks);
    static SequenceTrack fantasyFreak(tick_t lengthInTicks, tick_t startInTicks);
    static SequenceTrack fantasyVocals(tick_t lengthInTicks, tick_t startInTicks);
    static SequenceTrack fantasySampleFadeCut(tick_t lengthInTicks, tick_t startInTicks);
    static SequenceTrack fantasyRiser(tick_t lengthInTicks, tick_t startInTicks);
};

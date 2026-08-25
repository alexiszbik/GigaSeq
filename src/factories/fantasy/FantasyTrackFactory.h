#pragma once

#include "SequenceTrack.h"

class FantasyTrackFactory
{
public:
    static SequenceTrack fantasyArp(tick_t lengthInTicks, tick_t startInTicks);
    static SequenceTrack fantasySnare909(tick_t lengthInTicks, tick_t startInTicks);

    static SequenceTrack fantasySampleIntro(tick_t lengthInTicks, tick_t startInTicks);
    static SequenceTrack fantasySampleSidekick(tick_t lengthInTicks, tick_t startInTicks);
    static SequenceTrack fantasySampleFilterB(tick_t lengthInTicks, tick_t startInTicks);


    static SequenceTrack fantasyDrums(tick_t lengthInTicks, tick_t startInTicks);
    static SequenceTrack fantasyShake(tick_t lengthInTicks, tick_t startInTicks);
    static SequenceTrack fantasyChords(tick_t lengthInTicks, tick_t startInTicks);
    static SequenceTrack fantasyHiDrum(tick_t lengthInTicks, tick_t startInTicks);
    static SequenceTrack fantasyFreak(tick_t lengthInTicks, tick_t startInTicks);
    static SequenceTrack fantasyVocals(tick_t lengthInTicks, tick_t startInTicks);
    static SequenceTrack fantasySampleFadeCut(tick_t lengthInTicks, tick_t startInTicks);
    static SequenceTrack fantasyRiser(tick_t lengthInTicks, tick_t startInTicks);
    static SequenceTrack fantasyChordOffset(tick_t lengthInTicks, tick_t startInTicks);
    static SequenceTrack fantasyArpPoly(tick_t lengthInTicks, tick_t startInTicks);
    static SequenceTrack fantasyArpBass(tick_t lengthInTicks, tick_t startInTicks);
    static SequenceTrack fantasyBigRiz1(tick_t lengthInTicks, tick_t startInTicks);
    static SequenceTrack fantasyBigClap(tick_t lengthInTicks, tick_t startInTicks);
    static SequenceTrack fantasyShakeEnd(tick_t lengthInTicks, tick_t startInTicks);
    static SequenceTrack fantasyBigRiz2(tick_t lengthInTicks, tick_t startInTicks);
};

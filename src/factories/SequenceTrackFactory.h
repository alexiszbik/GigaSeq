#pragma once

#include "SequenceTrack.h"

class SequenceTrackFactory
{
public:
    static SequenceTrack kickFour(tick_t lengthInTicks, tick_t startInTicks);
    static SequenceTrack snareFour(tick_t lengthInTicks, tick_t startInTicks);


    static SequenceTrack createCMaj7Arpeggio(tick_t lengthInTicks, tick_t startInTicks);
    static SequenceTrack createAm7Arpeggio(tick_t lengthInTicks, tick_t startInTicks);
    static SequenceTrack createKickSnare(tick_t lengthInTicks, tick_t startInTicks);
    static SequenceTrack createKickSnareWithHats(tick_t lengthInTicks, tick_t startInTicks);
    static SequenceTrack createBassLine(tick_t lengthInTicks, tick_t startInTicks);
    static SequenceTrack createMelodicBass(tick_t lengthInTicks, tick_t startInTicks);
    static SequenceTrack createHiHatPattern(tick_t lengthInTicks, tick_t startInTicks);
    static SequenceTrack createSnareBackbeat(tick_t lengthInTicks, tick_t startInTicks);
    static SequenceTrack createPadChords(tick_t lengthInTicks, tick_t startInTicks);
    static SequenceTrack createSynthStabs(tick_t lengthInTicks, tick_t startInTicks);
    static SequenceTrack createClapBackbeat(tick_t lengthInTicks, tick_t startInTicks);

    // Additional tracks for limit testing
    static SequenceTrack createOpenHat(tick_t lengthInTicks, tick_t startInTicks);
    static SequenceTrack createTomFill(tick_t lengthInTicks, tick_t startInTicks);
    static SequenceTrack createRimshot(tick_t lengthInTicks, tick_t startInTicks);
    static SequenceTrack createCymbalRide(tick_t lengthInTicks, tick_t startInTicks);
    static SequenceTrack createTambourine(tick_t lengthInTicks, tick_t startInTicks);
    static SequenceTrack createShaker(tick_t lengthInTicks, tick_t startInTicks);
    static SequenceTrack createClave(tick_t lengthInTicks, tick_t startInTicks);
    static SequenceTrack createCowbell(tick_t lengthInTicks, tick_t startInTicks);
    static SequenceTrack createChordStab(tick_t lengthInTicks, tick_t startInTicks);
    static SequenceTrack createPluck(tick_t lengthInTicks, tick_t startInTicks);
    static SequenceTrack createLead(tick_t lengthInTicks, tick_t startInTicks);
    static SequenceTrack createSubBass(tick_t lengthInTicks, tick_t startInTicks);
    static SequenceTrack createPadSwells(tick_t lengthInTicks, tick_t startInTicks);
    static SequenceTrack createFxBleep(tick_t lengthInTicks, tick_t startInTicks);
    static SequenceTrack createArpFast(tick_t lengthInTicks, tick_t startInTicks);
    static SequenceTrack createGtrChug(tick_t lengthInTicks, tick_t startInTicks);
};

#pragma once

#include "SequenceTrack.h"

class SequenceTrackFactory
{
public:
    static SequenceTrack togetherArp(tick_t lengthInTicks);
    static SequenceTrack togetherHiDrum(tick_t lengthInTicks);
    static SequenceTrack togetherSample(tick_t lengthInTicks);
    static SequenceTrack togetherDX7(tick_t lengthInTicks);
    static SequenceTrack togetherVocoder(tick_t lengthInTicks);

    static SequenceTrack togetherVocoderPartSample(tick_t lengthInTicks);
    static SequenceTrack togetherVocoderPartKick(tick_t lengthInTicks);
    static SequenceTrack togetherVocoderPartHiDrum(tick_t lengthInTicks);
    static SequenceTrack togetherVocoderPartArp(tick_t lengthInTicks);
    static SequenceTrack togetherVocoderPartDX7(tick_t lengthInTicks);
    static SequenceTrack togetherVocoderPartExtraBass(tick_t lengthInTicks);
    static SequenceTrack togetherEndRiser(tick_t lengthInTicks);

    static SequenceTrack togetherPartBSampleCut(tick_t lengthInTicks);
    static SequenceTrack togetherPartBSynth(tick_t lengthInTicks);
    static SequenceTrack togetherPartBAh(tick_t lengthInTicks);
    static SequenceTrack togetherPartBDaDaDa(tick_t lengthInTicks);
    static SequenceTrack togetherPartBHat(tick_t lengthInTicks);

    static SequenceTrack togetherPartBJC(tick_t lengthInTicks);
    static SequenceTrack togetherPartBTambourin(tick_t lengthInTicks);
    static SequenceTrack togetherPartBCymbal(tick_t lengthInTicks);
    static SequenceTrack togetherPartBEndRiser(tick_t lengthInTicks);

    static SequenceTrack createCMaj7Arpeggio(tick_t lengthInTicks);
    static SequenceTrack createAm7Arpeggio(tick_t lengthInTicks);
    static SequenceTrack createKickSnare(tick_t lengthInTicks);
    static SequenceTrack createKickSnareWithHats(tick_t lengthInTicks);
    static SequenceTrack createBassLine(tick_t lengthInTicks);
    static SequenceTrack createMelodicBass(tick_t lengthInTicks);
    static SequenceTrack createHiHatPattern(tick_t lengthInTicks);
    static SequenceTrack kickFour(tick_t lengthInTicks);
    static SequenceTrack createSnareBackbeat(tick_t lengthInTicks);
    static SequenceTrack createPadChords(tick_t lengthInTicks);
    static SequenceTrack createSynthStabs(tick_t lengthInTicks);
    static SequenceTrack createClapBackbeat(tick_t lengthInTicks);

    // Additional tracks for limit testing
    static SequenceTrack createOpenHat(tick_t lengthInTicks);
    static SequenceTrack createTomFill(tick_t lengthInTicks);
    static SequenceTrack createRimshot(tick_t lengthInTicks);
    static SequenceTrack createCymbalRide(tick_t lengthInTicks);
    static SequenceTrack createTambourine(tick_t lengthInTicks);
    static SequenceTrack createShaker(tick_t lengthInTicks);
    static SequenceTrack createClave(tick_t lengthInTicks);
    static SequenceTrack createCowbell(tick_t lengthInTicks);
    static SequenceTrack createChordStab(tick_t lengthInTicks);
    static SequenceTrack createPluck(tick_t lengthInTicks);
    static SequenceTrack createLead(tick_t lengthInTicks);
    static SequenceTrack createSubBass(tick_t lengthInTicks);
    static SequenceTrack createPadSwells(tick_t lengthInTicks);
    static SequenceTrack createFxBleep(tick_t lengthInTicks);
    static SequenceTrack createArpFast(tick_t lengthInTicks);
    static SequenceTrack createGtrChug(tick_t lengthInTicks);
};

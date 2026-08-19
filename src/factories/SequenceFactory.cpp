#include "SequenceFactory.h"

#include "SequenceBuilder.h"
#include "SequenceTrackFactory.h"

Sequence SequenceFactory::createSequenceOne()
{
    return buildSequence(
        2, 7, 1, "Kick/Hat12345", 120, true,
        {
            SequenceTrackFactory::createKickSnareWithHats,
            SequenceTrackFactory::createCMaj7Arpeggio,
            SequenceTrackFactory::kickFour,
            SequenceTrackFactory::createHiHatPattern,
            SequenceTrackFactory::createOpenHat,
            SequenceTrackFactory::createSnareBackbeat,
            SequenceTrackFactory::createClapBackbeat,
            SequenceTrackFactory::createBassLine,
            SequenceTrackFactory::createMelodicBass,
            SequenceTrackFactory::createSubBass,
            SequenceTrackFactory::createPadChords,
            SequenceTrackFactory::createPadSwells,
            SequenceTrackFactory::createSynthStabs,
            SequenceTrackFactory::createChordStab,
            SequenceTrackFactory::createPluck,
            SequenceTrackFactory::createLead,
        });
}

Sequence SequenceFactory::createSequenceTwo()
{
    return buildSequence(
        4, 4, 2, "F on Flour", 140, true,
        {
            SequenceTrackFactory::createCMaj7Arpeggio,
            SequenceTrackFactory::kickFour,
            SequenceTrackFactory::createKickSnare,
            SequenceTrackFactory::createKickSnareWithHats,
            SequenceTrackFactory::createHiHatPattern,
            SequenceTrackFactory::createOpenHat,
            SequenceTrackFactory::createCymbalRide,
            SequenceTrackFactory::createTambourine,
            SequenceTrackFactory::createShaker,
            SequenceTrackFactory::createRimshot,
            SequenceTrackFactory::createCowbell,
            SequenceTrackFactory::createBassLine,
            SequenceTrackFactory::createMelodicBass,
            SequenceTrackFactory::createSubBass,
            SequenceTrackFactory::createSynthStabs,
            SequenceTrackFactory::createArpFast,
        });
}

Sequence SequenceFactory::createSequenceThree()
{
    Sequence sequence = buildSequence(
        4, 4, 0, "Am7Hi-Hat", 165, true,
        {
            SequenceTrackFactory::createAm7Arpeggio,
            SequenceTrackFactory::createHiHatPattern,
            SequenceTrackFactory::kickFour,
            SequenceTrackFactory::createKickSnare,
            SequenceTrackFactory::createSnareBackbeat,
            SequenceTrackFactory::createClapBackbeat,
            SequenceTrackFactory::createOpenHat,
            SequenceTrackFactory::createCymbalRide,
            SequenceTrackFactory::createTambourine,
            SequenceTrackFactory::createShaker,
            SequenceTrackFactory::createClave,
            SequenceTrackFactory::createTomFill,
            SequenceTrackFactory::createMelodicBass,
            SequenceTrackFactory::createSubBass,
            SequenceTrackFactory::createPadChords,
            SequenceTrackFactory::createLead,
        });

    const tick_t bar2Tick = static_cast<tick_t>(1 * 4 * Sequence::kTicksPerQuarterNote);
    const tick_t bar4Tick = static_cast<tick_t>(3 * 4 * Sequence::kTicksPerQuarterNote);
    sequence.addTempoEvent(bar2Tick, 140);
    sequence.addTempoEvent(bar4Tick, 165);

    return sequence;
}

Sequence SequenceFactory::createSequenceFour()
{
    return buildSequence(
        4, 4, 0, "Pads", 90, true,
        {
            SequenceTrackFactory::createPadChords,
            SequenceTrackFactory::createKickSnare,
            SequenceTrackFactory::createPadSwells,
            SequenceTrackFactory::kickFour,
            SequenceTrackFactory::createHiHatPattern,
            SequenceTrackFactory::createSnareBackbeat,
            SequenceTrackFactory::createClapBackbeat,
            SequenceTrackFactory::createOpenHat,
            SequenceTrackFactory::createShaker,
            SequenceTrackFactory::createTambourine,
            SequenceTrackFactory::createBassLine,
            SequenceTrackFactory::createMelodicBass,
            SequenceTrackFactory::createSubBass,
            SequenceTrackFactory::createChordStab,
            SequenceTrackFactory::createSynthStabs,
            SequenceTrackFactory::createFxBleep,
        });
}

Sequence SequenceFactory::createSequenceFive()
{
    return buildSequence(
        4, 4, 1, "Melodic", 104, true,
        {
            SequenceTrackFactory::createMelodicBass,
            SequenceTrackFactory::createSnareBackbeat,
            SequenceTrackFactory::kickFour,
            SequenceTrackFactory::createHiHatPattern,
            SequenceTrackFactory::createOpenHat,
            SequenceTrackFactory::createClapBackbeat,
            SequenceTrackFactory::createCymbalRide,
            SequenceTrackFactory::createShaker,
            SequenceTrackFactory::createRimshot,
            SequenceTrackFactory::createClave,
            SequenceTrackFactory::createSubBass,
            SequenceTrackFactory::createLead,
            SequenceTrackFactory::createPluck,
            SequenceTrackFactory::createChordStab,
            SequenceTrackFactory::createPadChords,
            SequenceTrackFactory::createArpFast,
        });
}

Sequence SequenceFactory::createSequenceSix()
{
    return buildSequence(
        4, 4, 2, "Stabs", 115, true,
        {
            SequenceTrackFactory::createSynthStabs,
            SequenceTrackFactory::createKickSnareWithHats,
            SequenceTrackFactory::kickFour,
            SequenceTrackFactory::createHiHatPattern,
            SequenceTrackFactory::createSnareBackbeat,
            SequenceTrackFactory::createClapBackbeat,
            SequenceTrackFactory::createOpenHat,
            SequenceTrackFactory::createTambourine,
            SequenceTrackFactory::createShaker,
            SequenceTrackFactory::createCowbell,
            SequenceTrackFactory::createBassLine,
            SequenceTrackFactory::createMelodicBass,
            SequenceTrackFactory::createSubBass,
            SequenceTrackFactory::createChordStab,
            SequenceTrackFactory::createLead,
            SequenceTrackFactory::createGtrChug,
        });
}

Sequence SequenceFactory::createSequenceSeven()
{
    return buildSequence(
        2, 4, 0, "Clap", 155, true,
        {
            SequenceTrackFactory::createClapBackbeat,
            SequenceTrackFactory::createMelodicBass,
            SequenceTrackFactory::kickFour,
            SequenceTrackFactory::createKickSnare,
            SequenceTrackFactory::createHiHatPattern,
            SequenceTrackFactory::createOpenHat,
            SequenceTrackFactory::createCymbalRide,
            SequenceTrackFactory::createRimshot,
            SequenceTrackFactory::createTambourine,
            SequenceTrackFactory::createShaker,
            SequenceTrackFactory::createClave,
            SequenceTrackFactory::createTomFill,
            SequenceTrackFactory::createSubBass,
            SequenceTrackFactory::createPadChords,
            SequenceTrackFactory::createPadSwells,
            SequenceTrackFactory::createFxBleep,
        });
}

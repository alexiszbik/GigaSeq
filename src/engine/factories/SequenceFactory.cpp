#include "SequenceFactory.h"

#include "SequenceTrackFactory.h"

namespace
{
using TrackBuilder = SequenceTrack (*)(tick_t lengthInTicks);

Sequence buildSequence(
    int barCount,
    int beatsPerBar,
    int barLoop,
    const char* name,
    uint8_t tempo,
    std::vector<TrackBuilder> builders)
{
    Sequence sequence(name, tempo, barCount, beatsPerBar, barLoop);
    const tick_t length = sequence.lengthInTicks();

    for (auto& tb : builders) {
        sequence.addTrack(tb(length));
    }
    return sequence;
}
} // namespace

Sequence SequenceFactory::createSequenceOne(int barCount)
{
    return buildSequence(
        2, 7, 1, "Kick/Hat12345", 120,
        {
            SequenceTrackFactory::createKickSnareWithHats,
            SequenceTrackFactory::createCMaj7Arpeggio,
            SequenceTrackFactory::createFourOnFloorKick,
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

Sequence SequenceFactory::createSequenceTwo(int barCount)
{
    return buildSequence(
        barCount, 4, 2, "F on Flour", 140,
        {
            SequenceTrackFactory::createCMaj7Arpeggio,
            SequenceTrackFactory::createFourOnFloorKick,
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

Sequence SequenceFactory::createSequenceThree(int barCount)
{
    return buildSequence(
        barCount, 4, 0, "Am7Hi-Hat", 165,
        {
            SequenceTrackFactory::createAm7Arpeggio,
            SequenceTrackFactory::createHiHatPattern,
            SequenceTrackFactory::createFourOnFloorKick,
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
}

Sequence SequenceFactory::createSequenceFour(int barCount)
{
    return buildSequence(
        barCount, 4, 0, "Pads", 90,
        {
            SequenceTrackFactory::createPadChords,
            SequenceTrackFactory::createKickSnare,
            SequenceTrackFactory::createPadSwells,
            SequenceTrackFactory::createFourOnFloorKick,
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

Sequence SequenceFactory::createSequenceFive(int barCount)
{
    return buildSequence(
        barCount, 4, 1, "Melodic", 104,
        {
            SequenceTrackFactory::createMelodicBass,
            SequenceTrackFactory::createSnareBackbeat,
            SequenceTrackFactory::createFourOnFloorKick,
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

Sequence SequenceFactory::createSequenceSix(int barCount)
{
    return buildSequence(
        barCount, 4, 2, "Stabs", 115,
        {
            SequenceTrackFactory::createSynthStabs,
            SequenceTrackFactory::createKickSnareWithHats,
            SequenceTrackFactory::createFourOnFloorKick,
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

Sequence SequenceFactory::createSequenceSeven(int barCount)
{
    return buildSequence(
        barCount, 4, 0, "Clap", 155,
        {
            SequenceTrackFactory::createClapBackbeat,
            SequenceTrackFactory::createMelodicBass,
            SequenceTrackFactory::createFourOnFloorKick,
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

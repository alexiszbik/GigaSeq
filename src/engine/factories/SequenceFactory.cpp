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
    std::vector<TrackBuilder> builders)
{
    Sequence sequence(name, barCount, beatsPerBar, barLoop);
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
        2, 7, 1, "Kick/Hat12345",
        {
            SequenceTrackFactory::createKickSnareWithHats, 
            SequenceTrackFactory::createCMaj7Arpeggio
        });
}

Sequence SequenceFactory::createSequenceTwo(int barCount)
{
    return buildSequence(
        barCount, 4, 2, "F on Flour", 
        {
            SequenceTrackFactory::createCMaj7Arpeggio,
            SequenceTrackFactory::createFourOnFloorKick
        });
}

Sequence SequenceFactory::createSequenceThree(int barCount)
{
    return buildSequence(
        barCount, 4, 0, "Am7Hi-Hat",
        {
            SequenceTrackFactory::createAm7Arpeggio,
            SequenceTrackFactory::createHiHatPattern
        });
}

Sequence SequenceFactory::createSequenceFour(int barCount)
{
    return buildSequence(
        barCount, 4, 0, "Pads",
        {
            SequenceTrackFactory::createPadChords,
            SequenceTrackFactory::createKickSnare
        });
}

Sequence SequenceFactory::createSequenceFive(int barCount)
{
    return buildSequence(
        barCount, 4, 1, "Melodic",
        {
            SequenceTrackFactory::createMelodicBass,
            SequenceTrackFactory::createSnareBackbeat
        });
}

Sequence SequenceFactory::createSequenceSix(int barCount)
{
    return buildSequence(
        barCount, 4, 2, "Stabs",
        {
            SequenceTrackFactory::createSynthStabs,
            SequenceTrackFactory::createKickSnareWithHats
        });
}

Sequence SequenceFactory::createSequenceSeven(int barCount)
{
    return buildSequence(
        barCount, 4, 0, "Clap",
        {
            SequenceTrackFactory::createClapBackbeat,
            SequenceTrackFactory::createMelodicBass
        });
}

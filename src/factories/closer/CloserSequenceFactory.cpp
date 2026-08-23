#include "CloserSequenceFactory.h"

#include "factories/SequenceBuilder.h"
#include "factories/SequenceTrackFactory.h"
#include "factories/closer/CloserTrackFactory.h"
#include "MidiChannel.h"

namespace {
    constexpr uint8_t songTempo = 130;
}

Sequence CloserSequenceFactory::closerIntro()
{

    Sequence seq = buildSequence(
        8, 4, 0, "Intro", songTempo, true,
        {
            SequenceTrackFactory::kickFour,
            CloserTrackFactory::closerHats,
            CloserTrackFactory::closerLoopHat,
            CloserTrackFactory::closerTambourin,
            CloserTrackFactory::closerClapTom,
            CloserTrackFactory::closerModular,
            CloserTrackFactory::closerStab,
            CloserTrackFactory::closerFill808,
            CloserTrackFactory::closerRiser,
        });
    return seq;
}

Sequence CloserSequenceFactory::closerChords()
{
    Sequence seq = buildSequence(
        8, 4, 0, "Chords", songTempo, true,
        {
            CloserTrackFactory::closerChords,
            CloserTrackFactory::closerModular,
            CloserTrackFactory::closerTambourin,
        });
    return seq;
}

Sequence CloserSequenceFactory::closerBass()
{
    Sequence seq = buildSequence(
        8, 4, 0, "Bass", songTempo, true,
        {
            CloserTrackFactory::closerChords,
            CloserTrackFactory::closerModular,
            CloserTrackFactory::closerTambourin,
            SequenceTrackFactory::clapFour,
            SequenceTrackFactory::kickFour,
            CloserTrackFactory::closerSing,
            CloserTrackFactory::closerTop,
        });
    return seq;
}

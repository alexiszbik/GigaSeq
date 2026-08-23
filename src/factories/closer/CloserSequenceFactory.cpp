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
        });
    return seq;
}

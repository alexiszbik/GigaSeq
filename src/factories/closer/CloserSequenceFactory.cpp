#include "CloserSequenceFactory.h"

#include "factories/SequenceBuilder.h"
#include "factories/SequenceTrackFactory.h"
#include "factories/closer/CloserTrackFactory.h"
#include "MidiChannel.h"

Sequence CloserSequenceFactory::closerIntro()
{
    Sequence seq = buildSequence(
        8, 4, 0, "Intro", 130, true,
        {
            SequenceTrackFactory::kickFour,
            CloserTrackFactory::closerArp,
        });
    return seq;
}

#include "DummySequenceFactory.h"

#include "factories/SequenceBuilder.h"
#include "factories/SequenceTrackFactory.h"
#include "factories/dummy/DummyTrackFactory.h"
#include "MidiChannel.h"

Sequence DummySequenceFactory::dummyIntro()
{
    Sequence seq = buildSequence(
        8, 4, 0, "Intro", 130, true,
        {
            SequenceTrackFactory::kickFour,
            DummyTrackFactory::dummyArp,
        });
    return seq;
}

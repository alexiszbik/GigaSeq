#include "DummySequenceFactory.h"

#include "factories/SequenceBuilder.h"
#include "factories/SequenceTrackFactory.h"
#include "factories/dummy/DummyTrackFactory.h"
#include "MidiConst.h"

namespace {
constexpr uint8_t songTempo = 130;
}


Sequence DummySequenceFactory::dummyIntro()
{
    Sequence seq = buildSequence(
        8, 4, 0, "Intro", songTempo, true,
        {
            SequenceTrackFactory::kickFour,
            DummyTrackFactory::dummyArp,
        });
    return seq;
}

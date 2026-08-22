#include "FallingSequenceFactory.h"

#include "factories/SequenceBuilder.h"
#include "factories/SequenceTrackFactory.h"
#include "factories/falling/FallingTrackFactory.h"
#include "MidiChannel.h"

namespace {
    constexpr uint8_t songTempo = 125;
}

Sequence FallingSequenceFactory::fallingIntro()
{
    Sequence seq = buildSequence(
        8, 4, 0, "Intro", songTempo, true,
        {
            FallingTrackFactory::fallingHats,
        });
    return seq;
}

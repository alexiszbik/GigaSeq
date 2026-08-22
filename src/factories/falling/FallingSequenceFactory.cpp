#include "FallingSequenceFactory.h"

#include "factories/SequenceBuilder.h"
#include "factories/SequenceTrackFactory.h"
#include "factories/falling/FallingTrackFactory.h"
#include "MidiChannel.h"

namespace {
    constexpr uint8_t songTempo = 125;

    constexpr tick_t oneBarTick = 384;
}

Sequence FallingSequenceFactory::fallingIntro()
{
    Sequence seq = buildSequence(
        8, 4, 0, "Intro", songTempo, true,
        {
            FallingTrackFactory::fallingHats,
            FallingTrackFactory::fallingPads,
            FallingTrackFactory::fallingKick,
        });
    return seq;
}

Sequence FallingSequenceFactory::fallingIntro2()
{
    Sequence seq = buildSequence(
        8, 4, 0, "Intro2", songTempo, false,
        {
            FallingTrackFactory::fallingHats,
            FallingTrackFactory::fallingPads,
            track(FallingTrackFactory::fallingKick).withLength(7*oneBarTick),
            track(FallingTrackFactory::fallingRiser).withLength(8*oneBarTick)
        });
    return seq;
}

Sequence FallingSequenceFactory::fallingBassSeq()
{
    Sequence seq = buildSequence(
        8, 4, 0, "BassSeq", songTempo, true,
        {
            FallingTrackFactory::fallingKick,
            FallingTrackFactory::fallingBass,
            FallingTrackFactory::fallingPads.withStart(16*oneBarTick),
        });
    return seq;
}

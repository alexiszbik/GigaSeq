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
            track(FallingTrackFactory::fallingRiser).withLength(4*oneBarTick),
        });
    return seq;
}

Sequence FallingSequenceFactory::fallingBassSeq()
{
    tick_t len1 = 8*oneBarTick;
    tick_t len2 = 12*oneBarTick;
    tick_t len3 = 16*oneBarTick;

    Sequence seq = buildSequence(
        20, 4, 16, "BassSeq", songTempo, true,
        {
            FallingTrackFactory::fallingKick,
            track(FallingTrackFactory::fallingBigClap).withStart(len2),
            track(SequenceTrackFactory::snareFour).startMuted(),
            track(FallingTrackFactory::fallingHats).withStart(len1),
            FallingTrackFactory::fallingBass,
            track(FallingTrackFactory::fallingPads).withStart(len1), //add automation !!!
            track(FallingTrackFactory::fallingRiser).withStart(len3),
            track(FallingTrackFactory::fallingHarp).startMuted(),
        });

    seq.track(1).addMuteEvent(len3);
    return seq;
}

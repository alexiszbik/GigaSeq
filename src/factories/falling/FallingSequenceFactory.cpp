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
            FallingTrackFactory::fallingRiser,
        });
    return seq;
}

Sequence FallingSequenceFactory::fallingBassSeq()
{
    tick_t len1 = 8*oneBarTick;
    uint8_t loopPoint = 16;
    tick_t len3 = loopPoint*oneBarTick;

    Sequence seq = buildSequence(
        24, 4, loopPoint, "BassSeq", songTempo, true,
        {
            FallingTrackFactory::fallingKick,
            track(FallingTrackFactory::fallingBigClap).withStart(len1).muted().withMuteEvent(len3),
            track(SequenceTrackFactory::clapFour).muted(),
            track(FallingTrackFactory::fallingHats).withStart(len1),
            FallingTrackFactory::fallingBass,
            track(FallingTrackFactory::fallingPads).withStart(len1), //add automation !!!
            track(FallingTrackFactory::fallingRiser).withMuteEvent(len3).asFill(),
            track(FallingTrackFactory::fallingHarp).muted(),
            track(FallingTrackFactory::fallingTambourin).muted(),
        });

    return seq;
}

Sequence FallingSequenceFactory::fallingPreInterlude()
{
    tick_t length = oneBarTick*7 + 2*96 + 24;

    Sequence seq = buildSequence(
        8, 4, 0, "PreInterlude", songTempo, false,
        {
            track(FallingTrackFactory::fallingKick).withLength(length),
            track(FallingTrackFactory::fallingBass).withLength(length),
            FallingTrackFactory::fallingPreInterlude,
        });
    return seq;
}

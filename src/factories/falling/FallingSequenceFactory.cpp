#include "FallingSequenceFactory.h"

#include "factories/SequenceBuilder.h"
#include "factories/SequenceTrackFactory.h"
#include "factories/falling/FallingTrackFactory.h"
#include "MidiChannel.h"
#include "TickHelper.h"

namespace {
    constexpr uint8_t songTempo = 125;
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
            track(FallingTrackFactory::fallingKick).withLength(TickHelper::bars(7)),
            FallingTrackFactory::fallingRiser,
        });
    return seq;
}

Sequence FallingSequenceFactory::fallingBassSeq()
{
    tick_t len1 = TickHelper::bars(8);
    uint8_t loopPoint = 16;
    tick_t len3 = TickHelper::bars(loopPoint);

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
    tick_t length = TICK(7, 2, 1);

    Sequence seq = buildSequence(
        10 /* 8 bars + 2 bars pause */, 4, 0, "PreInterlude", songTempo, false,
        {
            track(FallingTrackFactory::fallingKick).withLength(length),
            track(FallingTrackFactory::fallingBass).withLength(length),
            FallingTrackFactory::fallingPreInterlude,
        });
    return seq;
}

Sequence FallingSequenceFactory::fallingInterlude()
{
    tick_t len1 = TickHelper::bars(8);

    Sequence seq = buildSequence(
        24, 4, 0, "Interlude", songTempo, false,
        {
            FallingTrackFactory::fallingInterlude,
            track(FallingTrackFactory::fallingHats).withStart(len1),
            track(FallingTrackFactory::fallingHandTamb).withStart(len1),
            FallingTrackFactory::fallingRiser,
            FallingTrackFactory::fallingSnareFill,
            FallingTrackFactory::fallingKickFill,
        });
    return seq;
}

Sequence FallingSequenceFactory::fallingPreClimax()
{
    Sequence seq = buildSequence(
        16, 4, 0, "PreClimax", songTempo, false,
        {
            track(FallingTrackFactory::fallingKick).withLength(TICK(15,0,0)),
            SequenceTrackFactory::clapFour,
            FallingTrackFactory::fallingHats,
            FallingTrackFactory::fallingBass,
            FallingTrackFactory::fallingHandTamb,
            FallingTrackFactory::fallingPads,
            FallingTrackFactory::fallingPiano,
            FallingTrackFactory::fallingRiser,
            FallingTrackFactory::fallingSnareFill,
        });
    return seq;
}

Sequence FallingSequenceFactory::fallingClimax()
{
    Sequence seq = buildSequence(
        8, 4, 0, "Climax", songTempo, true,
        {
            SequenceTrackFactory::kickFour,
            SequenceTrackFactory::clapFour,
            FallingTrackFactory::fallingHats,
            FallingTrackFactory::fallingBass,
            FallingTrackFactory::fallingHandTamb,
            FallingTrackFactory::fallingPads,
            FallingTrackFactory::fallingPiano,
            SequenceTrackFactory::rideOff,
            track(FallingTrackFactory::fallingRiser).withMuteEvent(0).asFill(),
        });
    return seq;
}

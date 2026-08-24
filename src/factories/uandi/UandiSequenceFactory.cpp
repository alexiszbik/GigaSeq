#include "UandiSequenceFactory.h"

#include "factories/SequenceBuilder.h"
#include "factories/SequenceTrackFactory.h"
#include "factories/uandi/UandiTrackFactory.h"
#include "MidiConst.h"

namespace {
constexpr uint8_t songTempo = 140;
}

Sequence UandiSequenceFactory::uandiIntro()
{
    Sequence seq = buildSequence(
        8, 4, 0, "Intro", songTempo, true,
        {
            SequenceTrackFactory::kickFour,
            UandiTrackFactory::uandiWavetableA,
            track(UandiTrackFactory::uandiHatLoop).muted(),
            track(UandiTrackFactory::uandiWant).muted().withMuteEvent(0),
            track(UandiTrackFactory::uandiBassA).muted(),
            track(UandiTrackFactory::uandiFreak).muted(),
            track(UandiTrackFactory::uandiRiser).muted().withMuteEvent(0)
        });
    return seq;
}

Sequence UandiSequenceFactory::uandiIntroB()
{
    Sequence seq = buildSequence(
        4, 4, 0, "IntroB", songTempo, true,
        {
            UandiTrackFactory::uandiWavetableB,
            UandiTrackFactory::uandiBassB,
            UandiTrackFactory::uandiFreak,
            UandiTrackFactory::uandiDiscoB,
            track(UandiTrackFactory::uandiRiser).muted().withMuteEvent(0).asFill(),
        });
    return seq;
}

Sequence UandiSequenceFactory::uandiMain()
{
    Sequence seq = buildSequence(
        12, 4, 0, "Main", songTempo, true,
        {
            SequenceTrackFactory::kickFour,
            SequenceTrackFactory::snareFour,
            UandiTrackFactory::uandiWavetableAB,
            UandiTrackFactory::uandiHatLoop,
            UandiTrackFactory::uandiBassAB,
            UandiTrackFactory::uandiFreak,
            UandiTrackFactory::uandiDiscoAB,
            UandiTrackFactory::uandiOpenHat,
            UandiTrackFactory::uandiRiser,
        });
    return seq;
}

Sequence UandiSequenceFactory::uandiBreak()
{
    tick_t loopPoint = TICK(8);

    Sequence seq = buildSequence(
        12, 4, 8, "Break", songTempo, true,
        {
            track(SequenceTrackFactory::kickFour).withLength(loopPoint),
            track(SequenceTrackFactory::snareFour).withLength(loopPoint),
            track(UandiTrackFactory::uandiHatLoop).withLength(loopPoint),
            track(UandiTrackFactory::uandiRiser).withLength(loopPoint),
            UandiTrackFactory::uandiBassA,
            UandiTrackFactory::uandiFreak,
            UandiTrackFactory::uandiShaker,
            UandiTrackFactory::uandiTomEvent,
            track(UandiTrackFactory::uandiPiano).muted().withMuteEvent(loopPoint),
       });
    return seq;
}

Sequence UandiSequenceFactory::uandiBack()
{
    Sequence seq = buildSequence(
        4, 4, 0, "Back", songTempo, true,
        {
            UandiTrackFactory::uandiDiscoB,
            UandiTrackFactory::uandiHatLoop,
            UandiTrackFactory::uandiRiser
        });
    return seq;
}

Sequence UandiSequenceFactory::uandiClimax()
{
    Sequence seq = buildSequence(
        36, 4, 0, "Climax", songTempo, false,
        {
            SequenceTrackFactory::kickFour,
            SequenceTrackFactory::snareFour,
            UandiTrackFactory::uandiHatLoop,
            UandiTrackFactory::uandiOpenHat,
            UandiTrackFactory::uandiRiserCrash, //play once
            UandiTrackFactory::uandiBassAB,
            UandiTrackFactory::uandiWavetableAB,
            UandiTrackFactory::uandiDiscoAB,
            UandiTrackFactory::uandiShaker,
            UandiTrackFactory::uandiFreak,
            track(UandiTrackFactory::uandiRimFill).withStart(TICK(24)),
        });
    return seq;
}

Sequence UandiSequenceFactory::uandiEnd()
{
    Sequence seq = buildSequence(
        4, 4, 3, "End", songTempo, true,
        {
            track(UandiTrackFactory::uandiExplode).withStart(TICK(2)),
        });
    return seq;
}

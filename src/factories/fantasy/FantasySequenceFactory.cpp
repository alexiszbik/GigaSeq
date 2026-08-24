#include "FantasySequenceFactory.h"

#include "factories/SequenceBuilder.h"
#include "factories/SequenceTrackFactory.h"
#include "factories/fantasy/FantasyTrackFactory.h"
#include "MidiConst.h"

namespace {
constexpr uint8_t songTempo = 130;
}

Sequence FantasySequenceFactory::fantasyIntro()
{
    Sequence seq = buildSequence(
        4, 4, 0, "Intro", songTempo, true,
        {
            FantasyTrackFactory::fantasySample,
        });
    return seq;
}


Sequence FantasySequenceFactory::fantasyStart()
{
    Sequence seq = buildSequence(
        4, 4, 0, "Start", songTempo, true,
        {
            FantasyTrackFactory::fantasySample,
            FantasyTrackFactory::fantasyDrums,
            FantasyTrackFactory::fantasyShake,
            FantasyTrackFactory::fantasyChords,
        });
    return seq;
}

Sequence FantasySequenceFactory::fantasyBreak()
{
    Sequence seq = buildSequence(
        4, 4, 0, "Break", songTempo, true,
        {
            FantasyTrackFactory::fantasyHiDrum,
            track(FantasyTrackFactory::fantasyFreak).muted(),
            track(FantasyTrackFactory::fantasyVocals).muted(),
        });
    return seq;
}

Sequence FantasySequenceFactory::fantasyBack()
{
    Sequence seq = buildSequence(
        12, 4, 8, "FadeCut", songTempo, true,
        {
            track(FantasyTrackFactory::fantasySample).withStart(TICK(8)),
            track(FantasyTrackFactory::fantasySampleFadeCut).withLength(TICK(8)),
            track(FantasyTrackFactory::fantasyDrums).withStart(TICK(4)),
            track(FantasyTrackFactory::fantasyShake).withStart(TICK(4)),
            track(FantasyTrackFactory::fantasyChordOffset).withStart(TICK(4)),
            track(FantasyTrackFactory::fantasyHiDrum).withLength(TICK(4)),
            track(FantasyTrackFactory::fantasyFreak),
            track(FantasyTrackFactory::fantasyVocals),
            track(FantasyTrackFactory::fantasyRiser).withMuteEvent(TICK(8)).asFill(),
        });


    seq.track(2).addControlChange(0, 37, 0);
    seq.track(2).addControlChange(TICK(4,0,2), 37, 127);

    seq.track(2).addControlChange(0, 34, 0);
    seq.track(2).addControlChange(TICK(4,0,2), 34, 127);

    return seq;
}

Sequence FantasySequenceFactory::fantasyRave()
{
    tick_t snareStart = TICK(16);
    tick_t snareLength = TICK(32);

    uint8_t len = 48;

    Sequence seq = buildSequence(
        len, 4, 0, "Rave", songTempo, false,
        {
            FantasyTrackFactory::fantasyArp,
            FantasyTrackFactory::fantasyArpPoly,
            track(FantasyTrackFactory::fantasyArpBass).muted(),
            track(FantasyTrackFactory::fantasySnare909).withCC(36,10).withStart(TICK(16))
            .withAutomation(TICK(16), TICK(len), 36, 24, 127),
            FantasyTrackFactory::fantasyRiser,
            FantasyTrackFactory::fantasyBigRiz1
        });
    return seq;
}

Sequence FantasySequenceFactory::fantasyGuitar()
{
    Sequence seq = buildSequence(
        4, 4, 0, "Guitar", songTempo, true,
        {
            FantasyTrackFactory::fantasyBigClap,
        });
    return seq;
}

Sequence FantasySequenceFactory::fantasyGuitarRiz()
{
    Sequence seq = buildSequence(
        8, 4, 0, "GuitarRiz", songTempo, false,
        {
            track(FantasyTrackFactory::fantasyBigClap).withLength(TICK(15,2)),
            FantasyTrackFactory::fantasyBigRiz2
        });
    return seq;
}

Sequence FantasySequenceFactory::fantasyClimax()
{
    Sequence seq = buildSequence(
        8, 4, 0, "Climax", songTempo, true,
        {
            FantasyTrackFactory::fantasySample,
            FantasyTrackFactory::fantasyDrums,
            FantasyTrackFactory::fantasyShake,
            FantasyTrackFactory::fantasyChords,
            FantasyTrackFactory::fantasyShakeEnd,
            FantasyTrackFactory::fantasyVocals,
            track(FantasyTrackFactory::fantasyRiser).withMuteEvent(0).asFill(),
        });
    return seq;
}

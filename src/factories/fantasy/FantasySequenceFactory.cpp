#include "FantasySequenceFactory.h"

#include "factories/SequenceBuilder.h"
#include "factories/SequenceTrackFactory.h"
#include "factories/fantasy/FantasyTrackFactory.h"
#include "MidiChannel.h"

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


Sequence FantasySequenceFactory::fantasyRave()
{
    tick_t snareStart = TICK(16);
    tick_t snareLength = TICK(32);

    uint8_t len = 48;

    Sequence seq = buildSequence(
        len, 4, 0, "Rave", songTempo, false,
        {
            FantasyTrackFactory::fantasyArp,
            track(FantasyTrackFactory::fantasySnare909).withCC(36,10).withStart(TICK(16))
            .withAutomation(TICK(16), TICK(len), 36, 10, 127)
        });
    return seq;
}
Sequence FantasySequenceFactory::fantasyBreak()
{
    Sequence seq = buildSequence(
        4, 4, 0, "Break", songTempo, true,
        {
            FantasyTrackFactory::fantasyHiDrum,
            FantasyTrackFactory::fantasyFreak,
            FantasyTrackFactory::fantasyVocals,
        });
    return seq;
}

Sequence FantasySequenceFactory::fantasyBack()
{
    Sequence seq = buildSequence(
        12, 4, 8, "FadeCut", songTempo, false,
        {
            track(FantasyTrackFactory::fantasySample).withStart(TICK(8)),
            track(FantasyTrackFactory::fantasySampleFadeCut).withLength(TICK(8)),
            track(FantasyTrackFactory::fantasyDrums).withStart(TICK(4)),
            track(FantasyTrackFactory::fantasyShake).withStart(TICK(4)),
            track(FantasyTrackFactory::fantasyChords).withStart(TICK(4)),
            track(FantasyTrackFactory::fantasyHiDrum).withLength(TICK(4)),
            track(FantasyTrackFactory::fantasyFreak),
            track(FantasyTrackFactory::fantasyVocals),
        });
    return seq;
}

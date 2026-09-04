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
        8, 4, 4, "Intro", songTempo, true,
        {
            FantasyTrackFactory::fantasySampleIntro,
            track(SequenceTrackFactory::gtrPedal)
                .withProgramChange(HXStomp::kBass),
            track(SequenceTrackFactory::polySynth).withProgramChange(PolySynth::kFantasyChords),
            track(SequenceTrackFactory::microfreak).withProgramChange(Microfreak::kFantasyStabs),
            track(SequenceTrackFactory::gtrLoopErase)
                .withProgramChange(BossRC::kFantasy, TICK(2)),
            track(SequenceTrackFactory::midiLoop)
                .withNote(MidiLoop::kEraseAll)
                .withNote(MidiLoop::kSelectVocoder)
                .withCC(MidiLoop::kArpMode_cc, OFF)
                .withCC(MidiLoop::kRecord_cc, OFF)
                .withCC(MidiLoop::kBarCount_cc, 4),
            track(SequenceTrackFactory::vocoder)
                .withCC(Vocoder::kPlayMode_cc, 0)
                .withCC(Vocoder::kGlide_cc, 5)
                .withCC(Vocoder::kRelease_cc, 53)
                .withCC(Vocoder::kOscMix_cc, 127)
                .withCC(Vocoder::kOscAWaveform_cc, 0)
                .withCC(Vocoder::kOscBWaveform_cc, 0)
                .withCC(Vocoder::kOscAPwm_cc, 64)
                .withCC(Vocoder::kOscBPwm_cc, 64),
        });
    return seq;
}


Sequence FantasySequenceFactory::fantasyStart()
{
    Sequence seq = buildSequence(
        4, 4, 0, "Start", songTempo, true,
        {
            FantasyTrackFactory::fantasySampleSidekick,
            FantasyTrackFactory::fantasyDrums,
            FantasyTrackFactory::fantasyShake,
            FantasyTrackFactory::fantasyChords,
            track(SequenceTrackFactory::matrix).withProgramChange(LedMatrix::kFantasy_signA),
            track(FantasyTrackFactory::fantasyLedChorus1).withCC(LedStrips::kDecay_cc, 50)
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
            track(SequenceTrackFactory::polySynth).withCC(ModularA::kGlobalMute_cc, ON),
            SequenceTrackFactory::matrixKill,
            track(SequenceTrackFactory::ledStrips).withCC(LedStrips::kDecay_cc, 0),
        });
    return seq;
}

Sequence FantasySequenceFactory::fantasyBack()
{
    return buildSequence(
        16, 4, 12, "FadeCut", songTempo, true,
        {
            track(FantasyTrackFactory::fantasySampleSidekick).withStart(TICK(8)),
            track(FantasyTrackFactory::fantasySampleFadeCut).withLength(TICK(8)),
            track(FantasyTrackFactory::fantasyDrums).withStart(TICK(8))
                .withMuteEvent(TICK(8)).withMuteEvent(TICK(8, 1), false),
            track(FantasyTrackFactory::fantasyShake).withStart(TICK(8, 1)),
            track(FantasyTrackFactory::fantasyChordOffset).withStart(TICK(8)),
            track(FantasyTrackFactory::fantasyHiDrum).withLength(TICK(8)),
            track(FantasyTrackFactory::fantasyFreak),
//                .withMuteEvent(TICK(8)).withMuteEvent(TICK(8, 1), false),
            track(FantasyTrackFactory::fantasyVocals)
                .withCC(37, 0)
                .withCC(37, 127, TICK(4, 0, 2))
                .withCC(34, 0)
                .withCC(34, 127, TICK(4, 0, 2)),
            track(FantasyTrackFactory::fantasyRiser).withMuteEvent(TICK(8)).asFill(),
            FantasyTrackFactory::fantasyBreakFX,
            track(SequenceTrackFactory::polySynth)
                .withCC(ModularA::kGlobalMute_cc, OFF).withProgramChange(PolySynth::kFantasyChords),
            track(SequenceTrackFactory::gtrLoop)
                .withCC(BossRC::kVolume_cc, 0, TICK(8)).withCC(BossRC::kVolume_cc, 65, TICK(8, 1)),
            track(SequenceTrackFactory::matrix).withProgramChange(LedMatrix::kFantasy_signB, TICK(8, 1)),
            track(FantasyTrackFactory::fantasyLedChorus2).withCC(LedStrips::kDecay_cc, 50)
                .withStart(TICK(8, 0)) //TODO : make better sync
        });
}

Sequence FantasySequenceFactory::fantasyRave()
{
    uint8_t len = 48;

    Sequence seq = buildSequence(
        len, 4, 0, "Rave", songTempo, false,
        {
            FantasyTrackFactory::fantasyArp,
            track(FantasyTrackFactory::fantasyArpPoly)
                .withProgramChange(PolySynth::kRave),
            track(FantasyTrackFactory::fantasyArpBass).muted(),
            track(FantasyTrackFactory::fantasySnare909).withCC(36,10).withStart(TICK(16))
                .withAutomation(TICK(16), TICK(len), 36, 24, 127), //TODO : replace by a roll ?
            FantasyTrackFactory::fantasyRiser,
            FantasyTrackFactory::fantasyBigRiz1,
            SequenceTrackFactory::gtrLoopMute,
            track(SequenceTrackFactory::gtrPedal)
                .withProgramChange(HXStomp::kFantasySolo),
            SequenceTrackFactory::matrixKill,
            FantasyTrackFactory::fantasyLedRave
        });
    return seq;
}

Sequence FantasySequenceFactory::fantasyGuitar()
{
    Sequence seq = buildSequence(
        4, 4, 0, "Guitar", songTempo, true,
        {
            FantasyTrackFactory::fantasyBigClap,
            track(SequenceTrackFactory::modularA).withCC(ModularA::kGlobalMute_cc, ON),
            track(SequenceTrackFactory::bass).withCC(Bass::kGlobalMute_cc, ON),
            track(SequenceTrackFactory::polySynth).withCC(PolySynth::kGlobalMute_cc, ON)
        });
    return seq;
}

Sequence FantasySequenceFactory::fantasyGuitarRiz()
{
    Sequence seq = buildSequence(
        8, 4, 0, "GuitarRiz", songTempo, false,
        {
            track(FantasyTrackFactory::fantasyBigClap).withLength(TICK(7,2)),
            FantasyTrackFactory::fantasyBigRiz2,
            FantasyTrackFactory::fantasySampleFilterB,
            track(SequenceTrackFactory::gtrLoopUnmute).withStart(TICK(7,2)),
            track(SequenceTrackFactory::polySynth)
                .withProgramChange(PolySynth::kFantasyChords)
                .withCC(PolySynth::kGlobalMute_cc, OFF),
        });
    return seq;
}

Sequence FantasySequenceFactory::fantasyClimax()
{
    Sequence seq = buildSequence(
        8, 4, 4, "Climax", songTempo, true,
        {
            FantasyTrackFactory::fantasySampleSidekick,
            FantasyTrackFactory::fantasyDrums,
            FantasyTrackFactory::fantasyShake,
            FantasyTrackFactory::fantasyChords,
            FantasyTrackFactory::fantasyShakeEnd,
            FantasyTrackFactory::fantasyVocals,
            track(SequenceTrackFactory::modularA).withCC(ModularA::kGlobalMute_cc, OFF),
            track(SequenceTrackFactory::bass).withCC(Bass::kGlobalMute_cc, OFF),
            track(FantasyTrackFactory::fantasyRiser).withMuteEvent(0).asFill(),
            track(SequenceTrackFactory::matrix).withProgramChange(LedMatrix::kFantasy_signC),
            FantasyTrackFactory::fantasyRainbowChorus
        });
    return seq;
}

Sequence FantasySequenceFactory::fantasyEnd()
{
    tick_t loop = TICK(16);
    Sequence seq = buildSequence(
        17, 4, 16, "End", songTempo, true,
        {
            track(FantasyTrackFactory::fantasyArp).withLength(loop),
            track(FantasyTrackFactory::fantasyArpEnd).withStart(loop),
            track(FantasyTrackFactory::fantasySampleIntro).withLength(loop),
            track(FantasyTrackFactory::fantasyVocals).withLength(loop),
            FantasyTrackFactory::fantasyBigClap,
            SequenceTrackFactory::gtrLoopErase
        });
    return seq;
}

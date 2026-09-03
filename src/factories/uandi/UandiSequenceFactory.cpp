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
            track(UandiTrackFactory::uandiFreak).muted().withProgramChange(Microfreak::kUandI),
            track(UandiTrackFactory::uandiRiser).muted().withMuteEvent(0).asFill(),
            track(SequenceTrackFactory::polySynth).withProgramChange(PolySynth::kSlowStr),
            track(SequenceTrackFactory::gtrPedal).withProgramChange(HXStomp::kUandI),
            track(SequenceTrackFactory::drumMachine)
                .withCC(DrumMachine::kClearAll_cc, ON)
                .withCC(DrumMachine::kPerformMode_cc, ON)
                .withCC(DrumMachine::kRepeatMode_cc, ON)
        });
    return seq;
}

Sequence UandiSequenceFactory::uandiIntroB()
{
    Sequence seq = buildSequence(
        4, 4, 0, "IntroB", songTempo, false,
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
        4, 4, 0, "Back", songTempo, false,
        {
            UandiTrackFactory::uandiDiscoB,
            UandiTrackFactory::uandiHatLoop,
            UandiTrackFactory::uandiRiser,
            track(SequenceTrackFactory::modularA).withCC(ModularA::kMuteClock_cc, ON),
            track(SequenceTrackFactory::bass).withCC(Bass::kGlobalMute_cc, ON),
            track(SequenceTrackFactory::gtrPedal)
                .withCC(HXStomp::kUandI_ccShifter, OFF, TICK(3,2)) 
                .withCC(HXStomp::kUandI_ccDrive, ON),
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
            UandiTrackFactory::uandiSweep,
            track(UandiTrackFactory::uandiRimFill).withStart(TICK(24)),
            track(SequenceTrackFactory::modularA).withCC(ModularA::kMuteClock_cc, OFF),
            track(SequenceTrackFactory::bass)
                .withCC(Bass::kHpfCutoff_cc, 0)
                .withCC(Bass::kHpfResonance_cc, 0)
                .withCC(Bass::kReverbSend_cc, 0)
                .withCC(Bass::kGlobalMute_cc, OFF),
            
        });
    return seq;
}

Sequence UandiSequenceFactory::uandiEnd()
{
    Sequence seq = buildSequence(
        4, 4, 3, "End", songTempo, true,
        {
            track(SequenceTrackFactory::sampler).withNote(69),
            track(UandiTrackFactory::uandiExplode).withStart(TICK(2)),
            track(SequenceTrackFactory::microfreak).withProgramChange(Microfreak::kUandIDust),
            track(UandiTrackFactory::uandiDust).withStart(TICK(2)).withProgramChange(Microfreak::kUandIDust),
        });
    return seq;
}

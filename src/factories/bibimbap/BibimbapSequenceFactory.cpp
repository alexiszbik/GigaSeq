#include "BibimbapSequenceFactory.h"

#include "factories/SequenceBuilder.h"
#include "factories/SequenceTrackFactory.h"
#include "factories/bibimbap/BibimbapTrackFactory.h"
#include "MidiConst.h"

namespace {
constexpr uint8_t songTempo = 135;
}

Sequence BibimbapSequenceFactory::bibimbapIntro()
{
    Sequence seq = buildSequence(
        8, 7, 4, "Intro", songTempo, true,
        {
            BibimbapTrackFactory::bibimbapKickHi,
            BibimbapTrackFactory::bibimbapTom,
            track(SequenceTrackFactory::gtrLoopErase)
                .withProgramChange(BossRC::kBiBimBap, TICK(2)),
            track(SequenceTrackFactory::gtrPedal)
                .withProgramChange(HXStomp::kBiBimBapIntro),
            track(SequenceTrackFactory::microfreak).withProgramChange(Microfreak::kBiBimBap),
            track(SequenceTrackFactory::polySynth).withProgramChange(PolySynth::kSlowStr),
            track(SequenceTrackFactory::midiLoop)
                .withNote(MidiLoop::kEraseAll)
                .withNote(MidiLoop::kSelectPoly)
                .withCC(MidiLoop::kArpMode_cc, OFF)
                .withCC(MidiLoop::kRecord_cc, OFF),
            SequenceTrackFactory::ledStripsTest
        });
    return seq;
}

Sequence BibimbapSequenceFactory::bibimbapMain()
{
    Sequence seq = buildSequence(
        12, 7, 4, "Main", songTempo, true,
        {
            BibimbapTrackFactory::bibimbapKickHi,
            BibimbapTrackFactory::bibimbapTom,
            BibimbapTrackFactory::bibimbapShaker,
            track(BibimbapTrackFactory::bibimbapRim).withStart(TICK(0,7*4)),
            track(BibimbapTrackFactory::bibimbapPercs).withStart(TICK(0,7*4)).muted(),
            track(BibimbapTrackFactory::bibimbapDizee).withStart(TICK(0,7*4)),
            track(BibimbapTrackFactory::bibimbapVocals).withStart(TICK(0,7*4)),
            track(BibimbapTrackFactory::bibimbapMarimbaVerb).withStart(TICK(0,7*4)).muted(),
        });
    return seq;
}


Sequence BibimbapSequenceFactory::bibimbapBass()
{
    Sequence seq = buildSequence(
        8, 7, 0, "Bass", songTempo, false,
        {
            track(BibimbapTrackFactory::bibimbapShaker).withStart(TICK(0,7*4)),
            BibimbapTrackFactory::bibimbapDizee,
            BibimbapTrackFactory::bibimbapVocals,
            BibimbapTrackFactory::bibimbapMarimbaVerb,
            BibimbapTrackFactory::bibimbapXyloLoop,
            BibimbapTrackFactory::bibimbapBass,
            BibimbapTrackFactory::bibimbapRiser
        });
    return seq;
}

Sequence BibimbapSequenceFactory::bibimbapBassFull()
{
    Sequence seq = buildSequence(
        8, 7, 0, "Bass", songTempo, true,
        {
            SequenceTrackFactory::kickFour,
            BibimbapTrackFactory::bibimbapKickHi,
            BibimbapTrackFactory::bibimbapTomB,
            BibimbapTrackFactory::bibimbapShaker,
            BibimbapTrackFactory::bibimbapRim,
            BibimbapTrackFactory::bibimbapPercsB,
            BibimbapTrackFactory::bibimbapDizee,
            BibimbapTrackFactory::bibimbapVocals,
            BibimbapTrackFactory::bibimbapMarimbaVerb,
            BibimbapTrackFactory::bibimbapXyloLoop,
            BibimbapTrackFactory::bibimbapBass,
            track(BibimbapTrackFactory::bibimbapFreak).muted(),
            track(BibimbapTrackFactory::bibimbapHats).muted(),
            track(BibimbapTrackFactory::bibimbapRiser).muted().asFill(),
        });
    return seq;
}

Sequence BibimbapSequenceFactory::bibimbapPause()
{
    Sequence seq = buildSequence(
        8, 7, 4, "Pause", songTempo, true,
        {
            BibimbapTrackFactory::bibimbapShaker,
            track(SequenceTrackFactory::gtrPedal)
                .withProgramChange(HXStomp::kBiBimBapSolo),
        });
    return seq;
}

Sequence BibimbapSequenceFactory::bibimbapDrop()
{
    tick_t dropPoint = TICK(0,24,2);

    Sequence seq = buildSequence(
        4, 7, 0, "Drop", songTempo, false,
        {
            track(BibimbapTrackFactory::bibimbapShaker).withLength(dropPoint),
            track(BibimbapTrackFactory::bibimbapSnareRoll).withLength(dropPoint),
            BibimbapTrackFactory::bibimbapDizee4bars,
            track(BibimbapTrackFactory::bibimbapRiser).withLength(dropPoint),
            track(SequenceTrackFactory::gtrLoopMute).withStart(dropPoint),
            track(SequenceTrackFactory::gtrPedal).withCC(HXStomp::kBiBimBapSolo_ccDrive, OFF, dropPoint),
            track(SequenceTrackFactory::polySynth).withCC(PolySynth::kGlobalMute_cc, ON, dropPoint),
            track(SequenceTrackFactory::modularA).withCC(ModularA::kMuteClock_cc, ON, dropPoint),
        });
    return seq;
}

Sequence BibimbapSequenceFactory::bibimbapClimax()
{
    tick_t len = TICK(0,7*16);
    Sequence seq = buildSequence(
        20, 7, 16, "Climax", songTempo, true,
        {
            track(SequenceTrackFactory::kickFour).withLength(len),
            track(BibimbapTrackFactory::bibimbapKickHi).withLength(len),
            track(BibimbapTrackFactory::bibimbapTomB).withLength(len),
            track(BibimbapTrackFactory::bibimbapShaker).withLength(len),
            track(BibimbapTrackFactory::bibimbapRim).withLength(len),
            track(BibimbapTrackFactory::bibimbapPercsB).withLength(len),
            track(BibimbapTrackFactory::bibimbapDizee).withLength(len),
            track(BibimbapTrackFactory::bibimbapVocals).withLength(len),
            track(BibimbapTrackFactory::bibimbapMarimbaVerb).withLength(len),
            track(BibimbapTrackFactory::bibimbapXyloLoop).withLength(len),
            track(BibimbapTrackFactory::bibimbapBass).withLength(len),
            track(BibimbapTrackFactory::bibimbapHats).withLength(len),
            track(BibimbapTrackFactory::bibimbapFreak).withLength(len),
            track(BibimbapTrackFactory::bibimbapRiser).withLength(len),
            track(BibimbapTrackFactory::bibimbapSnare).withLength(len),
            track(BibimbapTrackFactory::bibimbapSnareRoll2).withStart(TICK(0,7*13)).withLength(TICK(0,7*3)),
            track(BibimbapTrackFactory::bibimbapArp).withStart(TICK(0,7*8)),
            BibimbapTrackFactory::bibimbapOpenHat,
            track(SequenceTrackFactory::gtrLoopUnmute),
            track(SequenceTrackFactory::gtrLoopErase).withStart(len),
            track(SequenceTrackFactory::gtrPedal)
                .withCC(HXStomp::kBiBimBapSolo_ccGain, ON)
                .withCC(HXStomp::kBiBimBapSolo_ccDrive, ON),
            track(SequenceTrackFactory::polySynth).withCC(PolySynth::kGlobalMute_cc, OFF),
            track(SequenceTrackFactory::modularA).withCC(ModularA::kMuteClock_cc, OFF),
        });
    return seq;
}

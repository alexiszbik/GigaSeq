#include "CloserSequenceFactory.h"

#include "factories/SequenceBuilder.h"
#include "factories/SequenceTrackFactory.h"
#include "factories/closer/CloserTrackFactory.h"
#include "factories/falling/FallingTrackFactory.h"
#include "MidiConst.h"

namespace {
    constexpr uint8_t songTempo = 130;
}

Sequence CloserSequenceFactory::closerIntro()
{

    Sequence seq = buildSequence(
        8, 4, 4, "Intro", songTempo, true,
        {
            SequenceTrackFactory::kickFour,
            track(CloserTrackFactory::closerHats).muted(),
            track(CloserTrackFactory::closerLoopHat).muted(),
            track(CloserTrackFactory::closerClapTom).muted(),
            track(CloserTrackFactory::closerModular).muted(),
            track(FallingTrackFactory::fallingHarp).withProgramChange(Microfreak::kFallingHarp),
            track(CloserTrackFactory::closerStab).withProgramChange(PolySynth::kCloser),
            track(CloserTrackFactory::closerFill808).withMuteEvent(TICK(4)).asFill(),
            track(CloserTrackFactory::closerRiser).withMuteEvent(TICK(4)).asFill(),
            track(SequenceTrackFactory::gtrLoopErase).withProgramChange(BossRC::kCloser, TICK(4)),
            track(SequenceTrackFactory::midiLoop)
                .withNote(MidiLoop::kSelectBass)
                .withCC(MidiLoop::kArpMode_cc, OFF)
                .withCC(MidiLoop::kRecord_cc, ON)
                .withCC(MidiLoop::kBarCount_cc, 4),
        });
    return seq;
}

Sequence CloserSequenceFactory::closerChords()
{
    Sequence seq = buildSequence(
        8, 4, 0, "Chords", songTempo, true,
        {
            track(CloserTrackFactory::closerChords).withProgramChange(Microfreak::kCloserChords),
            CloserTrackFactory::closerModular,
            track(CloserTrackFactory::closerTambourin).muted(),
            track(SequenceTrackFactory::gtrPedal).withProgramChange(HXStomp::kCloserBassDisto),
            track(SequenceTrackFactory::midiLoop).withCC(MidiLoop::kMuteBass_cc, ON)
        });
    return seq;
}

Sequence CloserSequenceFactory::closerBass()
{
    Sequence seq = buildSequence(
        8, 4, 0, "Bass", songTempo, true,
        {
            CloserTrackFactory::closerChords,
            CloserTrackFactory::closerModular,
            CloserTrackFactory::closerTambourin,
            SequenceTrackFactory::clapFour,
            track(SequenceTrackFactory::kickFour).muted(),
            track(CloserTrackFactory::closerSing).muted(),
            track(CloserTrackFactory::closerTop).muted(),
        });
    return seq;
}

Sequence CloserSequenceFactory::closerBlast()
{
    Sequence seq = buildSequence(
        8, 4, 0, "Blast", songTempo, false,
        {
            CloserTrackFactory::closerChords,
            CloserTrackFactory::closerArp,
            CloserTrackFactory::closerTambourin,
            CloserTrackFactory::closerRiser,
            CloserTrackFactory::closerBlastCymb,
            CloserTrackFactory::closerBlastKick,
            CloserTrackFactory::closerBlastSnare,
        });
    return seq;
}

Sequence CloserSequenceFactory::closerBackKick()
{
    Sequence seq = buildSequence(
        8, 4, 0, "BackKick", songTempo, true,
        {
            SequenceTrackFactory::kickFour,
            track(CloserTrackFactory::closerHats).muted(),
            track(CloserTrackFactory::closerLoopHat).muted(),
            CloserTrackFactory::closerStab,
            track(CloserTrackFactory::closerFill808).withMuteEvent(0).asFill(),
            track(CloserTrackFactory::closerRiser).withMuteEvent(0).asFill(),
            track(SequenceTrackFactory::gtrLoopErase),
            track(SequenceTrackFactory::midiLoop)
                .withCC(MidiLoop::kMuteBass_cc, OFF)
                .withCC(MidiLoop::kCopy_cc, 1)
        });
    return seq;
}

Sequence CloserSequenceFactory::closerClimax()
{
    Sequence seq = buildSequence(
        8, 4, 4, "Climax", songTempo, true,
        {
            SequenceTrackFactory::kickFour,
            CloserTrackFactory::closerClapTom,
            track(CloserTrackFactory::closerHats).muted(),
            track(CloserTrackFactory::closerLoopHat).muted(),
            CloserTrackFactory::closerStab,
            track(CloserTrackFactory::closerFill808).withMuteEvent(TICK(4)).asFill(),
            track(CloserTrackFactory::closerRiser).withMuteEvent(TICK(4)).asFill(),
            CloserTrackFactory::closer303,
            track(CloserTrackFactory::closerDrumix).muted(),
            track(SequenceTrackFactory::microfreak).withProgramChange(Microfreak::kCloserHouse),
            track(SequenceTrackFactory::midiLoop)
                .withCC(MidiLoop::kPaste_cc, 3)
        });
    return seq;
}


Sequence CloserSequenceFactory::closerEnd()
{
    Sequence seq = buildSequence(
        4, 4, 0, "Climax", songTempo, true,
        {
            track(CloserTrackFactory::closerRiser).withMuteEvent(0).asFill(),
        });
    return seq;
}


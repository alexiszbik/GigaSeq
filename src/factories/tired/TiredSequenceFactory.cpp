#include "TiredSequenceFactory.h"

#include "factories/SequenceBuilder.h"
#include "factories/SequenceTrackFactory.h"
#include "factories/tired/TiredTrackFactory.h"
#include "MidiConst.h"

namespace {
constexpr uint8_t songTempo = 145;
}

Sequence TiredSequenceFactory::tiredIntro()
{
    Sequence seq = buildSequence(
        16, 4, 8, "Intro", songTempo, true,
        {
            track(SequenceTrackFactory::kickFour).muted(),
            track(TiredTrackFactory::tiredFreak).withProgramChange(Microfreak::kTiredBass),
            track(TiredTrackFactory::tiredHats).muted(),
            track(TiredTrackFactory::tiredIntro),
            track(TiredTrackFactory::tiredHatSolo),
            track(TiredTrackFactory::tiredCongas).muted(),
            track(TiredTrackFactory::tiredRoboto).muted(),
            track(TiredTrackFactory::tiredShake).muted(),
            track(SequenceTrackFactory::gtrPedal).withProgramChange(HXStomp::kTiredSlicer),
            track(SequenceTrackFactory::gtrLoop).withProgramChange(BossRC::kTired),
             track(SequenceTrackFactory::polySynth).withProgramChange(PolySynth::kFilterStr),
            track(SequenceTrackFactory::midiLoop)
                .withNote(MidiLoop::kEraseAll)
                .withNote(MidiLoop::kSelectPoly)
                .withCC(MidiLoop::kArpMode_cc, OFF)
                .withCC(MidiLoop::kRecord_cc, OFF)
                .withCC(MidiLoop::kBarCount_cc, 8),
        });
    return seq;
}

Sequence TiredSequenceFactory::tiredDropA()
{
    Sequence seq = buildSequence(
        16, 4, 0, "DropA", songTempo, false,
        {
            TiredTrackFactory::tiredSync,
            TiredTrackFactory::tiredPhazeHat,
            TiredTrackFactory::tiredUpRising,
            TiredTrackFactory::tiredRiserA,
            TiredTrackFactory::tiredFreak,
        });
    return seq;
}

Sequence TiredSequenceFactory::tiredMain()
{
    Sequence seq = buildSequence(
        8, 4, 0, "Main", songTempo, true,
        {
            SequenceTrackFactory::kickFour,
            TiredTrackFactory::tiredFreak,
            TiredTrackFactory::tiredSync,
            TiredTrackFactory::tiredPhazeHat,
            TiredTrackFactory::tiredShake,
            TiredTrackFactory::tiredClapEcho,
            track(TiredTrackFactory::tiredWhiteNoise).withMuteEvent(TICK(1)),
            track(TiredTrackFactory::tiredRiserA).muted(),
            TiredTrackFactory::tiredCymbal,
        });
    return seq;
}

Sequence TiredSequenceFactory::tiredPause()
{
    Sequence seq = buildSequence(
        8, 4, 0, "Pause", songTempo, true,
        {
            TiredTrackFactory::tiredFreak,
            TiredTrackFactory::tiredSync,
            TiredTrackFactory::tiredPhazeHat,
            TiredTrackFactory::tiredShake,
            TiredTrackFactory::tiredClapEcho,
            TiredTrackFactory::tiredRiserA,
            TiredTrackFactory::tiredCymbal,
            track(SequenceTrackFactory::gtrPedal).withProgramChange(HXStomp::kTiredDelay),
        });
    return seq;
}

Sequence TiredSequenceFactory::tiredDropB()
{
    return buildSequence(
        8, 4, 0, "DropB", songTempo, false,
        {
            track(TiredTrackFactory::tiredFreak).withLength(TICK(7)),
            track(TiredTrackFactory::tiredSync).withLength(TICK(7)),
            track(TiredTrackFactory::tiredPhazeHat).withNote(68, 127, TICK(7)),
            track(TiredTrackFactory::tiredShake).withLength(TICK(7)),
            track(TiredTrackFactory::tiredClapEcho),
            TiredTrackFactory::tiredUpRisingB,
            track(TiredTrackFactory::tiredSnareRoll),
            track(TiredTrackFactory::tiredRiserB),
            track(TiredTrackFactory::tiredCymbal),
            track(SequenceTrackFactory::midiLoop)
                .withNote(MidiLoop::kEraseAll)
                .withNote(MidiLoop::kSelectBass)
                .withCC(MidiLoop::kArpMode_cc, ON)
                .withCC(MidiLoop::kRecord_cc, ON)
                .withCC(MidiLoop::kBarCount_cc, 8),
        });
}

Sequence TiredSequenceFactory::tiredMainB()
{
    Sequence seq = buildSequence(
        8, 4, 0, "Main", songTempo, true,
        {
            SequenceTrackFactory::kickFour,
            TiredTrackFactory::tiredFreak,
            TiredTrackFactory::tiredSync,
            TiredTrackFactory::tiredRoboto,
            TiredTrackFactory::tiredPhazeHat,
            TiredTrackFactory::tiredShake,
            TiredTrackFactory::tiredClapEcho,
            track(TiredTrackFactory::tiredWhiteNoise).withMuteEvent(TICK(1)),
            TiredTrackFactory::tiredRiserB,
            TiredTrackFactory::tiredCymbal,
        });
    return seq;
}

Sequence TiredSequenceFactory::tiredMainBBass()
{
    Sequence seq = buildSequence(
        40, 4, 36, "MainBBass", songTempo, true,
        {
            track(SequenceTrackFactory::kickFour).withLength(TICK(32)),
            track(TiredTrackFactory::tiredFreak).withLength(TICK(32)),
            track(TiredTrackFactory::tiredSync).withLength(TICK(32)),
            track(TiredTrackFactory::tiredRoboto).withLength(TICK(32)),
            track(TiredTrackFactory::tiredPhazeHat).withLength(TICK(32)),
            track(TiredTrackFactory::tiredShake).withLength(TICK(32)),
            track(TiredTrackFactory::tiredClave).withLength(TICK(32)),
            track(TiredTrackFactory::tiredRide).withStart(TICK(16)).withLength(TICK(16)),
            TiredTrackFactory::tiredMainBBassEvents,
            track(SequenceTrackFactory::gtrLoopErase).withStart(TICK(32)),
            track(TiredTrackFactory::tiredRiserB).muted().asFill(),
        });
    return seq;
}

Sequence TiredSequenceFactory::tiredPartBStart()
{
    Sequence seq = buildSequence(
        8, 4, 4, "PartBStart", songTempo, true,
        {
            TiredTrackFactory::tiredStabs, //make program change for poly synth
            track(SequenceTrackFactory::gtrLoop).withProgramChange(BossRC::kTiredEnd),
            track(SequenceTrackFactory::gtrPedal).withProgramChange(HXStomp::kTiredEndA),
            track(SequenceTrackFactory::microfreak).withProgramChange(Microfreak::kTiredArp),
            track(SequenceTrackFactory::midiLoop)
                .withNote(MidiLoop::kEraseAll)
        });
    return seq;
}

Sequence TiredSequenceFactory::tiredPartBSolo()
{
    Sequence seq = buildSequence(
        20, 4, 16, "PartBSolo", songTempo, true,
        {
            TiredTrackFactory::tiredStabs,
            track(TiredTrackFactory::tiredImpacts).withMuteEvent(0).withMuteEvent(TICK(3,3,2), false),
            track(TiredTrackFactory::tiredImpactsKick).withMuteEvent(0).withMuteEvent(TICK(3,3,2), false),
            track(TiredTrackFactory::tiredTechHats).withStart(TICK(12)),
            track(TiredTrackFactory::tiredFreakArp).muted(),
            TiredTrackFactory::tiredRollHat,
            track(TiredTrackFactory::tiredRiserA).withLength(TICK(4)),
        });
    return seq;
}

Sequence TiredSequenceFactory::tiredPartBPreRoll()
{
    Sequence seq = buildSequence(
        8, 4, 0, "PartBPreRoll", songTempo, false,
        {
            TiredTrackFactory::tiredStabs,
            TiredTrackFactory::tiredImpacts,
            TiredTrackFactory::tiredImpactsKick,
            TiredTrackFactory::tiredTechHats,
            TiredTrackFactory::tiredFreakArp,
            TiredTrackFactory::tiredBass,
            TiredTrackFactory::tiredRiserA,
            track(SequenceTrackFactory::gtrPedal).withProgramChange(HXStomp::kTiredEndB),
            track(SequenceTrackFactory::polySynth).withProgramChange(PolySynth::kBigLead),
        });
    return seq;
}

Sequence TiredSequenceFactory::tiredPartBClimax()
{
    Sequence seq = buildSequence(
        16, 4, 0, "PartBClimax", songTempo, false,
        {
            TiredTrackFactory::tiredStabs,
            TiredTrackFactory::tiredImpacts,
            TiredTrackFactory::tiredTechKick,
            TiredTrackFactory::tiredTechHats,
            TiredTrackFactory::tiredFreakArp,
            TiredTrackFactory::tiredBass,
            TiredTrackFactory::tiredRiserA,
        });
    return seq;
}

Sequence TiredSequenceFactory::tiredBigEnd()
{
    Sequence seq = buildSequence(
        20, 4, 16, "BigEnd", songTempo, true,
        {
            track(TiredTrackFactory::tiredStabs).withLength(TICK(16)),
            track(TiredTrackFactory::tiredBigDrums).withLength(TICK(16)),
            TiredTrackFactory::tiredFreakArp,
            track(TiredTrackFactory::tiredBass).withLength(TICK(16)),
            track(TiredTrackFactory::tiredClapRoll).withStart(TICK(8)).withLength(TICK(8)),
            track(TiredTrackFactory::tiredRiserB).withLength(TICK(16)),
            track(TiredTrackFactory::tiredRiserA).withLength(TICK(16)),
        });
    return seq;
}

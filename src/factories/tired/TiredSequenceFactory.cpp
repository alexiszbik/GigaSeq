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
        8, 4, 0, "Intro", songTempo, true,
        {
            SequenceTrackFactory::kickFour,
            TiredTrackFactory::tiredFreak,
            TiredTrackFactory::tiredHats,
            TiredTrackFactory::tiredIntro,
            TiredTrackFactory::tiredHatSolo,
            TiredTrackFactory::tiredCongas,
            TiredTrackFactory::tiredRoboto,
            TiredTrackFactory::tiredShake,
            track(SequenceTrackFactory::gtrPedal).withProgramChange(HXStomp::kTiredSlicer)
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
            track(SequenceTrackFactory::gtrPedal).withProgramChange(1)
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
            TiredTrackFactory::tiredWhiteNoise,
            TiredTrackFactory::tiredRiserA,
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
        });
    return seq;
}

Sequence TiredSequenceFactory::tiredDropB()
{
    Sequence seq = buildSequence(
        8, 4, 0, "DropB", songTempo, false,
        {
            track(TiredTrackFactory::tiredFreak).withLength(TICK(7)),
            track(TiredTrackFactory::tiredSync).withLength(TICK(7)),
            track(TiredTrackFactory::tiredPhazeHat),
            track(TiredTrackFactory::tiredShake).withLength(TICK(7)),
            track(TiredTrackFactory::tiredClapEcho),
            track(TiredTrackFactory::tiredSnareRoll),
            track(TiredTrackFactory::tiredRiserB),
            track(TiredTrackFactory::tiredCymbal),
        });

    seq.track(2).addNote(TICK(7), TickHelper::kStepLen, 68, 127);
    return seq;
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
        36, 4, 32, "MainBBass", songTempo, true,
        {
            track(SequenceTrackFactory::kickFour).withLength(TICK(32)),
            track(TiredTrackFactory::tiredFreak).withLength(TICK(32)),
            track(TiredTrackFactory::tiredSync).withLength(TICK(32)),
            track(TiredTrackFactory::tiredRoboto).withLength(TICK(32)),
            track(TiredTrackFactory::tiredPhazeHat).withLength(TICK(32)),
            track(TiredTrackFactory::tiredShake).withLength(TICK(32)),
            track(TiredTrackFactory::tiredClave).withLength(TICK(32)),
            track(TiredTrackFactory::tiredRide).withStart(TICK(16)).withLength(TICK(16)),
            TiredTrackFactory::tiredMainBBassEvents
        });
    return seq;
}

Sequence TiredSequenceFactory::tiredPartBStart()
{
    Sequence seq = buildSequence(
        4, 4, 0, "PartBStart", songTempo, true,
        {
            TiredTrackFactory::tiredStabs,
        });
    return seq;
}

Sequence TiredSequenceFactory::tiredPartBSolo()
{
    Sequence seq = buildSequence(
        20, 12, 0, "PartBSolo", songTempo, true,
        {
            TiredTrackFactory::tiredStabs,
            TiredTrackFactory::tiredRollHat,
            track(TiredTrackFactory::tiredImpacts).withMuteEvent(0).withMuteEvent(TICK(3,3,2), false),
            track(TiredTrackFactory::tiredImpactsKick).withMuteEvent(0).withMuteEvent(TICK(3,3,2), false),
            track(TiredTrackFactory::tiredTechHats).withStart(TICK(12)),
        });
    return seq;
}

Sequence TiredSequenceFactory::tiredFreakArp()
{
    Sequence seq = buildSequence(
        8, 4, 0, "FreakArp", songTempo, true,
        {
            TiredTrackFactory::tiredFreakArp,
            TiredTrackFactory::tiredStabs,
            TiredTrackFactory::tiredBass,
            TiredTrackFactory::tiredTechHats,
            TiredTrackFactory::tiredImpacts,
            TiredTrackFactory::tiredImpactsKick,
            TiredTrackFactory::tiredTechKick,
            track(SequenceTrackFactory::gtrPedal).withProgramChange(2)
        });
    return seq;
}

Sequence TiredSequenceFactory::tiredBigEnd()
{
    Sequence seq = buildSequence(
        8, 4, 0, "BigEnd", songTempo, true,
        {
            TiredTrackFactory::tiredBigDrums,
            TiredTrackFactory::tiredClapRoll,
            track(SequenceTrackFactory::gtrPedal).withProgramChange(3)
        });
    return seq;
}

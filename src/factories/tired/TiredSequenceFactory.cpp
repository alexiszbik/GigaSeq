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
            track(SequenceTrackFactory::gtrPedal).withProgramChange(HXStomp::kWater)
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

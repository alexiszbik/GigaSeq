#include "TiredSequenceFactory.h"

#include "factories/SequenceBuilder.h"
#include "factories/SequenceTrackFactory.h"
#include "factories/tired/TiredTrackFactory.h"
#include "MidiChannel.h"

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
            TiredTrackFactory::tiredFreak
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
            TiredTrackFactory::tiredTechKick
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
        });
    return seq;
}

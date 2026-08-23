#include "CloserSequenceFactory.h"

#include "factories/SequenceBuilder.h"
#include "factories/SequenceTrackFactory.h"
#include "factories/closer/CloserTrackFactory.h"
#include "MidiChannel.h"

namespace {
    constexpr uint8_t songTempo = 130;
}

Sequence CloserSequenceFactory::closerIntro()
{

    Sequence seq = buildSequence(
        8, 4, 0, "Intro", songTempo, true,
        {
            SequenceTrackFactory::kickFour,
            track(CloserTrackFactory::closerHats).muted(),
            track(CloserTrackFactory::closerLoopHat).muted(),
            track(CloserTrackFactory::closerTambourin).muted(),
            track(CloserTrackFactory::closerClapTom).muted(),
            track(CloserTrackFactory::closerModular).muted(),
            CloserTrackFactory::closerStab,
            track(CloserTrackFactory::closerFill808).withMuteEvent(0).asFill(),
            track(CloserTrackFactory::closerRiser).withMuteEvent(0).asFill(),
        });
    return seq;
}

Sequence CloserSequenceFactory::closerChords()
{
    Sequence seq = buildSequence(
        8, 4, 0, "Chords", songTempo, true,
        {
            CloserTrackFactory::closerChords,
            CloserTrackFactory::closerModular,
            track(CloserTrackFactory::closerTambourin).muted(),
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
            track(CloserTrackFactory::closerTambourin).muted(),
            CloserTrackFactory::closerStab,
            track(CloserTrackFactory::closerFill808).withMuteEvent(0).asFill(),
            track(CloserTrackFactory::closerRiser).withMuteEvent(0).asFill(),
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
            track(CloserTrackFactory::closerTambourin).muted(),
            CloserTrackFactory::closerStab,
            track(CloserTrackFactory::closerFill808).withMuteEvent(TICK(4)).asFill(),
            track(CloserTrackFactory::closerRiser).withMuteEvent(TICK(4)).asFill(),
            CloserTrackFactory::closer303,
            track(CloserTrackFactory::closerDrumix).muted(),
        });
    return seq;
}

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
        4, 7, 0, "Intro", songTempo, true,
        {
            BibimbapTrackFactory::bibimbapKickHi,
            BibimbapTrackFactory::bibimbapTom,
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
            track(BibimbapTrackFactory::bibimbapVocals).withStart(TICK(0,7*4)).muted(),
            track(BibimbapTrackFactory::bibimbapMarimbaVerb).withStart(TICK(0,7*4)).muted(),
        });
    return seq;
}

Sequence BibimbapSequenceFactory::bibimbapBass()
{
    Sequence seq = buildSequence(
        32, 7, 16, "Bass", songTempo, true,
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
        4, 7, 0, "Pause", songTempo, true,
        {
            BibimbapTrackFactory::bibimbapShaker,
        });
    return seq;
}

Sequence BibimbapSequenceFactory::bibimbapDrop()
{
    tick_t dropPoint = TICK(0,24,2);

    Sequence seq = buildSequence(
        4, 7, 0, "Drop", songTempo, true,
        {
            track(BibimbapTrackFactory::bibimbapShaker).withLength(dropPoint),
            track(BibimbapTrackFactory::bibimbapSnareRoll).withLength(dropPoint),
            BibimbapTrackFactory::bibimbapDizee4bars,
            track(BibimbapTrackFactory::bibimbapRiser).withLength(dropPoint),
        });
    return seq;
}

Sequence BibimbapSequenceFactory::bibimbapClimax()
{
    tick_t len = TICK(0,7*24);
    Sequence seq = buildSequence(
        28, 7, 24, "Climax", songTempo, true,
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
            BibimbapTrackFactory::bibimbapArp,
            BibimbapTrackFactory::bibimbapOpenHat,
        });
    return seq;
}

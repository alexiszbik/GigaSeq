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
            BibimbapTrackFactory::bibimbapArp,
            BibimbapTrackFactory::bibimbapRiser,
        });
    return seq;
}

Sequence BibimbapSequenceFactory::bibimbapMain()
{
    Sequence seq = buildSequence(
        8, 7, 0, "Main", songTempo, true,
        {
            BibimbapTrackFactory::bibimbapKickHi,
            BibimbapTrackFactory::bibimbapTom,
            BibimbapTrackFactory::bibimbapShaker,
            BibimbapTrackFactory::bibimbapRim,
            BibimbapTrackFactory::bibimbapPercs,
            BibimbapTrackFactory::bibimbapDizee,
            BibimbapTrackFactory::bibimbapVocals,
            BibimbapTrackFactory::bibimbapMarimbaVerb,
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
            BibimbapTrackFactory::bibimbapHats,
            BibimbapTrackFactory::bibimbapRiser,
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

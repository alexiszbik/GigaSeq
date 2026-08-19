#include "TogetherSequenceFactory.h"

#include "factories/SequenceBuilder.h"
#include "factories/SequenceTrackFactory.h"
#include "factories/together/TogetherTrackFactory.h"
#include "MidiChannel.h"

Sequence TogetherSequenceFactory::togetherIntro()
{
    Sequence seq = buildSequence(
        8, 4, 0, "Intro", 130, true,
        {
            TogetherTrackFactory::togetherArp
        });

    addProgramChangeTrack(seq, "Poly pgm", MidiChannel::kPoly, 1);
    return seq;
}

Sequence TogetherSequenceFactory::togetherSample()
{
    Sequence seq = buildSequence(
        8, 4, 0, "Sample", 130, true,
        {
            TogetherTrackFactory::togetherArp,
            TogetherTrackFactory::togetherHiDrum,
            TogetherTrackFactory::togetherSample,
            TogetherTrackFactory::togetherDX7
        });

    seq.track(2).setStartMuted();
    seq.track(3).setStartMuted();

    return seq;
}

Sequence TogetherSequenceFactory::togetherKick()
{
    return buildSequence(
        8, 4, 0, "Kick", 130, true,
        {
            TogetherTrackFactory::togetherArp,
            TogetherTrackFactory::togetherHiDrum,
            TogetherTrackFactory::togetherSample,
            TogetherTrackFactory::togetherDX7,
            SequenceTrackFactory::kickFour
        });
}

Sequence TogetherSequenceFactory::togetherVocoder()
{
    Sequence seq = buildSequence(
        16, 4, 16, "Vocoder", 130, false,
        {
            TogetherTrackFactory::togetherArp,
            TogetherTrackFactory::togetherHiDrum,
            TogetherTrackFactory::togetherSample,
            TogetherTrackFactory::togetherDX7,
            SequenceTrackFactory::kickFour,
            TogetherTrackFactory::togetherVocoder,
        });

    seq.track(2).addControlChange(0, 13, 68);
    return seq;
}

Sequence TogetherSequenceFactory::togetherPause()
{
    return buildSequence(
        8, 4, 0, "Pause", 130, true,
        {
            TogetherTrackFactory::togetherArp,
            TogetherTrackFactory::togetherHatsOnly,
            TogetherTrackFactory::togetherSample,
            TogetherTrackFactory::togetherDX7,
        });
}

Sequence TogetherSequenceFactory::togetherClimax()
{
    Sequence seq = buildSequence(
        8, 4, 0, "Climax", 130, false,
        {
            TogetherTrackFactory::togetherArp,
            TogetherTrackFactory::togetherHiDrum,
            TogetherTrackFactory::togetherSample,
            TogetherTrackFactory::togetherDX7,
            SequenceTrackFactory::kickFour,
        });

    seq.track(2).addControlChange(0, 13, 127);
    return seq;
}

Sequence TogetherSequenceFactory::togetherRepeat()
{
    return buildSequence(
        4, 4, 0, "Climax", 130, false,
        {
            TogetherTrackFactory::togetherArp,
            TogetherTrackFactory::togetherHatsOnly,
            TogetherTrackFactory::togetherSampleRepeat,
            TogetherTrackFactory::togetherDX7,
            TogetherTrackFactory::togetherKickRepeat,
            TogetherTrackFactory::togetherExtraBass,
            TogetherTrackFactory::togetherEndRiser
        });
}

Sequence TogetherSequenceFactory::togetherPartB()
{
    Sequence seq = buildSequence(
        8, 4, 0, "Part B", 130, true,
        {
            TogetherTrackFactory::togetherPartBSampleCut,
            TogetherTrackFactory::togetherPartBSynth,
            TogetherTrackFactory::togetherPartBAh,
            TogetherTrackFactory::togetherPartBDaDaDa,
        });

    seq.track(2).setStartMuted();
    seq.track(3).setStartMuted();

    return seq;
}

Sequence TogetherSequenceFactory::togetherPartBWithHats()
{
    return buildSequence(
        16, 4, 0, "Part B Hats", 130, false,
        {
            TogetherTrackFactory::togetherPartBSampleCut,
            TogetherTrackFactory::togetherPartBSynth,
            TogetherTrackFactory::togetherPartBAh,
            TogetherTrackFactory::togetherPartBDaDaDa,
            TogetherTrackFactory::togetherHatsOnly
        });
}

Sequence TogetherSequenceFactory::togetherPartBDrums()
{
    Sequence seq = buildSequence(
        8, 4, 0, "Part B Drums", 130, true,
        {
            TogetherTrackFactory::togetherPartBSynth,
            TogetherTrackFactory::togetherPartBAh,
            TogetherTrackFactory::togetherHiDrum,
            SequenceTrackFactory::kickFour,
            TogetherTrackFactory::togetherPartBJC,
            TogetherTrackFactory::togetherPartBTambourin
        });

    seq.track(4).setStartMuted();
    seq.track(5).setStartMuted();

    return seq;
}

Sequence TogetherSequenceFactory::togetherPartBClimax()
{
    Sequence seq = buildSequence(
        8, 4, 0, "Part B Climax", 130, true,
        {
            TogetherTrackFactory::togetherPartBSynth,
            TogetherTrackFactory::togetherPartBAh,
            TogetherTrackFactory::togetherHiDrum,
            SequenceTrackFactory::kickFour,
            TogetherTrackFactory::togetherPartBJC,
            TogetherTrackFactory::togetherPartBTambourin,
            TogetherTrackFactory::togetherPartBCymbal,
            TogetherTrackFactory::togetherEndRiser
        });

    seq.track(7).addMuteEvent(0);
    return seq;
}

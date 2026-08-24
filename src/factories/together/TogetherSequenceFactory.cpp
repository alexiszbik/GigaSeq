#include "TogetherSequenceFactory.h"

#include "factories/SequenceBuilder.h"
#include "factories/SequenceTrackFactory.h"
#include "factories/together/TogetherTrackFactory.h"
#include "MidiConst.h"

namespace {
constexpr uint8_t songTempo = 130;
}

Sequence TogetherSequenceFactory::togetherIntro()
{
    Sequence seq = buildSequence(
        8, 4, 0, "Intro", songTempo, true,
        {
            TogetherTrackFactory::togetherArp,
            track(SequenceTrackFactory::gtrPedal).withProgramChange(HXStomp::kBass)
        });

    addProgramChangeTrack(seq, "Poly pgm", MidiChannel::kPoly, 1);
    return seq;
}

Sequence TogetherSequenceFactory::togetherSample()
{
    return buildSequence(
        8, 4, 0, "Sample", songTempo, true,
        {
            TogetherTrackFactory::togetherArp,
            TogetherTrackFactory::togetherHiDrum,
            track(TogetherTrackFactory::togetherSample).muted(),
            track(TogetherTrackFactory::togetherDX7).muted(),
        });
}

Sequence TogetherSequenceFactory::togetherKick()
{
    return buildSequence(
        8, 4, 0, "Kick", songTempo, true,
        {
            TogetherTrackFactory::togetherArp,
            TogetherTrackFactory::togetherHiDrum,
            track(TogetherTrackFactory::togetherSample).withCC(13, 127),
            TogetherTrackFactory::togetherDX7,
            SequenceTrackFactory::kickFour,
        });
}

Sequence TogetherSequenceFactory::togetherVocoder()
{
    return buildSequence(
        16, 4, 16, "Vocoder", songTempo, false,
        {
            TogetherTrackFactory::togetherArp,
            TogetherTrackFactory::togetherHiDrum,
            track(TogetherTrackFactory::togetherSample).withCC(13, 63),
            TogetherTrackFactory::togetherDX7,
            SequenceTrackFactory::kickFour,
            TogetherTrackFactory::togetherVocoder,
            track(SequenceTrackFactory::gtrPedal).withProgramChange(HXStomp::kTogetherChorus)
            .withCC(HXStomp::kTogetherChorus_ccVolume, 0)
        });
}

Sequence TogetherSequenceFactory::togetherPause()
{
    return buildSequence(
        8, 4, 0, "Pause", songTempo, true,
        {
            TogetherTrackFactory::togetherArp,
            TogetherTrackFactory::togetherHatsOnly,
            TogetherTrackFactory::togetherSample,
            TogetherTrackFactory::togetherDX7,
            track(SequenceTrackFactory::gtrPedal).withCC(HXStomp::kTogetherChorus_ccVolume, 127)
        });
}

Sequence TogetherSequenceFactory::togetherClimax()
{
    return buildSequence(
        16, 4, 0, "Climax", songTempo, false,
        {
            TogetherTrackFactory::togetherArp,
            TogetherTrackFactory::togetherHiDrum,
            track(TogetherTrackFactory::togetherSample).withCC(13, 127),
            TogetherTrackFactory::togetherDX7,
            SequenceTrackFactory::kickFour,
            track(SequenceTrackFactory::gtrPedal).withCC(HXStomp::kTogetherChorus_ccDrive, 127)
        });
}

Sequence TogetherSequenceFactory::togetherRepeat()
{
    return buildSequence(
        4, 4, 0, "Repeat", songTempo, false,
        {
            TogetherTrackFactory::togetherArp,
            TogetherTrackFactory::togetherHatsOnly,
            TogetherTrackFactory::togetherSampleRepeat,
            TogetherTrackFactory::togetherDX7,
            TogetherTrackFactory::togetherKickRepeat,
            TogetherTrackFactory::togetherExtraBass,
            TogetherTrackFactory::togetherEndRiser,
        });
}

Sequence TogetherSequenceFactory::togetherPartB()
{
    return buildSequence(
        8, 4, 0, "PartB", 130, true,
        {
            TogetherTrackFactory::togetherPartBSampleCut,
            TogetherTrackFactory::togetherPartBSynth,
            track(TogetherTrackFactory::togetherPartBAh).muted(),
            track(TogetherTrackFactory::togetherPartBDaDaDa).muted(),
        });
}

Sequence TogetherSequenceFactory::togetherPartBWithHats()
{
    return buildSequence(
        16, 4, 0, "PartBHats", songTempo, false,
        {
            TogetherTrackFactory::togetherPartBSampleCut,
            TogetherTrackFactory::togetherPartBSynth,
            TogetherTrackFactory::togetherPartBAh,
            TogetherTrackFactory::togetherPartBDaDaDa,
            TogetherTrackFactory::togetherHatsOnly,
        });
}

Sequence TogetherSequenceFactory::togetherPartBDrums()
{
    return buildSequence(
        8, 4, 0, "PartBDrums", songTempo, true,
        {
            TogetherTrackFactory::togetherPartBSynth,
            TogetherTrackFactory::togetherPartBAh,
            TogetherTrackFactory::togetherHiDrum,
            SequenceTrackFactory::kickFour,
            track(TogetherTrackFactory::togetherPartBJC).muted(),
            track(TogetherTrackFactory::togetherPartBTambourin).muted(),
        });
}

Sequence TogetherSequenceFactory::togetherPartBClimax()
{
    return buildSequence(
        8, 4, 0, "PartBClimax", songTempo, true,
        {
            TogetherTrackFactory::togetherPartBSynth,
            TogetherTrackFactory::togetherPartBAh,
            TogetherTrackFactory::togetherHiDrum,
            SequenceTrackFactory::kickFour,
            TogetherTrackFactory::togetherPartBJC,
            TogetherTrackFactory::togetherPartBTambourin,
            TogetherTrackFactory::togetherPartBCymbal,
            track(TogetherTrackFactory::togetherEndRiser).withMuteEvent(0).asFill(),
        });
}

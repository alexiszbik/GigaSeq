#include "TogetherSequenceFactory.h"

#include "factories/SequenceBuilder.h"
#include "factories/SequenceTrackFactory.h"
#include "factories/together/TogetherTrackFactory.h"
#include "factories/together/TogetherSamples.h"
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
            track(SequenceTrackFactory::gtrPedal).withProgramChange(HXStomp::kBass),
            track(SequenceTrackFactory::gtrLoop).withProgramChange(BossRC::kTogetherA),
            track(SequenceTrackFactory::microfreak).withProgramChange(Microfreak::kTogetherLead),
            track(SequenceTrackFactory::midiLoop)
                .withNote(MidiLoop::kSelectMicrofreak)
                .withCC(MidiLoop::kBarCount_cc, 4),
            track(SequenceTrackFactory::matrix).withProgramChange(LedMatrix::kKill)
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
            track(SequenceTrackFactory::midiLoop).withCC(MidiLoop::kRecord_cc, ON),
            track(SequenceTrackFactory::polySynth).withProgramChange(PolySynth::kTogetherChords),
            track(SequenceTrackFactory::vocoder)
                .withCC(Vocoder::kPlayMode_cc, 127)
                .withCC(Vocoder::kGlide_cc, 0)
                .withCC(Vocoder::kRelease_cc, 42)
                .withCC(Vocoder::kOscMix_cc, 89)
                .withCC(Vocoder::kOscAWaveform_cc, 127)
                .withCC(Vocoder::kOscBWaveform_cc, 0)
                .withCC(Vocoder::kOscAPwm_cc, 64)
                .withCC(Vocoder::kOscBPwm_cc, 64),

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
            track(SequenceTrackFactory::matrix).withProgramChange(LedMatrix::kTogether_vuIntro),
            track(TogetherTrackFactory::togetherLedBlinkBlue).withCC(LedStrips::kDecay_cc, 30),
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
            track(SequenceTrackFactory::gtrPedal)
                .withProgramChange(HXStomp::kTogetherChorus)
                .withCC(HXStomp::kTogetherChorus_ccVolume, 0, TICK(0,1)),
            track(SequenceTrackFactory::microfreak).withProgramChange(Microfreak::kWaterBass),
            track(SequenceTrackFactory::midiLoop).withNote(MidiLoop::kEraseAll)
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
            track(SequenceTrackFactory::gtrPedal).withCC(HXStomp::kTogetherChorus_ccVolume, 127),
            SequenceTrackFactory::gtrLoopMute,
            track(SequenceTrackFactory::matrix).withProgramChange(LedMatrix::kTogether_circles),
            track(SequenceTrackFactory::ledStrips).withNote(LedStrips::kBlue_ALL, 127, 0, TICK(8))
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
            track(SequenceTrackFactory::gtrPedal).withCC(HXStomp::kTogetherChorus_ccDrive, 127),
            SequenceTrackFactory::gtrLoopUnmute,
            track(SequenceTrackFactory::matrix).withProgramChange(LedMatrix::kTogether_vuRainbow),
            track(SequenceTrackFactory::ledStrips)
                .withNote(LedStrips::kRainbow_note, 127, 0, TICK(16))
                .withCC(LedStrips::kRainbowSpeed_cc, 14),
            track(SequenceTrackFactory::drumMachine)
                .withNote(Together::tgtAh)
                .withCC(DrumMachine::kPerformMode_cc, OFF)
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
            SequenceTrackFactory::gtrLoopErase,
            track(SequenceTrackFactory::ledStrips)
                .withNote(LedStrips::kRainbow_note, 127, 0, TICK(4))
                .withCC(LedStrips::kRainbowSpeed_cc, 2)
                .withCC(LedStrips::kDecay_cc, 0)
        });
}

Sequence TogetherSequenceFactory::togetherPartB()
{
    return buildSequence(
        16, 4, 8, "PartB", 130, true,
        {
            TogetherTrackFactory::togetherPartBSampleCut,
            TogetherTrackFactory::togetherPartBSynth,
            //track(TogetherTrackFactory::togetherPartBAh).muted(),
            track(TogetherTrackFactory::togetherPartBDaDaDa).muted(),
            track(SequenceTrackFactory::gtrPedal)
                .withCC(HXStomp::kTogetherChorus_ccDrive, 0)
                .withProgramChange(HXStomp::kTogetherEnd, TICK(5)),
            track(SequenceTrackFactory::gtrLoop).withProgramChange(BossRC::kTogetherB, TICK(5)),
            track(SequenceTrackFactory::midiLoop)
                .withNote(MidiLoop::kSelectBass)
                .withCC(MidiLoop::kBarCount_cc, 4),
            track(SequenceTrackFactory::matrix).withProgramChange(LedMatrix::kKill)
        });
}

Sequence TogetherSequenceFactory::togetherPartBWithHats()
{
    return buildSequence(
        16, 4, 0, "PartBHats", songTempo, false,
        {
            TogetherTrackFactory::togetherPartBSampleCut,
            TogetherTrackFactory::togetherPartBSynth,
            //TogetherTrackFactory::togetherPartBAh,
            TogetherTrackFactory::togetherPartBDaDaDa,
            TogetherTrackFactory::togetherHatsOnly,
            track(TogetherTrackFactory::togetherBassLed).withCC(LedStrips::kDecay_cc, 80)
        });
}

Sequence TogetherSequenceFactory::togetherPartBDrums()
{
    return buildSequence(
        16, 4, 8, "PartBDrums", songTempo, true,
        {
            TogetherTrackFactory::togetherPartBSynth,
            //TogetherTrackFactory::togetherPartBAh,
            TogetherTrackFactory::togetherHiDrum,
            SequenceTrackFactory::kickFour,
            track(TogetherTrackFactory::togetherPartBJC).muted(),
            track(TogetherTrackFactory::togetherPartBTambourin).muted(),
            track(SequenceTrackFactory::polySynth).withCC(PolySynth::kFilterCutoff_cc, 3)
        });
}

Sequence TogetherSequenceFactory::togetherPartBClimax()
{
    return buildSequence(
        8, 4, 0, "PartBClimax", songTempo, true,
        {
            TogetherTrackFactory::togetherPartBSynth,
            //TogetherTrackFactory::togetherPartBAh,
            TogetherTrackFactory::togetherHiDrum,
            SequenceTrackFactory::kickFour,
            TogetherTrackFactory::togetherPartBJC,
            TogetherTrackFactory::togetherPartBTambourin,
            TogetherTrackFactory::togetherPartBCymbal,
            track(TogetherTrackFactory::togetherEndRiser).withMuteEvent(0).asFill(),
            track(TogetherTrackFactory::togetherLedBlinkClimax).withCC(LedStrips::kDecay_cc, 44)
        });
}

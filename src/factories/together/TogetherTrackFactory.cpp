#include "TogetherTrackFactory.h"

#include "factories/SequenceTrackFactory.h"
#include "factories/together/TogetherPatterns.h"
#include "factories/TrackPatternBuilder.h"
#include "MidiChannel.h"
#include "factories/MidiNotes.h"

namespace
{
constexpr tick_t oneBarTick = 384;

}

SequenceTrack TogetherTrackFactory::togetherArp(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("Modular", MidiChannel::kModularA);
    track.setPattern(TogetherPatterns::kTogetherArp, lengthInTicks, startInTicks);
    return track;
}

SequenceTrack TogetherTrackFactory::togetherHiDrum(tick_t lengthInTicks, tick_t startInTicks)
{
    SequenceTrack track("Hi Drum", MidiChannel::kDrums);
    track.setPattern(TogetherPatterns::kTogetherHiDrum, lengthInTicks, startInTicks);
    return track;
}

SequenceTrack TogetherTrackFactory::togetherSample(tick_t lengthInTicks, tick_t startInTicks)
{
    SequenceTrack track("Sample", MidiChannel::kSampler);
    track.setPattern(TogetherPatterns::kTogetherSample, lengthInTicks, startInTicks);
    return track;
}

SequenceTrack TogetherTrackFactory::togetherDX7(tick_t lengthInTicks, tick_t startInTicks)
{
    SequenceTrack track("DX7", MidiChannel::kSampler);
    track.setPattern(TogetherPatterns::kTogetherDX7, lengthInTicks, startInTicks);
    return track;
}

SequenceTrack TogetherTrackFactory::togetherVocoder(tick_t lengthInTicks, tick_t startInTicks)
{
    SequenceTrack track("Vocoder", MidiChannel::kVocoder);

    SequenceDesc desc;
    desc.notes = {
        {C3, Eb3, Bb3}, {}, {}, {C3, Eb3, Ab3}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, 
        {C3, Eb3, Bb3}, {}, {}, {C3, Eb3, Ab3}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {},
        {C3, Eb3, Ab3}, {}, {}, {C3, Eb3, G3},  {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {},
        {Bb2, Eb3, F3}, {}, {}, {C3, Eb3, G3},  {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}
    };
    desc.rate = 8;
    desc.durations = {3, 11};
    
    makeSequenceTrack(track, desc, oneBarTick*16, startInTicks);

    return track;
}

SequenceTrack TogetherTrackFactory::togetherSampleRepeat(tick_t lengthInTicks, tick_t startInTicks)
{
    SequenceTrack track("Sample", MidiChannel::kSampler);

    SequenceDesc desc;
    desc.notes = {{52}};
    desc.rate = 4;
    makeSequenceTrack(track, desc, 3*oneBarTick, startInTicks);

    desc.rate = 8;
    makeSequenceTrack(track, desc, oneBarTick, startInTicks + 3*oneBarTick);

    return track;
}

SequenceTrack TogetherTrackFactory::togetherPartBSampleCut(tick_t lengthInTicks, tick_t startInTicks)
{
    SequenceTrack track("Sample Cut", MidiChannel::kDrums);
    track.addNote(startInTicks, 24, 54, 127);

    return track;
}

SequenceTrack TogetherTrackFactory::togetherKickRepeat(tick_t lengthInTicks, tick_t startInTicks)
{
    auto track = SequenceTrackFactory::kickFour(3*oneBarTick, startInTicks);

    SequenceDesc desc;
    desc.notes = {{36, 37}};
    desc.rate = 8;
    makeSequenceTrack(track, desc, oneBarTick, startInTicks + 3*oneBarTick);

    return track;
}

SequenceTrack TogetherTrackFactory::togetherExtraBass(tick_t lengthInTicks, tick_t startInTicks)
{
    SequenceTrack track("Extra Bass", MidiChannel::kDrums);

    SequenceDesc desc;
    desc.notes = {{57}};
    desc.rate = 4;
    makeSequenceTrack(track, desc, 4*oneBarTick, startInTicks);

    return track;
}

SequenceTrack TogetherTrackFactory::togetherEndRiser(tick_t lengthInTicks, tick_t startInTicks)
{
    SequenceTrack track("Riser", MidiChannel::kDrums);
    tick_t riserLength = 2*oneBarTick;
    track.addNote(startInTicks + lengthInTicks - riserLength, riserLength, 60, 127);

    return track;
}

SequenceTrack TogetherTrackFactory::togetherPartBSynth(tick_t lengthInTicks, tick_t startInTicks)
{
    SequenceTrack track("Poly Synth", MidiChannel::kPoly);
    track.setPattern(TogetherPatterns::kTogetherPartBSynth, lengthInTicks, startInTicks);
    return track;
}

SequenceTrack TogetherTrackFactory::togetherPartBAh(tick_t lengthInTicks, tick_t startInTicks)
{
    SequenceTrack track("Ah", MidiChannel::kSampler);
    track.setPattern(TogetherPatterns::kTogetherPartBAh, lengthInTicks, startInTicks);
    return track;
}

SequenceTrack TogetherTrackFactory::togetherPartBDaDaDa(tick_t lengthInTicks, tick_t startInTicks)
{
    SequenceTrack track("DaDaDa", MidiChannel::kDrums);
    track.setPattern(TogetherPatterns::kTogetherPartBDaDaDa, lengthInTicks, startInTicks);
    return track;
}

SequenceTrack TogetherTrackFactory::togetherHatsOnly(tick_t lengthInTicks, tick_t startInTicks)
{
    SequenceTrack track("Hats", MidiChannel::kDrums);
    track.setPattern(TogetherPatterns::kTogetherHatsOnly, lengthInTicks, startInTicks);
    return track;
}


SequenceTrack TogetherTrackFactory::togetherPartBJC(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("JC", MidiChannel::kDrums);

    SequenceDesc desc;
    desc.notes = {
        {}, {}, {45}, {}, {}, {}, {}, {46}, 
        {}, {}, {}, {}, {}, {}, {44}, {},
        {}, {}, {45}, {}, {}, {}, {}, {47}, 
        {}, {}, {}, {}, {}, {}, {44}, {},
    };
    desc.rate = 8;
    makeSequenceTrack(track, desc, lengthInTicks, startInTicks);

    return track;
}

SequenceTrack TogetherTrackFactory::togetherPartBTambourin(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("Tambourin", MidiChannel::kSampler);
    track.setPattern(TogetherPatterns::kTogetherPartBTambourin, lengthInTicks, startInTicks);
    return track;
}

SequenceTrack TogetherTrackFactory::togetherPartBCymbal(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("Cymbal", MidiChannel::kSampler);
    track.setPattern(TogetherPatterns::kTogetherPartBCymbal, lengthInTicks, startInTicks);
    return track;
}

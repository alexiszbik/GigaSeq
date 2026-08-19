#include "TogetherTrackFactory.h"

#include "factories/SequenceTrackFactory.h"
#include "factories/TrackPatternBuilder.h"
#include "MidiChannel.h"
#include "factories/MidiNotes.h"

namespace
{
constexpr tick_t oneBarTick = 384;
} // namespace

SequenceTrack TogetherTrackFactory::togetherArp(tick_t lengthInTicks) {
    SequenceTrack track("Modular", MidiChannel::kModularA);

    SequenceDesc desc;
    desc.notes = {
        {Gd4}, {Gd3}, {Gd2}, {Gd3}, {Gd4}, {Gd3}, {Gd2}, {Gd3}, {Gd4}, {Gd3}, {Gd2}, {Gd3}, {Gd4}, {Gd3}, {Gd2}, {Gd3},
        {Gd4}, {Gd3}, {Gd2}, {Gd3}, {Gd4}, {Gd3}, {Gd2}, {Gd3}, {Gd4}, {Gd3}, {Gd2}, {Gd3}, {Gd4}, {Gd3}, {Gd2}, {Gd3},
        {Gd4}, {Gd3}, {Gd2}, {Gd3}, {Gd4}, {Gd3}, {Gd2}, {Gd3}, {Gd4}, {Gd3}, {Gd2}, {Gd3}, {Gd4}, {Gd3}, {Gd2}, {Gd3},
        {Gd4}, {Gd3}, {Gd2}, {Gd3}, {Gd4}, {Gd3}, {Gd2}, {Gd3}, {Gd4}, {Gd3}, {Gd2}, {Gd3}, {Gd4}, {Gd3}, {Gd2}, {Gd3},
        {C4}, {C3}, {C2}, {C3}, {C4}, {C3}, {C2}, {C3}, {C4}, {C3}, {C2}, {C3}, {C4}, {C3}, {C2}, {C3}, 
        {C4}, {C3}, {C2}, {C3}, {C4}, {C3}, {C2}, {C3}, {C4}, {C3}, {C2}, {C3}, {C4}, {C3}, {C2}, {C3}, 
        {C4}, {C3}, {C2}, {C3}, {C4}, {C3}, {C2}, {C3}, {C4}, {C3}, {C2}, {C3}, {C4}, {C3}, {C2}, {C3}, 
        {C4}, {C3}, {C2}, {C3}, {C4}, {C3}, {C2}, {C3}, {C4}, {C3}, {C2}, {C3}, {C4}, {C3}, {C2}, {C3}
    };
    desc.rate = 16;
    makeSequenceTrack(track, desc, lengthInTicks);

    return track;
}

SequenceTrack TogetherTrackFactory::togetherHiDrum(tick_t lengthInTicks)
{
    SequenceTrack track("Hi Drum", MidiChannel::kDrums);

    SequenceDesc desc;
    desc.notes = {{56}};
    desc.rate = 2;
    makeSequenceTrack(track, desc, lengthInTicks);

    desc.notes = {{37}};
    desc.rate = 4;
    makeSequenceTrack(track, desc, lengthInTicks);

    desc.notes = {{}, {38}};
    desc.rate = 4;
    makeSequenceTrack(track, desc, lengthInTicks);

    desc.notes = {{40}};
    desc.velocities = {127, 56};
    desc.rate = 8;
    makeSequenceTrack(track, desc, lengthInTicks);

    return track;
}

SequenceTrack TogetherTrackFactory::togetherSample(tick_t lengthInTicks)
{
    SequenceTrack track("Sample", MidiChannel::kSampler);

    SequenceDesc desc;
    desc.notes = {{52}, {52}, {53}, {53}};
    desc.rate = 0.5;
    makeSequenceTrack(track, desc, lengthInTicks);

    return track;
}

SequenceTrack TogetherTrackFactory::togetherDX7(tick_t lengthInTicks)
{
    SequenceTrack track("DX7", MidiChannel::kSampler);

    SequenceDesc desc;
    desc.notes = {
        {58}, {58}, {58}, {58}, {58}, {58}, {58}, {58},
        {58}, {58}, {58}, {58}, {58}, {58}, {58}, {58},
        {58}, {58}, {58}, {58}, {58}, {58}, {58}, {58},
        {58}, {58}, {58}, {58}, {58}, {58}, {58}, {58},
        {59}, {59}, {59}, {59}, {59}, {59}, {59}, {59},
        {59}, {59}, {59}, {59}, {59}, {59}, {59}, {59},
        {59}, {59}, {59}, {59}, {59}, {59}, {59}, {59},
        {59}, {59}, {59}, {59}, {59}, {59}, {59}, {59},
    };
    desc.rate = 8;
    makeSequenceTrack(track, desc, lengthInTicks);

    return track;
}

SequenceTrack TogetherTrackFactory::togetherVocoder(tick_t lengthInTicks)
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
    
    makeSequenceTrack(track, desc, oneBarTick*16);

    return track;
}

SequenceTrack TogetherTrackFactory::togetherSampleRepeat(tick_t lengthInTicks)
{
    SequenceTrack track("Sample", MidiChannel::kSampler);

    SequenceDesc desc;
    desc.notes = {{52}};
    desc.rate = 4;
    makeSequenceTrack(track, desc, 3*oneBarTick);

    desc.rate = 8;
    makeSequenceTrack(track, desc, oneBarTick, 3*oneBarTick);

    return track;
}

SequenceTrack TogetherTrackFactory::togetherPartBSampleCut(tick_t lengthInTicks)
{
    SequenceTrack track("Sample Cut", MidiChannel::kDrums);
    track.addNote(0, 24, 54, 127);

    return track;
}

SequenceTrack TogetherTrackFactory::togetherKickRepeat(tick_t lengthInTicks)
{
    auto track = SequenceTrackFactory::kickFour(3*oneBarTick);

    SequenceDesc desc;
    desc.notes = {{36, 37}};
    desc.rate = 8;
    makeSequenceTrack(track, desc, oneBarTick, 3*oneBarTick);

    return track;
}

SequenceTrack TogetherTrackFactory::togetherExtraBass(tick_t lengthInTicks)
{
    SequenceTrack track("Extra Bass", MidiChannel::kDrums);

    SequenceDesc desc;
    desc.notes = {{57}};
    desc.rate = 4;
    makeSequenceTrack(track, desc, 4*oneBarTick);

    return track;
}

SequenceTrack TogetherTrackFactory::togetherEndRiser(tick_t lengthInTicks)
{
    SequenceTrack track("Riser", MidiChannel::kDrums);
    tick_t riserLength = 2*oneBarTick;
    track.addNote(lengthInTicks - riserLength, riserLength, 60, 127);

    return track;
}

SequenceTrack TogetherTrackFactory::togetherPartBSynth(tick_t lengthInTicks)
{   
    SequenceTrack track("Poly Synth", MidiChannel::kPoly);

    SequenceDesc desc;
    desc.notes = {
        {Ab2, C4, Eb4, Bb4}, {}, {}, {Ab2, C4, Eb4, Ab4}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, 
        {G2, B3, D4, Bb4}, {}, {}, {G2, B3, D4, G4}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {},
        {Bb2, Bb3, D4, F4}, {}, {}, {Bb2, Bb3, D4, G4},  {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {},
        {C3, C4, Eb4, Ab4}, {}, {}, {C3, C4, Eb4, G4},  {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}
    };
    desc.rate = 8;
    desc.durations = {2, 9};
    
    makeSequenceTrack(track, desc, lengthInTicks);

    return track;
}

SequenceTrack TogetherTrackFactory::togetherPartBAh(tick_t lengthInTicks)
{
    SequenceTrack track("Ah", MidiChannel::kSampler);

    SequenceDesc desc;
    desc.notes = {{39}};
    desc.rate = 4;
    makeSequenceTrack(track, desc, lengthInTicks);

    return track;
}

SequenceTrack TogetherTrackFactory::togetherPartBDaDaDa(tick_t lengthInTicks)
{
    SequenceTrack track("DaDaDa", MidiChannel::kDrums);

    SequenceDesc desc;
    desc.notes = {{41}, {42}, {43}, {42}, {41}, {42}, {43}, {43}};
    desc.rate = 8;
    makeSequenceTrack(track, desc, lengthInTicks);

    return track;
}

SequenceTrack TogetherTrackFactory::togetherHatsOnly(tick_t lengthInTicks)
{
    SequenceTrack track("Hats", MidiChannel::kDrums);

    SequenceDesc desc;
    desc.notes = {{40}};
    desc.velocities = {127, 56};
    desc.rate = 8;
    makeSequenceTrack(track, desc, lengthInTicks);

    return track;
}


SequenceTrack TogetherTrackFactory::togetherPartBJC(tick_t lengthInTicks) {
    SequenceTrack track("JC", MidiChannel::kDrums);

    SequenceDesc desc;
    desc.notes = {
        {}, {}, {45}, {}, {}, {}, {}, {46}, 
        {}, {}, {}, {}, {}, {}, {44}, {},
        {}, {}, {45}, {}, {}, {}, {}, {47}, 
        {}, {}, {}, {}, {}, {}, {44}, {},
    };
    desc.rate = 8;
    makeSequenceTrack(track, desc, lengthInTicks);

    return track;
}

SequenceTrack TogetherTrackFactory::togetherPartBTambourin(tick_t lengthInTicks) {
    SequenceTrack track("Tambourin", MidiChannel::kSampler);

    SequenceDesc desc;
    desc.notes = {{48, 50}};
    desc.rate = 4;
    makeSequenceTrack(track, desc, lengthInTicks);

    return track;
}
SequenceTrack TogetherTrackFactory::togetherPartBCymbal(tick_t lengthInTicks) {
    SequenceTrack track("Cymbal", MidiChannel::kSampler);

    SequenceDesc desc;
    desc.notes = {{51}};
    desc.velocities = {127, 56};
    desc.rate = 8;
    makeSequenceTrack(track, desc, lengthInTicks);

    return track;
}

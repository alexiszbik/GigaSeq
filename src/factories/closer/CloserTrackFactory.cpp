#include "CloserTrackFactory.h"

#include "factories/TrackPatternBuilder.h"
#include "factories/closer/CloserPatterns.h"
#include "MidiChannel.h"

SequenceTrack CloserTrackFactory::closerHats(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("Hats", MidiChannel::kSampler);
    track.setPattern(CloserPatterns::kCloserHat, lengthInTicks, startInTicks);
    return track;
}

SequenceTrack CloserTrackFactory::closerLoopHat(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("LoopHat", MidiChannel::kDrums);
    track.setPattern(CloserPatterns::kCloserLoopHat, lengthInTicks, startInTicks);
    return track;
}

SequenceTrack CloserTrackFactory::closerTambourin(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("Tambourin", MidiChannel::kSampler);
    track.setPattern(CloserPatterns::kCloserTambourin, lengthInTicks, startInTicks);
    return track;
}

SequenceTrack CloserTrackFactory::closerClapTom(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("ClapTom", MidiChannel::kDrums);
    track.setPattern(CloserPatterns::kCloserClapTom, lengthInTicks, startInTicks);
    return track;
}

SequenceTrack CloserTrackFactory::closerRiser(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("Riser", MidiChannel::kSampler);

    SequenceDesc desc;
    desc.notes = {{Closer::triRizstr}};
    desc.rate = 16;
    makeSequenceTrack(track, desc, lengthInTicks - TickHelper::bars(2) , startInTicks);

    return track;
}

SequenceTrack CloserTrackFactory::closerModular(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("Modular", MidiChannel::kModularA);
    track.setPattern(CloserPatterns::kCloserModular, lengthInTicks, startInTicks);
    return track;
}

SequenceTrack CloserTrackFactory::closerStab(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("Stab", MidiChannel::kPoly);

    SequenceDesc desc;
    desc.notes = {
        {}, {}, {}, {},
        {}, {}, {}, {},
        {}, {}, {}, {},
        {}, {}, {}, {},

        {}, {}, {}, {},
        {}, {}, {}, {},
        {}, {}, {}, {},
        {}, {}, {}, {},

        {}, {}, {}, {},
        {}, {}, {}, {},
        {}, {}, {}, {},
        {}, {}, {}, {},

        {}, {}, {}, {},
        {}, {}, {}, {},
        {}, {}, {}, {},
        {}, {}, {}, {Cd3, E3, Gd3, B3}
    };
    desc.rate = 16;
    makeSequenceTrack(track, desc, lengthInTicks, startInTicks);

    return track;
}

SequenceTrack CloserTrackFactory::closerFill808(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("Fill808", MidiChannel::kDrums);

    uint8_t snr = Closer::sd1050;

    tick_t fillStart = lengthInTicks - TickHelper::bars(2);

    tick_t grooveLen = TICK(1,2);

    SequenceDesc desc;
    desc.notes = {{snr}};
    desc.rate = 16;
    desc.groove = 10;
    makeSequenceTrack(track, desc, grooveLen, fillStart);

    SequenceDesc descTri;
    descTri.notes = {{snr}};
    descTri.rate = 24;
    makeSequenceTrack(track, descTri, TICK(0,2), fillStart + grooveLen);

    return track;
}

SequenceTrack CloserTrackFactory::closerChords(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("Chords", MidiChannel::kMicrofreak);
    track.setPattern(CloserPatterns::kCloserChords, lengthInTicks, startInTicks);
    return track;
}

SequenceTrack CloserTrackFactory::closerSing(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("Sing", MidiChannel::kSampler);
    track.setPattern(CloserPatterns::kCloserSing, lengthInTicks, startInTicks);
    return track;
}

SequenceTrack CloserTrackFactory::closerTop(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("Top", MidiChannel::kSampler);
    track.setPattern(CloserPatterns::kCloserTop, lengthInTicks, startInTicks);
    return track;
}

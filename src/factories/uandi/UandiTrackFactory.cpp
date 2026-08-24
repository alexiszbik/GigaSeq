#include "UandiTrackFactory.h"

#include "UandiSamples.h"
#include "factories/uandi/UandiPatterns.h"
#include "factories/TrackPatternBuilder.h"
#include "MidiChannel.h"

SequenceTrack UandiTrackFactory::uandiWavetableA(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("WavetableA", MidiChannel::kSampler);
    addSingleNote(track, Uandi::uaiWt1, TickHelper::kTicksPerEighthNote);
    return track;
}

SequenceTrack UandiTrackFactory::uandiWavetableB(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("WavetableB", MidiChannel::kSampler);
    addSingleNote(track, Uandi::uaiWt2, TickHelper::kTicksPerEighthNote);
    return track;
}

SequenceTrack UandiTrackFactory::uandiHatLoop(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("HatLoop", MidiChannel::kSampler);
    addSingleNote(track, Uandi::uaiHat);
    addSingleNote(track, Uandi::uaiHat, TICK(4));
    return track;
}

SequenceTrack UandiTrackFactory::uandiWant(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("Want", MidiChannel::kSampler);
    addSingleNote(track, Uandi::uaiHat, TICK(3,3));
    return track;
}

SequenceTrack UandiTrackFactory::uandiBassA(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("BassA", MidiChannel::kBass);
    track.setPattern(UandiPatterns::kUandiBassA, lengthInTicks, startInTicks);
    return track;
}

SequenceTrack UandiTrackFactory::uandiBassB(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("Bassb", MidiChannel::kBass);
    track.setPattern(UandiPatterns::kUandiBassb, lengthInTicks, startInTicks);
    return track;
}

SequenceTrack UandiTrackFactory::uandiFreak(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("Freak", MidiChannel::kMicrofreak);
    track.setPattern(UandiPatterns::kUandiFreak, lengthInTicks, startInTicks);
    return track;
}

SequenceTrack UandiTrackFactory::uandiRiser(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("Riser", MidiChannel::kSampler);

    SequenceDesc desc;
    desc.notes = {{C3}};
    desc.rate = 16;
    makeSequenceTrack(track, desc, lengthInTicks, startInTicks);

    return track;
}

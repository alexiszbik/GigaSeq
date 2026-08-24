#include "UandiTrackFactory.h"

#include "UandiSamples.h"
#include "factories/uandi/UandiPatterns.h"
#include "factories/TrackPatternBuilder.h"
#include "MidiConst.h"

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

SequenceTrack UandiTrackFactory::uandiWavetableAB(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("WavetableAB", MidiChannel::kSampler);

    SequenceDesc desc;
    desc.notes = {{Uandi::uaiWt1}, {}, {}, {}, {}, {}, {}, {}, {Uandi::uaiWt2}, {}, {}, {}};
    desc.rate = 1;
    makeSequenceTrack(track, desc, lengthInTicks, startInTicks + TickHelper::kTicksPerEighthNote);

    return track;
}


SequenceTrack UandiTrackFactory::uandiHatLoop(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("HatLoop", MidiChannel::kSampler);
    addSingleNote(track, Uandi::uaiHat);
    addSingleNote(track, Uandi::uaiHat, TICK(4));
    if (lengthInTicks > TICK(8)) {
        addSingleNote(track, Uandi::uaiHat, TICK(8));
    }
    return track;
}

SequenceTrack UandiTrackFactory::uandiWant(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("Want", MidiChannel::kSampler);
    addSingleNote(track, Uandi::uiWant, TICK(7,3));
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
    makeRiser(track, Uandi::uaiRiz, lengthInTicks, TICK(0,2));

    return track;
}

SequenceTrack UandiTrackFactory::uandiDiscoAB(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("DiscoA", MidiChannel::kSampler);
    track.setPattern(UandiPatterns::kUandiDiscoAB, lengthInTicks, startInTicks);
    return track;
}

SequenceTrack UandiTrackFactory::uandiDiscoB(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("DiscoB", MidiChannel::kSampler);
    track.setPattern(UandiPatterns::kUandiDiscoB, lengthInTicks, startInTicks);
    return track;
}

SequenceTrack UandiTrackFactory::uandiBassAB(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("BassAB", MidiChannel::kBass);
    track.setPattern(UandiPatterns::kUandiBassAB, lengthInTicks, startInTicks);
    return track;
}
SequenceTrack UandiTrackFactory::uandiOpenHat(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("OpenHat", MidiChannel::kDrums);
    track.setPattern(UandiPatterns::kUandiOpenHat, lengthInTicks, startInTicks);
    return track;
}

SequenceTrack UandiTrackFactory::uandiShaker(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("Shaker", MidiChannel::kDrums);
    track.setPattern(UandiPatterns::kUandiShaker, lengthInTicks, startInTicks);
    return track;
}

SequenceTrack UandiTrackFactory::uandiTomEvent(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("TomEvent", MidiChannel::kDrums);

    for (tick_t t : {TICK(3,2,1), TICK(3,2,2), TICK(3,2,3), TICK(3,3,0), TICK(3,3,2)}) {
        track.addNote(t, TickHelper::kStepLen, Uandi::uiTomverb, 127);
    }

    track.addNote(TICK(4), TickHelper::kStepLen, Uandi::uiClpverb, 127);
    return track;
}

SequenceTrack UandiTrackFactory::uandiPiano(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("Piano", MidiChannel::kSampler);
    track.addNote(TICK(11,2,2), TickHelper::kStepLen, Uandi::uiPiano, 127);

    return track;
}

SequenceTrack UandiTrackFactory::uandiRiserCrash(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("RizCrash", MidiChannel::kDrums);
    addSingleNote(track, Uandi::crash1);
    addSingleNote(track, Uandi::uaiRiz, TICK(11,2,0));
    addSingleNote(track, Uandi::crash1, TICK(12));
    addSingleNote(track, Uandi::uaiRiz, TICK(23,2,0));
    addSingleNote(track, Uandi::crash1, TICK(24));
    addSingleNote(track, Uandi::uaiRiz, TICK(35,2,0));
    return track;
}

SequenceTrack UandiTrackFactory::uandiRimFill(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("RimFill", MidiChannel::kDrums);
    track.setPattern(UandiPatterns::kUandiRimFill, TICK(11), startInTicks);
    SequenceDesc desc;
    desc.notes = {{Uandi::sst}};
    desc.rate = 32;
    makeSequenceTrack(track, desc, TickHelper::kOneBarTick4_4, startInTicks + TICK(11));
    return track;
}

SequenceTrack UandiTrackFactory::uandiExplode(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("Explode", MidiChannel::kSampler);
    addSingleNote(track, Uandi::explode, startInTicks);
    return track;
}

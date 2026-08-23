#include "FantasyTrackFactory.h"

#include "factories/TrackPatternBuilder.h"
#include "factories/fantasy/FantasyPatterns.h"
#include "MidiChannel.h"

SequenceTrack FantasyTrackFactory::fantasyArp(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("Arp", MidiChannel::kModularA);
    track.setPattern(FantasyPatterns::kFantasyArp, lengthInTicks, startInTicks);
    return track;
}

SequenceTrack FantasyTrackFactory::fantasySnare909(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("Snare909", MidiChannel::kDrums);
    track.setPattern(FantasyPatterns::kFantasySnare909, lengthInTicks, startInTicks);
    return track;
}

SequenceTrack FantasyTrackFactory::fantasySample(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("Sample", MidiChannel::kSampler);
    track.setPattern(FantasyPatterns::kFantasySample, lengthInTicks, startInTicks);
    return track;
}


SequenceTrack FantasyTrackFactory::fantasySampleFadeCut(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("SampleFade", MidiChannel::kSampler);
    track.addNote(0, TickHelper::kStepLen, Fantasy::ftsySampleFade, 127);
    track.addNote(TICK(4), TickHelper::kStepLen, Fantasy::ftsySampleCut, 127);
    return track;
}


SequenceTrack FantasyTrackFactory::fantasyDrums(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("Drums", MidiChannel::kDrums);
    track.setPattern(FantasyPatterns::kFantasyDrums, lengthInTicks, startInTicks);
    return track;
}

SequenceTrack FantasyTrackFactory::fantasyShake(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("Shake", MidiChannel::kDrums);
    track.setPattern(FantasyPatterns::kFantasyShake, lengthInTicks, startInTicks);
    return track;
}

SequenceTrack FantasyTrackFactory::fantasyChords(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("Chords", MidiChannel::kPoly);
    track.setPattern(FantasyPatterns::kFantasyChords, lengthInTicks, startInTicks);
    return track;
}

SequenceTrack FantasyTrackFactory::fantasyHiDrum(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("HiDrum", MidiChannel::kSampler);
    SequenceDesc desc;
    desc.notes = {{Fantasy::fantDrumhi}, {}};
    desc.rate = 1;
    makeSequenceTrack(track, desc, lengthInTicks, startInTicks);

    return track;
}

SequenceTrack FantasyTrackFactory::fantasyFreak(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("Freak", MidiChannel::kMicrofreak);
    track.setPattern(FantasyPatterns::kFantasyFreak, lengthInTicks, startInTicks);
    return track;
}

SequenceTrack FantasyTrackFactory::fantasyVocals(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("Vocals", MidiChannel::kSampler);
    track.setPattern(FantasyPatterns::kFantasyVocals, lengthInTicks, startInTicks);
    return track;
}

SequenceTrack FantasyTrackFactory::fantasyRiser(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("Riser", MidiChannel::kSampler);

    track.addNote(lengthInTicks - TICK(0,2), TickHelper::kStepLen, Fantasy::ftsyRiz, 127);
    return track;
}

#include "TiredTrackFactory.h"

#include "factories/tired/TiredPatterns.h"
#include "factories/TrackPatternBuilder.h"
#include "MidiChannel.h"

SequenceTrack TiredTrackFactory::tiredIntro(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("Intro", MidiChannel::kSampler);
    track.setPattern(TiredPatterns::kTiredIntro, lengthInTicks, startInTicks);
    return track;
}

SequenceTrack TiredTrackFactory::tiredHatSolo(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("HatSolo", MidiChannel::kSampler);
    track.setPattern(TiredPatterns::kTiredHatSolo, lengthInTicks, startInTicks);
    return track;
}

SequenceTrack TiredTrackFactory::tiredCongas(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("Congas", MidiChannel::kSampler);
    track.setPattern(TiredPatterns::kTiredCongas, lengthInTicks, startInTicks);
    return track;
}

SequenceTrack TiredTrackFactory::tiredRoboto(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("Roboto", MidiChannel::kSampler);
    track.setPattern(TiredPatterns::kTiredRoboto, lengthInTicks, startInTicks);
    return track;
}

SequenceTrack TiredTrackFactory::tiredHats(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("Hats", MidiChannel::kDrums);
    track.setPattern(TiredPatterns::kTiredHats, lengthInTicks, startInTicks);
    return track;
}

SequenceTrack TiredTrackFactory::tiredSync(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("Sync", MidiChannel::kSampler);
    track.setPattern(TiredPatterns::kTiredSync, lengthInTicks, startInTicks);
    return track;
}

SequenceTrack TiredTrackFactory::tiredPhazeHat(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("PhazeHat", MidiChannel::kSampler);
    track.setPattern(TiredPatterns::kTiredPhazeHat, lengthInTicks, startInTicks);
    return track;
}

SequenceTrack TiredTrackFactory::tiredUpRising(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("UpRising", MidiChannel::kSampler);
    track.addNote(TICK(8), TICK(8), Tired::up, 127);
    return track;
}

SequenceTrack TiredTrackFactory::tiredRiserA(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("RiserA", MidiChannel::kSampler);
    makeRiser(track, Tired::tired3briz, lengthInTicks, TICK(3));

    return track;
}

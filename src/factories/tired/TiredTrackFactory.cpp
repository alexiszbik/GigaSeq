#include "TiredTrackFactory.h"

#include "factories/tired/TiredPatterns.h"
#include "factories/TrackPatternBuilder.h"
#include "MidiConst.h"

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


SequenceTrack TiredTrackFactory::tiredUpRisingB(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("UpRising", MidiChannel::kSampler);
    track.addNote(0, TICK(7), Tired::up, 127);
    return track;
}

SequenceTrack TiredTrackFactory::tiredRiserA(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("RiserA", MidiChannel::kSampler);
    makeRiser(track, Tired::tired3briz, lengthInTicks, TICK(3));

    return track;
}

SequenceTrack TiredTrackFactory::tiredFreak(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("Freak", MidiChannel::kMicrofreak);
    track.setPattern(TiredPatterns::kTiredFreak, lengthInTicks, startInTicks);
    return track;
}

SequenceTrack TiredTrackFactory::tiredFreakArp(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("FreakArp", MidiChannel::kMicrofreak);
    track.setPattern(TiredPatterns::kTiredFreakArp, lengthInTicks, startInTicks);
    return track;
}

SequenceTrack TiredTrackFactory::tiredStabs(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("Stabs", MidiChannel::kPoly);
    track.setPattern(TiredPatterns::kTiredStabs, lengthInTicks, startInTicks);
    return track;
}

SequenceTrack TiredTrackFactory::tiredBass(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("Bass", MidiChannel::kBass);
    track.setPattern(TiredPatterns::kTiredBass, lengthInTicks, startInTicks);
    return track;
}

SequenceTrack TiredTrackFactory::tiredTechHats(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("TechHats", MidiChannel::kDrums);
    track.setPattern(TiredPatterns::kTiredTechHats, lengthInTicks, startInTicks);
    return track;
}

SequenceTrack TiredTrackFactory::tiredImpacts(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("Impacts", MidiChannel::kDrums);
    track.setPattern(TiredPatterns::kTiredImpacts, lengthInTicks, startInTicks);
    return track;
}

SequenceTrack TiredTrackFactory::tiredImpactsKick(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("Long Kick", MidiChannel::kDrums);
    track.setPattern(TiredPatterns::kTiredKickImpacts, lengthInTicks, startInTicks);
    return track;
}

SequenceTrack TiredTrackFactory::tiredTechKick(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("TechKick", MidiChannel::kDrums);
    track.setPattern(TiredPatterns::kTiredTechKick, lengthInTicks, startInTicks);
    return track;
}

SequenceTrack TiredTrackFactory::tiredBigDrums(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("BigDrums", MidiChannel::kDrums);
    track.setPattern(TiredPatterns::kTiredBigDrums, lengthInTicks, startInTicks);
    return track;
}

SequenceTrack TiredTrackFactory::tiredClapRoll(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("ClapRoll", MidiChannel::kDrums);
    track.setPattern(TiredPatterns::kTiredClapRoll, lengthInTicks, startInTicks);
    return track;
}

SequenceTrack TiredTrackFactory::tiredShake(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("Shake", MidiChannel::kDrums);
    track.setPattern(TiredPatterns::kTiredShake, lengthInTicks, startInTicks);
    return track;
}

SequenceTrack TiredTrackFactory::tiredClapEcho(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("ClapEcho", MidiChannel::kSampler);
    addSingleNote(track, Tired::tClapecho, lengthInTicks - TICK(0,1));
    return track;
}

SequenceTrack TiredTrackFactory::tiredWhiteNoise(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("WhiteNoise", MidiChannel::kSampler);
    addSingleNote(track, Tired::wnDown);
    return track;
}

SequenceTrack TiredTrackFactory::tiredCymbal(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("Cymbal", MidiChannel::kDrums);
    addSingleNote(track, Tired::cymb);

    return track;
}

SequenceTrack TiredTrackFactory::tiredSnareRoll(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("SnareRoll", MidiChannel::kDrums);

    makeRoll(track, Tired::shortsnr, TICK(7), 0, 10, 127, {1, 0.87, 0.75});

    return track;
}

SequenceTrack TiredTrackFactory::tiredRiserB(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("RiserB", MidiChannel::kSampler);

    makeRiser(track, Tired::tRiz2bar, lengthInTicks, TICK(2));

    return track;
}

SequenceTrack TiredTrackFactory::tiredClave(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("Clave", MidiChannel::kDrums);
    track.setPattern(TiredPatterns::kTiredClave, lengthInTicks, startInTicks);
    return track;
}

SequenceTrack TiredTrackFactory::tiredRide(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("Ride", MidiChannel::kDrums);
    track.setPattern(TiredPatterns::kTiredRide, lengthInTicks, startInTicks);
    return track;
}

SequenceTrack TiredTrackFactory::tiredMainBBassEvents(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("MainBBassEvents", MidiChannel::kSampler);

    addSingleNote(track, Tired::tClapecho, TICK(7,3));
    addSingleNote(track, Tired::tRiz2bar, TICK(14));

    addSingleNote(track, Tired::cymb, TICK(16));
    addSingleNote(track, Tired::tClapecho, TICK(23,3));

    addSingleNote(track, Tired::cymb, TICK(28));
    addSingleNote(track, Tired::tired3briz, TICK(29));
    return track;
}

SequenceTrack TiredTrackFactory::tiredRollHat(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("RollHat", MidiChannel::kDrums);

    SequenceDesc desc;
    desc.notes = {{Tired::tiredHat}};
    desc.rate = 16;
    makeSequenceTrack(track, desc, TICK(3,2), 0);

    desc.rate = 32;
    makeSequenceTrack(track, desc, TICK(0,2), TICK(3,2));

    return track;
}

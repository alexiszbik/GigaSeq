#include "FriendshipTrackFactory.h"

#include "factories/friendship/FriendshipPatterns.h"
#include "factories/TrackPatternBuilder.h"
#include "MidiConst.h"

SequenceTrack FriendshipTrackFactory::friendshipStabs(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("Stabs", MidiChannel::kSampler);
    track.setPattern(FriendshipPatterns::kFriendshipStabs, lengthInTicks, startInTicks);
    return track;
}

SequenceTrack FriendshipTrackFactory::friendshipHats(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("Hats", MidiChannel::kSampler);
    track.setPattern(FriendshipPatterns::kFriendshipHats, lengthInTicks, startInTicks);
    return track;
}

SequenceTrack FriendshipTrackFactory::friendshipVoiceSynth(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("VoiceSynth", MidiChannel::kSampler);
    SequenceDesc desc;
    desc.notes = {{Friendship::fbrVoices}};
    desc.rate = 0.125;
    makeSequenceTrack(track, desc, lengthInTicks, startInTicks);
    return track;
}

SequenceTrack FriendshipTrackFactory::friendshipRiser(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("Riser", MidiChannel::kSampler);
    makeRiser(track, Friendship::n130riz, lengthInTicks, TICK(2));
    return track;
}

SequenceTrack FriendshipTrackFactory::friendshipCowClap(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("CowClap", MidiChannel::kDrums);

    uint8_t cow = Friendship::n707cow;
    uint8_t clap = Friendship::fbrClp;

    SequenceDesc desc;
    desc.notes = {
        {}, {}, {cow}, {cow},
        {}, {}, {}, {},
        {}, {}, {}, {},
        {}, {}, {}, {},

        {}, {}, {}, {},
        {}, {}, {}, {},
        {}, {}, {cow}, {},
        {}, {}, {cow}, {},

        {}, {}, {}, {},
        {}, {}, {}, {},
        {}, {}, {}, {},
        {}, {}, {cow}, {cow},

        {}, {}, {}, {},
        {}, {}, {}, {},
        {}, {}, {}, {},
        {}, {}, {cow}, {},

        {}, {}, {cow}, {cow},
        {}, {}, {}, {},
        {}, {}, {}, {},
        {}, {}, {}, {},

        {}, {}, {}, {},
        {}, {}, {}, {},
        {}, {}, {cow}, {},
        {}, {}, {cow}, {},

        {}, {}, {}, {},
        {}, {}, {}, {},
        {}, {}, {}, {},
        {}, {}, {cow}, {cow},

        {}, {}, {}, {},
        {}, {}, {clap}, {clap},
        {clap}, {clap}, {}, {clap},
        {}, {clap}, {cow}, {clap},

    };
    desc.rate = 16;
    makeSequenceTrack(track, desc, lengthInTicks, startInTicks);

    return track;
}

SequenceTrack FriendshipTrackFactory::friendshipBravery(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("Bravery", MidiChannel::kDrums);
    track.setPattern(FriendshipPatterns::kFriendshipBravery, lengthInTicks, startInTicks);
    return track;
}

SequenceTrack FriendshipTrackFactory::friendshipAndBravery(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("Bravery", MidiChannel::kDrums);
    track.setPattern(FriendshipPatterns::kFriendshipAndBravery, lengthInTicks, startInTicks);
    return track;
}

SequenceTrack FriendshipTrackFactory::friendshipXylo(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("Xylo", MidiChannel::kSampler);
    track.setPattern(FriendshipPatterns::kFriendshipXylo, lengthInTicks, startInTicks);
    return track;
}

SequenceTrack FriendshipTrackFactory::friendshipChords(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("Chords", MidiChannel::kMicrofreak);

    SequenceDesc desc;
    desc.notes = {
        {Cd1}, {}, {Gd1}, {Fd1}

    };
    desc.rate = 0.5;
    desc.durations = {2,1,1};
    makeSequenceTrack(track, desc, lengthInTicks, startInTicks);

    return track;
}

SequenceTrack FriendshipTrackFactory::friendshipBalafon(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("Balafon", MidiChannel::kSampler);
    track.setPattern(FriendshipPatterns::kFriendshipBalafon, lengthInTicks, startInTicks);
    return track;
}

SequenceTrack FriendshipTrackFactory::friendshipDrop(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("Drop", MidiChannel::kSampler);

    addSingleNote(track,  Friendship::fbrDrop, startInTicks);

    return track;
}

SequenceTrack FriendshipTrackFactory::friendshipSeqVoice(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("Seq Voice", MidiChannel::kSampler);

    uint8_t a = Friendship::fbrS;
    uint8_t b = Friendship::fbrS1;
    uint8_t c = Friendship::fbrS2;
    uint8_t d = Friendship::fbrS3;

    SequenceDesc desc;
    desc.notes = {
        {a}, {}, {}, {c},
        {a}, {}, {b}, {d}
    };
    desc.rate = 4;
    makeSequenceTrack(track, desc, lengthInTicks, startInTicks);

    return track;
}

SequenceTrack FriendshipTrackFactory::friendshipTrance(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("Trance", MidiChannel::kMicrofreak);
    track.setPattern(FriendshipPatterns::kFriendshipTrance, lengthInTicks, startInTicks);
    return track;
}

SequenceTrack FriendshipTrackFactory::friendshipBass(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("Bass", MidiChannel::kBass);
    track.setPattern(FriendshipPatterns::kFriendshipBass, lengthInTicks, startInTicks);
    return track;
}

SequenceTrack FriendshipTrackFactory::friendshipJungle(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("Jungle", MidiChannel::kSampler);
    track.setPattern(FriendshipPatterns::kFriendshipJungle, lengthInTicks, startInTicks);
    return track;
}

SequenceTrack FriendshipTrackFactory::friendshipStabz(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("Stabz", MidiChannel::kSampler);
    track.setPattern(FriendshipPatterns::kFriendshipStabz, lengthInTicks, startInTicks);
    return track;
}

SequenceTrack FriendshipTrackFactory::friendshipVocalHits(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("VocalHits", MidiChannel::kDrums);

    uint8_t a = Friendship::fbV3; 
    uint8_t b = Friendship::fbV4; 
    uint8_t c = Friendship::fbV2;

    SequenceDesc desc;
    desc.notes = {{a}};
    desc.rate = 16;
    makeSequenceTrack(track, desc, TICK(2), TICK(4));

    desc.notes = {{b}};
    makeSequenceTrack(track, desc, TICK(1), TICK(6));

    desc.notes = {{c}};
    makeSequenceTrack(track, desc, TICK(1), TICK(7));

    return track;
}

SequenceTrack FriendshipTrackFactory::friendshipOpenH909(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("OpenH909", MidiChannel::kDrums);
    track.setPattern(FriendshipPatterns::kFriendshipOpenH909, lengthInTicks, startInTicks);
    return track;
}

SequenceTrack FriendshipTrackFactory::friendshipSnareRoll(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("SnareRoll", MidiChannel::kDrums);

    makeRoll(track, {Friendship::snr909}, TICK(15,0), startInTicks, 1, 127);
    return track;
}

SequenceTrack FriendshipTrackFactory::friendshipTranceB(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("TranceB", MidiChannel::kMicrofreak);
    track.setPattern(FriendshipPatterns::kFriendshipTranceB, lengthInTicks, startInTicks);

    return track;
}

SequenceTrack FriendshipTrackFactory::friendshipCrash(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("Crash", MidiChannel::kDrums);
    addSingleNote(track, Friendship::cym74);
    return track;
}

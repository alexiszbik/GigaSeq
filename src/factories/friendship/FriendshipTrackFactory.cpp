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

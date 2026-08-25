#include "FriendshipSequenceFactory.h"

#include "factories/SequenceBuilder.h"
#include "factories/SequenceTrackFactory.h"
#include "factories/friendship/FriendshipTrackFactory.h"
#include "MidiConst.h"

namespace {
constexpr uint8_t songTempo = 145;
}

Sequence FriendshipSequenceFactory::friendshipIntro()
{
    Sequence seq = buildSequence(
        8, 4, 0, "Intro", songTempo, true,
        {
            SequenceTrackFactory::kickFour,
            SequenceTrackFactory::snareFour,
            FriendshipTrackFactory::friendshipHats,
            FriendshipTrackFactory::friendshipCowClap,
            FriendshipTrackFactory::friendshipStabs,
            FriendshipTrackFactory::friendshipVoiceSynth,
            FriendshipTrackFactory::friendshipBravery,
            FriendshipTrackFactory::friendshipRiser,
        });
    return seq;
}

Sequence FriendshipSequenceFactory::friendshipChill()
{
    Sequence seq = buildSequence(
        8, 4, 0, "Chill", songTempo, true,
        {
            FriendshipTrackFactory::friendshipXylo,
            FriendshipTrackFactory::friendshipChords,
            FriendshipTrackFactory::friendshipBalafon,
            FriendshipTrackFactory::friendshipSeqVoice,
            FriendshipTrackFactory::friendshipHats,
            FriendshipTrackFactory::friendshipDrop,
            FriendshipTrackFactory::friendshipRiser,
        });
    return seq;
}

Sequence FriendshipSequenceFactory::friendshipBreak()
{
    Sequence seq = buildSequence(
        8, 4, 0, "Break", songTempo, true,
        {
            FriendshipTrackFactory::friendshipTrance,
            FriendshipTrackFactory::friendshipBravery,
        });
    return seq;
}

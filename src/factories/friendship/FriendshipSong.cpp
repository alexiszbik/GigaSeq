#include "FriendshipSong.h"

#include "factories/friendship/FriendshipSequenceFactory.h"
#include "Sequence.h"
#include "SequencePool.h"
#include "Song.h"


void addFriendshipSong(SequencePool& pool)
{
    using Builder = Sequence (*)();

    Song song("Friendship", 8);
    const Builder sequences[] = {
        FriendshipSequenceFactory::friendshipIntro,
        FriendshipSequenceFactory::friendshipChill,
        FriendshipSequenceFactory::friendshipBack,
        FriendshipSequenceFactory::friendshipBreak,
        FriendshipSequenceFactory::friendshipRising,
        FriendshipSequenceFactory::friendshipClimax,

        FriendshipSequenceFactory::friendshipMain,
        FriendshipSequenceFactory::friendshipEnd,
    };

    for (Builder builder : sequences) {
        song.add(builder());
    }

    

    pool.add(std::move(song));
}

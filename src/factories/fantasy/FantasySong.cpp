#include "FantasySong.h"

#include "factories/fantasy/FantasySequenceFactory.h"
#include "Sequence.h"
#include "SequencePool.h"
#include "Song.h"

void addFantasySong(SequencePool& pool)
{
    using Builder = Sequence (*)();

    Song song("Fantasy", 4);
    const Builder sequences[] = {
        FantasySequenceFactory::fantasyIntro,
        FantasySequenceFactory::fantasyStart,
        FantasySequenceFactory::fantasyBreak,
        FantasySequenceFactory::fantasyBack,
        FantasySequenceFactory::fantasyRave,
        FantasySequenceFactory::fantasyGuitar,
        FantasySequenceFactory::fantasyGuitarRiz,
        FantasySequenceFactory::fantasyClimax,
    };

    for (Builder builder : sequences) {
        song.add(builder());
    }

    pool.add(std::move(song));
}

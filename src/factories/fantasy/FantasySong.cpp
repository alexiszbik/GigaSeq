#include "FantasySong.h"

#include "factories/fantasy/FantasySequenceFactory.h"
#include "Sequence.h"
#include "SequencePool.h"
#include "Song.h"

void addFantasySong(SequencePool& pool)
{
    using Builder = Sequence (*)();

    Song song("Fantasy", 1);
    const Builder sequences[] = {
        FantasySequenceFactory::fantasyIntro,
  
    };

    for (Builder builder : sequences) {
        song.add(builder());
    }

    pool.add(std::move(song));
}

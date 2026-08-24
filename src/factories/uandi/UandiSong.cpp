#include "UandiSong.h"

#include "factories/uandi/UandiSequenceFactory.h"
#include "Sequence.h"
#include "SequencePool.h"
#include "Song.h"

void addUandiSong(SequencePool& pool)
{
    using Builder = Sequence (*)();

    Song song("Uandi", 6);
    const Builder sequences[] = {
        UandiSequenceFactory::uandiIntro,
  
        UandiSequenceFactory::uandiIntroB,
        UandiSequenceFactory::uandiMain,
        UandiSequenceFactory::uandiBreak,
        UandiSequenceFactory::uandiBack,
        UandiSequenceFactory::uandiClimax,
        UandiSequenceFactory::uandiEnd,
    };

    for (Builder builder : sequences) {
        song.add(builder());
    }

    pool.add(std::move(song));
}

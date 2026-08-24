#include "TiredSong.h"

#include "factories/tired/TiredSequenceFactory.h"
#include "Sequence.h"
#include "SequencePool.h"
#include "Song.h"

void addTiredSong(SequencePool& pool)
{
    using Builder = Sequence (*)();

    Song song("Tired", 7);
    const Builder sequences[] = {
        TiredSequenceFactory::tiredIntro,
  
        TiredSequenceFactory::tiredDropA,
    };

    for (Builder builder : sequences) {
        song.add(builder());
    }

    pool.add(std::move(song));
}

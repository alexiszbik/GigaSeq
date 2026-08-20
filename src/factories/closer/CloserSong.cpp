#include "CloserSong.h"

#include "factories/closer/CloserSequenceFactory.h"
#include "Sequence.h"
#include "SequencePool.h"
#include "Song.h"

void addCloserSong(SequencePool& pool)
{
    using Builder = Sequence (*)();

    Song song("Closer", 1);
    const Builder sequences[] = {
        CloserSequenceFactory::closerIntro,
  
    };

    for (Builder builder : sequences) {
        song.add(builder());
    }

    pool.add(std::move(song));
}

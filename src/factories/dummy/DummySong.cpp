#include "DummySong.h"

#include "factories/dummy/DummySequenceFactory.h"
#include "Sequence.h"
#include "SequencePool.h"
#include "Song.h"

void addDummySong(SequencePool& pool)
{
    using Builder = Sequence (*)();

    Song song("Dummy", 1);
    const Builder sequences[] = {
        DummySequenceFactory::dummyIntro,
  
    };

    for (Builder builder : sequences) {
        song.add(builder());
    }

    pool.add(std::move(song));
}

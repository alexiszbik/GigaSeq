#include "WaterSong.h"

#include "factories/water/WaterSequenceFactory.h"
#include "Sequence.h"
#include "SequencePool.h"
#include "Song.h"

void addWaterSong(SequencePool& pool)
{
    using Builder = Sequence (*)();

    Song song("Water", 1);
    const Builder sequences[] = {
        WaterSequenceFactory::waterIntro,
  
    };

    for (Builder builder : sequences) {
        song.add(builder());
    }

    pool.add(std::move(song));
}

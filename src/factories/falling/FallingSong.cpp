#include "FallingSong.h"

#include "factories/falling/FallingSequenceFactory.h"
#include "Sequence.h"
#include "SequencePool.h"
#include "Song.h"

void addFallingSong(SequencePool& pool)
{
    using Builder = Sequence (*)();

    Song song("Falling", 2);
    const Builder sequences[] = {
        FallingSequenceFactory::fallingIntro,
        FallingSequenceFactory::fallingIntro2,
        FallingSequenceFactory::fallingBassSeq,
        
        FallingSequenceFactory::fallingPreInterlude,
    };

    for (Builder builder : sequences) {
        song.add(builder());
    }

    pool.add(std::move(song));
}

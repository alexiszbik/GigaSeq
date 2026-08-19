#include "TogetherSong.h"

#include "factories/together/TogetherSequenceFactory.h"
#include "Sequence.h"
#include "SequencePool.h"
#include "Song.h"

void addTogetherSong(SequencePool& pool)
{
    using Builder = Sequence (*)();

    Song song("Together");
    const Builder sequences[] = {
        TogetherSequenceFactory::togetherIntro,
        TogetherSequenceFactory::togetherSample,
        TogetherSequenceFactory::togetherKick,
        TogetherSequenceFactory::togetherVocoder,
        TogetherSequenceFactory::togetherPause,
        TogetherSequenceFactory::togetherClimax,
        TogetherSequenceFactory::togetherRepeat,
        TogetherSequenceFactory::togetherPartB,
        TogetherSequenceFactory::togetherPartBWithHats,
        TogetherSequenceFactory::togetherPartBDrums,
        TogetherSequenceFactory::togetherPartBClimax,
    };

    for (Builder builder : sequences) {
        song.add(builder());
    }

    pool.add(std::move(song));
}

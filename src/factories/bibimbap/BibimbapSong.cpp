#include "BibimbapSong.h"

#include "factories/bibimbap/BibimbapSequenceFactory.h"
#include "Sequence.h"
#include "SequencePool.h"
#include "Song.h"

void addBibimbapSong(SequencePool& pool)
{
    using Builder = Sequence (*)();

    Song song("Bibimbap", 5);
    const Builder sequences[] = {
        BibimbapSequenceFactory::bibimbapIntro,
        BibimbapSequenceFactory::bibimbapMain,
        BibimbapSequenceFactory::bibimbapBass,
        BibimbapSequenceFactory::bibimbapPause,
        BibimbapSequenceFactory::bibimbapDrop,
    };

    for (Builder builder : sequences) {
        song.add(builder());
    }

    pool.add(std::move(song));
}

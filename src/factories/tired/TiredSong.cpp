#include "TiredSong.h"

#include "factories/tired/TiredSequenceFactory.h"
#include "Sequence.h"
#include "SequencePool.h"
#include "Song.h"
#include "MidiConst.h"

void addTiredSong(SequencePool& pool)
{
    using Builder = Sequence (*)();

    Song song("Tired", 7);
    const Builder sequences[] = {
        TiredSequenceFactory::tiredIntro,
        TiredSequenceFactory::tiredDropA,
        TiredSequenceFactory::tiredMain,

        TiredSequenceFactory::tiredPause,

        TiredSequenceFactory::tiredDropB,
        TiredSequenceFactory::tiredMainB,

        TiredSequenceFactory::tiredMainBBass,
        
        TiredSequenceFactory::tiredPartBStart,
        TiredSequenceFactory::tiredPartBSolo,

        TiredSequenceFactory::tiredPartBPreRoll,
        TiredSequenceFactory::tiredPartBClimax,
        TiredSequenceFactory::tiredBigEnd,
        

    };

    for (Builder builder : sequences) {
        song.add(builder());
    }

    pool.add(std::move(song));
}

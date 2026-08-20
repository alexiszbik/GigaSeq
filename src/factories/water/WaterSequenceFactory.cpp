#include "WaterSequenceFactory.h"

#include "factories/SequenceBuilder.h"
#include "factories/SequenceTrackFactory.h"
#include "factories/water/WaterTrackFactory.h"
#include "MidiChannel.h"

Sequence WaterSequenceFactory::waterIntro()
{
    Sequence seq = buildSequence(
        8, 4, 0, "Intro", 125, true,
        {
            SequenceTrackFactory::kickFour,
            SequenceTrackFactory::snareFour,
            WaterTrackFactory::waterHats,
            WaterTrackFactory::waterArp,
        });
    return seq;
}

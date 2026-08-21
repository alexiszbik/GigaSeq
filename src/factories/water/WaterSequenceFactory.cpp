#include "WaterSequenceFactory.h"

#include "factories/SequenceBuilder.h"
#include "factories/SequenceTrackFactory.h"
#include "factories/water/WaterTrackFactory.h"
#include "MidiChannel.h"

constexpr uint8_t songTempo = 125;

Sequence WaterSequenceFactory::waterIntro()
{
    Sequence seq = buildSequence(
        8, 4, 0, "Intro", songTempo, true,
        {
            SequenceTrackFactory::kickFour,
            SequenceTrackFactory::snareFour,
            WaterTrackFactory::waterHats,
            WaterTrackFactory::waterMarimba,
            WaterTrackFactory::waterFm,
            WaterTrackFactory::waterBalafon,
            WaterTrackFactory::waterFreak,
            WaterTrackFactory::waterBass,
            WaterTrackFactory::waterClaves,
            WaterTrackFactory::waterCongas,
            WaterTrackFactory::waterShakes,
            WaterTrackFactory::waterFmbass,
        });
    return seq;
}

Sequence WaterSequenceFactory::waterChorus()
{
    Sequence seq = buildSequence(
        8, 4, 0, "Chorus", songTempo, true,
        {
            SequenceTrackFactory::snareFour,
            WaterTrackFactory::waterHats,
            WaterTrackFactory::waterChorus,
            WaterTrackFactory::waterMarimba,
            WaterTrackFactory::waterXmas,
            WaterTrackFactory::waterCongas,
        });
    return seq;
}

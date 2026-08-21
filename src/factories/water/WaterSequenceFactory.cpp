#include "WaterSequenceFactory.h"

#include "factories/SequenceBuilder.h"
#include "factories/SequenceTrackFactory.h"
#include "factories/water/WaterTrackFactory.h"
#include "MidiChannel.h"

constexpr uint8_t songTempo = 125;

Sequence WaterSequenceFactory::waterIntro()
{
    return buildSequence(
        8, 4, 0, "Intro", songTempo, true,
        {
            SequenceTrackFactory::kickFour,
            SequenceTrackFactory::snareFour,
            track(WaterTrackFactory::waterHats).muted(),
            track(WaterTrackFactory::waterMarimba).muted(),
            WaterTrackFactory::waterFreak,
            track(WaterTrackFactory::waterBass).muted(),
            track(WaterTrackFactory::waterClaves).muted(),
            track(WaterTrackFactory::waterCongas).muted(),
            track(WaterTrackFactory::waterFmbass).muted(),
        });
}

Sequence WaterSequenceFactory::waterPrechorus()
{
    return buildSequence(
        8, 4, 0, "Intro", songTempo, false,
        {
            WaterTrackFactory::waterKickPreChorus,
            SequenceTrackFactory::snareFour,
            WaterTrackFactory::waterHats,
            WaterTrackFactory::waterMarimba,
            WaterTrackFactory::waterFreak,
            WaterTrackFactory::waterBass,
            WaterTrackFactory::waterClaves,
            WaterTrackFactory::waterCongas,
            WaterTrackFactory::waterFmbass,
        });
}

Sequence WaterSequenceFactory::waterChorus()
{
    return buildSequence(
        8, 4, 0, "Chorus", songTempo, false,
        {
            SequenceTrackFactory::snareFour,
            WaterTrackFactory::waterHats,
            WaterTrackFactory::waterChorus,
            WaterTrackFactory::waterMarimba,
        });
}

Sequence WaterSequenceFactory::waterChorus2()
{
    tick_t len = 7*384 + 2*96;

    Sequence seq = buildSequence(
        8, 4, 0, "Chorus2", songTempo, false,
        {
            track(SequenceTrackFactory::snareFour).withLength(len),
            track(WaterTrackFactory::waterHats).withLength(len),
            WaterTrackFactory::waterChorus2,
            WaterTrackFactory::waterMarimba,
            track(WaterTrackFactory::waterXmas).withLength(len),
            WaterTrackFactory::waterChorusFMBass
        });
    seq.track(3).addNote(len, 24, 68, 127); // note to stop the marimba
    seq.track(3).addNote(len, 24, 69, 127); // note to stop the juno

    return seq;
}


Sequence WaterSequenceFactory::waterFull()
{
    return buildSequence(
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
}
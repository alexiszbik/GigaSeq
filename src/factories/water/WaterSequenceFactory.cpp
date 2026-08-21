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
    tick_t len = 15*384 + 2*96 + 48;
    tick_t len2 = 7*384 + 2*96 + 48;

    Sequence seq = buildSequence(
        16, 4, 0, "Chorus", songTempo, false,
        {
            track(SequenceTrackFactory::snareFour).withLength(len),
            track(WaterTrackFactory::waterHats).withLength(len),
            WaterTrackFactory::waterChorus,
            WaterTrackFactory::waterMarimba,
            track(WaterTrackFactory::waterXmas).withLength(len2).withStart(8*384),
            track(WaterTrackFactory::waterChorusFMBass).withStart(15*384),
        });

    seq.track(3).addNote(len, 24, 68, 127); // note to stop the marimba
    seq.track(2).addNote(len, 24, 69, 127); // note to stop the juno

    return seq;
}

Sequence WaterSequenceFactory::waterPartB()
{
    tick_t start2 = 384*8;
    tick_t start3 = 384*16;

    tick_t len1 = 384*31 + 3*96;
    tick_t len2 = 384*23 + 3*96;
    tick_t len3 = 384*15 + 3*96;

    Sequence seq = buildSequence(
        32, 4, 0, "PartB", songTempo, false,
        {
            WaterTrackFactory::waterKickPartB,
            track(SequenceTrackFactory::snareFour).withLength(len1),
            track(WaterTrackFactory::waterHats).withLength(len1),
            track(WaterTrackFactory::waterFm).withLength(len1),
            track(WaterTrackFactory::waterFreak).withLength(len1),
            track(WaterTrackFactory::waterFmbass).withLength(384*31),
            track(WaterTrackFactory::waterClaves).withStart(start2).withLength(len2),
            track(WaterTrackFactory::waterBalafon).withStart(start2).withLength(len2),
            track(WaterTrackFactory::waterBass).withStart(start2).withLength(len2),
            track(WaterTrackFactory::waterXmas).withStart(start3).withLength(len3),
            WaterTrackFactory::waterEventsPartB,
        });

    seq.track(3).addNote(len1, 24, 70, 127); // note to stop the juno
    return seq;
}


Sequence WaterSequenceFactory::waterChorus2()
{
    tick_t len = 15*384 + 2*96 + 48;
    tick_t len2 = 7*384 + 2*96 + 48;

    Sequence seq = buildSequence(
        16, 4, 0, "Chorus", songTempo, false,
        {
            track(SequenceTrackFactory::snareFour).withLength(len),
            track(WaterTrackFactory::waterHats).withLength(len),
            WaterTrackFactory::waterChorus,
            track(WaterTrackFactory::waterBalafon).withLength(len),
            track(WaterTrackFactory::waterXmas).withLength(len2).withStart(8*384),
            track(WaterTrackFactory::waterChorusFMBass).withStart(15*384),
            track(WaterTrackFactory::waterFreakChorusB).withLength(len),
        });

    seq.track(2).addNote(len, 24, 69, 127); // note to stop the juno

    return seq;
}


Sequence WaterSequenceFactory::waterFull()
{
    return buildSequence(
        8, 4, 0, "Full", songTempo, true,
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


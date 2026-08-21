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
        8, 4, 0, "PreChorus", songTempo, false,
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
    tick_t start4 = 384*24;

    tick_t len1 = 384*31 + 3*96;
    tick_t len2 = 384*23 + 3*96;
    tick_t len3 = 384*15 + 3*96;
    tick_t len4 = 384*7 + 3*96;

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
            track(WaterTrackFactory::waterShakes).withStart(start4).withLength(len4),
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
        16, 4, 0, "ChorusB", songTempo, false,
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


Sequence WaterSequenceFactory::waterPartC()
{
    Sequence seq = buildSequence(
        24, 4, 16, "PartC", songTempo, true,
        {
            SequenceTrackFactory::kickFour,
            track(SequenceTrackFactory::snareFour).muted(),
            track(WaterTrackFactory::waterHats).muted(),
            WaterTrackFactory::waterMarimba,
            WaterTrackFactory::waterFreak,
            WaterTrackFactory::waterBass,
            WaterTrackFactory::waterClaves,
            track(WaterTrackFactory::waterBalafon).muted(),
            track(WaterTrackFactory::waterShakes).muted(),
            track(WaterTrackFactory::waterXmas).withStart(384*16),
            WaterTrackFactory::waterFmbass,
        });
    return seq;
}


Sequence WaterSequenceFactory::waterPartCEnd()
{
    tick_t len = 7*384 + 2*96 + 48;

    Sequence seq = buildSequence(
        8, 4, 0, "PartCEnd", songTempo, false,
        {
            WaterTrackFactory::waterKickPartC,
            SequenceTrackFactory::snareFour,
            WaterTrackFactory::waterHats,
            WaterTrackFactory::waterMarimba,
            track(WaterTrackFactory::waterFreak).withLength(len),
            track(WaterTrackFactory::waterBass).withLength(len),
            WaterTrackFactory::waterClaves,
            track(WaterTrackFactory::waterBalafon).withLength(len),
            track(WaterTrackFactory::waterShakes).withLength(len),
            track(WaterTrackFactory::waterXmas).withLength(len),
            track(WaterTrackFactory::waterFmbass).withLength(len),
            WaterTrackFactory::waterEventsPartC,
        });

    seq.track(3).addNote(len, 24, 68, 127); // note to stop the marimba
    
    return seq;
}


Sequence WaterSequenceFactory::waterChorusEnd()
{
    tick_t len1 = 8*384;
    tick_t len2 = 16*384;
    tick_t len4 = 32*384;

    Sequence seq = buildSequence(
        33, 4, 32, "ChorusEnd", songTempo, true,
        {
            track(SequenceTrackFactory::snareFour).withLength(len2),
            track(WaterTrackFactory::waterHats).withLength(len2),
            track(WaterTrackFactory::waterChorusEnd).withLength(len4),
            track(WaterTrackFactory::waterMarimba).withLength(len4),
            WaterTrackFactory::waterBalafon,
            track(WaterTrackFactory::waterXmas).withLength(len1).withStart(len1),
            WaterTrackFactory::waterEventsEnd,
        });

    return seq;
}

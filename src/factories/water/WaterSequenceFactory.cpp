#include "WaterSequenceFactory.h"

#include "factories/SequenceBuilder.h"
#include "factories/SequenceTrackFactory.h"
#include "factories/water/WaterTrackFactory.h"
#include "MidiConst.h"
#include "TickHelper.h"

namespace {
constexpr uint8_t songTempo = 125;
}

Sequence WaterSequenceFactory::waterIntro()
{
    Sequence seq = buildSequence(
        16, 4, 8, "Intro", songTempo, true,
        {
            SequenceTrackFactory::kickFour,
            SequenceTrackFactory::clapFour,
            track(WaterTrackFactory::waterHats).muted(),
            track(WaterTrackFactory::waterMarimba).muted(),
            track(WaterTrackFactory::waterFreak).withProgramChange(Microfreak::kWaterBass),
            track(WaterTrackFactory::waterBass).muted(),
            track(WaterTrackFactory::waterClaves).muted(),
            track(WaterTrackFactory::waterCongas).muted(),
            track(WaterTrackFactory::waterFmbass).muted(),
            track(SequenceTrackFactory::gtrLoopErase).withProgramChange(BossRC::kWater, TICK(4)),
            track(SequenceTrackFactory::gtrPedal).withProgramChange(HXStomp::kWater),
            track(SequenceTrackFactory::polySynth).withProgramChange(PolySynth::kWaterSqr),
            track(SequenceTrackFactory::midiLoop)
                .withNote(MidiLoop::kEraseAll)
                .withNote(MidiLoop::kSelectPoly)
                .withCC(MidiLoop::kArpMode_cc, OFF)
                .withCC(MidiLoop::kRecord_cc, OFF),
        });

    return seq;
}

Sequence WaterSequenceFactory::waterPrechorus()
{
    return buildSequence(
        8, 4, 0, "PreChorus", songTempo, false,
        {
            WaterTrackFactory::waterKickPreChorus,
            SequenceTrackFactory::clapFour,
            WaterTrackFactory::waterHats,
            WaterTrackFactory::waterMarimba,
            WaterTrackFactory::waterFreak,
            WaterTrackFactory::waterBass,
            WaterTrackFactory::waterClaves,
            WaterTrackFactory::waterCongas,
            track(WaterTrackFactory::waterFmbass).withLength(TickHelper::bars(7)),
        });
}

Sequence WaterSequenceFactory::waterChorus()
{
    tick_t len = TICK(15, 2, 2);
    tick_t len2 = TICK(7, 2, 2);

    return buildSequence(
        16, 4, 0, "Chorus", songTempo, false,
        {
            track(SequenceTrackFactory::clapFour).withLength(len),
            track(WaterTrackFactory::waterHats).withLength(len),
            track(WaterTrackFactory::waterChorus).withNote(69, 127, len), // note to stop the juno
            track(WaterTrackFactory::waterMarimba).withNote(68, 127, len), // note to stop the marimba
            track(WaterTrackFactory::waterXmas).withLength(len2).withStart(TickHelper::bars(8)),
            track(WaterTrackFactory::waterChorusFMBass).withStart(TickHelper::bars(15)),
            track(SequenceTrackFactory::modularA).withCC(ModularA::kGlobalMute_cc, ON, len)
        });
}

Sequence WaterSequenceFactory::waterPartB()
{
    tick_t start2 = TickHelper::bars(8);
    tick_t start3 = TickHelper::bars(16);
    tick_t start4 = TickHelper::bars(24);

    tick_t len1 = TICK(31, 3);
    tick_t len2 = TICK(23, 3);
    tick_t len3 = TICK(15, 3);
    tick_t len4 = TICK(7, 3);

    return buildSequence(
        32, 4, 0, "PartB", songTempo, false,
        {
            WaterTrackFactory::waterKickPartB,
            track(SequenceTrackFactory::clapFour).withLength(len1),
            track(WaterTrackFactory::waterHats).withLength(len1),
            track(WaterTrackFactory::waterFm).withLength(len1).withNote(70, 127, len1), // note to stop the juno
            track(WaterTrackFactory::waterFreak).withLength(len1),
            track(WaterTrackFactory::waterFmbass).withLength(TickHelper::bars(31)),
            track(WaterTrackFactory::waterClaves).withStart(start2).withLength(len2),
            track(WaterTrackFactory::waterBalafon).withStart(start2).withLength(len2),
            track(WaterTrackFactory::waterBass).withStart(start2).withLength(len2),
            track(WaterTrackFactory::waterXmas).withStart(start3).withLength(len3),
            track(WaterTrackFactory::waterShakes).withStart(start4).withLength(len4),
            WaterTrackFactory::waterEventsPartB,
            track(SequenceTrackFactory::polySynth).withProgramChange(PolySynth::kSlowStr),
            track(SequenceTrackFactory::modularA).withCC(ModularA::kGlobalMute_cc, OFF).withCC(ModularA::kGlobalMute_cc, ON, len1)
        });
}


Sequence WaterSequenceFactory::waterChorus2()
{
    tick_t len = TICK(15, 2, 2);
    tick_t len2 = TICK(7, 2, 2);

    return buildSequence(
        16, 4, 0, "ChorusB", songTempo, false,
        {
            track(SequenceTrackFactory::clapFour).withLength(len),
            track(WaterTrackFactory::waterHats).withLength(len),
            track(WaterTrackFactory::waterChorus).withNote(69, 127, len), // note to stop the juno
            track(WaterTrackFactory::waterBalafon).withLength(len),
            track(WaterTrackFactory::waterXmas).withLength(len2).withStart(TickHelper::bars(8)),
            track(WaterTrackFactory::waterChorusFMBass).withStart(TickHelper::bars(15)),
            track(WaterTrackFactory::waterFreakChorusB).withLength(len)
                .withProgramChange(Microfreak::kWaterArp),
            track(SequenceTrackFactory::polySynth).withProgramChange(PolySynth::kBigLead),
            track(SequenceTrackFactory::modularA).withCC(ModularA::kGlobalMute_cc, OFF)
        });
}


Sequence WaterSequenceFactory::waterPartC()
{
    Sequence seq = buildSequence(
        24, 4, 16, "PartC", songTempo, true,
        {
            SequenceTrackFactory::kickFour,
            track(SequenceTrackFactory::clapFour).muted(),
            track(WaterTrackFactory::waterHats).muted(),
            WaterTrackFactory::waterMarimba,
            track(WaterTrackFactory::waterFreak).withProgramChange(Microfreak::kWaterBass),
            WaterTrackFactory::waterBass,
            WaterTrackFactory::waterClaves,
            track(WaterTrackFactory::waterBalafon).muted(),
            track(WaterTrackFactory::waterShakes).muted(),
            track(WaterTrackFactory::waterXmas).withStart(TickHelper::bars(16)),
            WaterTrackFactory::waterFmbass,
        });
    return seq;
}


Sequence WaterSequenceFactory::waterPartCEnd()
{
    tick_t len = TICK(7, 2, 2);

    return buildSequence(
        8, 4, 0, "PartCEnd", songTempo, false,
        {
            WaterTrackFactory::waterKickPartC,
            SequenceTrackFactory::clapFour,
            WaterTrackFactory::waterHats,
            track(WaterTrackFactory::waterMarimba).withNote(68, 127, len), // note to stop the marimba
            track(WaterTrackFactory::waterFreak).withLength(len),
            track(WaterTrackFactory::waterBass).withLength(len),
            WaterTrackFactory::waterClaves,
            track(WaterTrackFactory::waterBalafon).withLength(len),
            track(WaterTrackFactory::waterShakes).withLength(len),
            track(WaterTrackFactory::waterXmas).withLength(len),
            track(WaterTrackFactory::waterFmbass).withLength(len),
            WaterTrackFactory::waterEventsPartC,
            track(SequenceTrackFactory::modularA).withCC(ModularA::kGlobalMute_cc, ON, len)
        });
}


Sequence WaterSequenceFactory::waterChorusEnd()
{
    tick_t len1 = TickHelper::bars(8);
    tick_t len2 = TickHelper::bars(16);
    tick_t len4 = TickHelper::bars(32);

    Sequence seq = buildSequence(
        36, 4, 32, "ChorusEnd", songTempo, true,
        {
            track(SequenceTrackFactory::clapFour).withLength(len2),
            track(WaterTrackFactory::waterHats).withLength(len2),
            track(WaterTrackFactory::waterChorusEnd).withLength(len4),
            track(WaterTrackFactory::waterMarimba).withLength(len4),
            WaterTrackFactory::waterBalafon,
            track(WaterTrackFactory::waterXmas).withLength(len1).withStart(len1),
            WaterTrackFactory::waterEventsEnd,
            track(WaterTrackFactory::waterFreakWind).withStart(TICK(8)).withProgramChange(Microfreak::kWind),
            track(SequenceTrackFactory::modularA).withCC(ModularA::kGlobalMute_cc, OFF)
        });

    return seq;
}

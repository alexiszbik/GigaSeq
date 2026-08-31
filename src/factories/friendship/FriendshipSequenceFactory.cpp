#include "FriendshipSequenceFactory.h"

#include "factories/SequenceBuilder.h"
#include "factories/SequenceTrackFactory.h"
#include "factories/friendship/FriendshipTrackFactory.h"
#include "MidiConst.h"

namespace {
constexpr uint8_t songTempo = 145;
}

Sequence FriendshipSequenceFactory::friendshipIntro()
{
    Sequence seq = buildSequence(
        8, 4, 0, "Intro", songTempo, true,
        {
            track(SequenceTrackFactory::kickFour).muted(),
            track(SequenceTrackFactory::snareFour).muted(),
            track(FriendshipTrackFactory::friendshipHats).muted(),
            track(FriendshipTrackFactory::friendshipCowClap).muted(),
            FriendshipTrackFactory::friendshipStabs,
            track(FriendshipTrackFactory::friendshipVoiceSynth).muted(),
            track(FriendshipTrackFactory::friendshipBravery).muted(),
            track(FriendshipTrackFactory::friendshipRiser).muted().withMuteEvent(0).asFill(),
            track(SequenceTrackFactory::gtrPedal).withProgramChange(HXStomp::kFriendship),
            track(SequenceTrackFactory::gtrLoop).withProgramChange(BossRC::kFriendship),
            track(SequenceTrackFactory::midiLoop)
                .withNote(MidiLoop::kEraseAll)
                .withNote(MidiLoop::kSelectBass)
                .withCC(MidiLoop::kArpMode_cc, ON)
                .withCC(MidiLoop::kRecord_cc, ON)
                .withCC(MidiLoop::kBarCount_cc, 8),
            
        });
    return seq;
}

Sequence FriendshipSequenceFactory::friendshipChill()
{
    Sequence seq = buildSequence(
        16, 4, 8, "Chill", songTempo, true,
        {
            FriendshipTrackFactory::friendshipChords,
            FriendshipTrackFactory::friendshipXylo,
            track(FriendshipTrackFactory::friendshipSeqVoice).withStart(TICK(8)),
            track(FriendshipTrackFactory::friendshipBalafon).muted(),
            track(FriendshipTrackFactory::friendshipHats).muted(),
            track(SequenceTrackFactory::midiLoop).withCC(MidiLoop::kMuteBass_cc, ON)
        });
    return seq;
}


Sequence FriendshipSequenceFactory::friendshipBack()
{
    Sequence seq = buildSequence(
        8, 4, 0, "Back", songTempo, false,
        {
            FriendshipTrackFactory::friendshipChords,
            FriendshipTrackFactory::friendshipXylo,
            FriendshipTrackFactory::friendshipSeqVoice,
            FriendshipTrackFactory::friendshipBalafon,
            FriendshipTrackFactory::friendshipHats,
            FriendshipTrackFactory::friendshipDrop,
            FriendshipTrackFactory::friendshipRiser,
            FriendshipTrackFactory::friendshipVocalHits
        });
    return seq;
}


Sequence FriendshipSequenceFactory::friendshipMain()
{
    Sequence seq = buildSequence(
        8, 4, 0, "Main", songTempo, true,
        {
            SequenceTrackFactory::kickFour,
            SequenceTrackFactory::snareFour,
            FriendshipTrackFactory::friendshipHats,
            FriendshipTrackFactory::friendshipCowClap,
            FriendshipTrackFactory::friendshipStabs,
            FriendshipTrackFactory::friendshipVoiceSynth,
            track(FriendshipTrackFactory::friendshipRiser).muted().withMuteEvent(0).asFill(),
            track(SequenceTrackFactory::midiLoop).withCC(MidiLoop::kMuteBass_cc, OFF)
        });
    return seq;
}

Sequence FriendshipSequenceFactory::friendshipBreak()
{
    Sequence seq = buildSequence(
        16, 4, 8, "Break", songTempo, true,
        {
            FriendshipTrackFactory::friendshipTrance,
            FriendshipTrackFactory::friendshipBravery,
            track(FriendshipTrackFactory::friendshipBass).muted(),
            track(FriendshipTrackFactory::friendshipJungle).withStart(TICK(8)),
            track(FriendshipTrackFactory::friendshipStabz).muted(),
            track(FriendshipTrackFactory::friendshipOpenH909).muted(),
            track(SequenceTrackFactory::midiLoop)
                .withNote(MidiLoop::kEraseAll)
                .withNote(MidiLoop::kSelectPoly)
                .withCC(MidiLoop::kArpMode_cc, OFF)
                .withCC(MidiLoop::kRecord_cc, OFF)

        });
    return seq;
}

Sequence FriendshipSequenceFactory::friendshipRising()
{
    return buildSequence(
        16, 4, 0, "Climax", songTempo, false,
        {
            track(FriendshipTrackFactory::friendshipTrance).withLength(TICK(15)),
            track(FriendshipTrackFactory::friendshipBravery).withLength(TICK(15)),
            track(FriendshipTrackFactory::friendshipBass)
                .withMuteEvent(TICK(15, 0, 1))
                .withMuteEvent(TICK(15, 2, 1), false),
            track(FriendshipTrackFactory::friendshipJungle).withNote(69, 127, TICK(15), TickHelper::kHalfStepLen),
            track(FriendshipTrackFactory::friendshipStabz),
            track(FriendshipTrackFactory::friendshipOpenH909).withLength(TICK(15)),
            track(FriendshipTrackFactory::friendshipSnareRoll),
            track(FriendshipTrackFactory::friendshipRiser).withLength(TICK(15)),
        });
}

Sequence FriendshipSequenceFactory::friendshipClimax()
{
    Sequence seq = buildSequence(
        8, 4, 0, "Climax", songTempo, true,
        {
            SequenceTrackFactory::kickFour,
            SequenceTrackFactory::snareFour,
            FriendshipTrackFactory::friendshipHats,
            FriendshipTrackFactory::friendshipTranceB,
            FriendshipTrackFactory::friendshipAndBravery,
            FriendshipTrackFactory::friendshipBass,
            FriendshipTrackFactory::friendshipJungle,
            FriendshipTrackFactory::friendshipStabz,
            track(FriendshipTrackFactory::friendshipOpenH909).muted(),
            track(FriendshipTrackFactory::friendshipRiser).muted().withMuteEvent(0).asFill(),
        });
    return seq;
}

Sequence FriendshipSequenceFactory::friendshipEnd()
{
    Sequence seq = buildSequence(
        8, 4, 0, "End", songTempo, true,
        {
            FriendshipTrackFactory::friendshipTranceB,
            FriendshipTrackFactory::friendshipAndBravery,
            track(FriendshipTrackFactory::friendshipBass).withMuteEvent(TICK(0,0,1)),
            FriendshipTrackFactory::friendshipJungle,
            FriendshipTrackFactory::friendshipStabz,
            track(FriendshipTrackFactory::friendshipCrash).withMuteEvent(TICK(1)),
        });
    return seq;
}

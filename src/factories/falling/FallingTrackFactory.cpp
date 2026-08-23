#include "FallingTrackFactory.h"

#include "factories/falling/FallingPatterns.h"

#include "factories/DrumPatterns.h"
#include "factories/TrackPatternBuilder.h"
#include "MidiChannel.h"
#include "TickHelper.h"
#include "factories/MidiNotes.h"


namespace
{
constexpr uint8_t riz = 52;
constexpr uint8_t bigClap = 39;

constexpr uint8_t rim = 45;
constexpr uint8_t tom = 44;

constexpr uint8_t riz2 = 53;
constexpr uint8_t tomFill = 55;

constexpr uint8_t interlude = 65;

constexpr uint8_t pianoLow = 68;
constexpr uint8_t pianoHi = 67;

}

SequenceTrack FallingTrackFactory::fallingHats(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("Hats", MidiChannel::kDrums);
    track.setPattern(FallingPatterns::kFallingHats, lengthInTicks, startInTicks);
    return track;
}

SequenceTrack FallingTrackFactory::fallingPads(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("Pads", MidiChannel::kSampler);
    track.setPattern(FallingPatterns::kFallingPads, lengthInTicks, startInTicks);
    return track;
}

SequenceTrack FallingTrackFactory::fallingKick(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("Kick", MidiChannel::kSampler);
    track.setPattern(FallingPatterns::kFallingKick, lengthInTicks, startInTicks);
    return track;
}

SequenceTrack FallingTrackFactory::fallingRiser(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("Riser", MidiChannel::kSampler);

    track.addNote(lengthInTicks - 2 * TickHelper::kOneBarTick4_4, TickHelper::kStepLen, riz, 127);

    return track;
}

SequenceTrack FallingTrackFactory::fallingBass(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("Bass", MidiChannel::kBass);
    track.setPattern(FallingPatterns::kFallingBass, lengthInTicks, startInTicks);
    return track;
}

SequenceTrack FallingTrackFactory::fallingBigClap(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("BigClap", MidiChannel::kDrums);
     
    SequenceDesc desc;
    desc.notes = {
        {}, {}, {}, {}, {}, {}, {}, {},
        {}, {}, {}, {}, {}, {}, {}, {},
        {}, {}, {}, {}, {}, {}, {}, {},
        {}, {}, {}, {}, {}, {}, {}, {},

        {}, {}, {}, {}, {}, {}, {}, {},
        {}, {}, {}, {}, {}, {}, {}, {},
        {}, {}, {}, {}, {}, {}, {}, {},
        {}, {}, {}, {}, {}, {}, {bigClap}, {bigClap}
    };
    desc.rate = 8;
    makeSequenceTrack(track, desc, lengthInTicks, startInTicks);

    return track;
}

SequenceTrack FallingTrackFactory::fallingHarp(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("Harp", MidiChannel::kMicrofreak);
    track.setPattern(FallingPatterns::kFallingHarp, lengthInTicks, startInTicks);

    return track;
}

SequenceTrack FallingTrackFactory::fallingTambourin(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("Tambourin", MidiChannel::kDrums);
    track.setPattern(FallingPatterns::kFallingTambourin, lengthInTicks, startInTicks);

    return track;
}

SequenceTrack FallingTrackFactory::fallingPreInterlude(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("PreInterlude", MidiChannel::kSampler);

    track.addNote(0, TickHelper::kStepLen, pianoLow, 127);
    track.addNote(TickHelper::bars(3), TickHelper::kStepLen, riz2, 127);
    track.addNote(TICK(3, 2, 3), TickHelper::kStepLen, tomFill, 127);
    return track;
}

SequenceTrack FallingTrackFactory::fallingInterlude(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("Interlude", MidiChannel::kSampler);
    track.addNote(0, TickHelper::kStepLen, interlude, 127);
    return track;
}

SequenceTrack FallingTrackFactory::fallingSnareFill(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("SnareFill", MidiChannel::kDrums);

    uint8_t snr = 37;

    SequenceDesc desc;
    desc.notes = {
        {snr}, {snr},
        {snr}, {}, {}, {snr},
        {}, {}, {snr}, {snr}, 
        {}, {}, {snr}, {},
        {snr}, {snr}, {}, {}};
    desc.rate = 16;

    desc.velocities = {
        60,90,
        127,127,
        127,127,
        127,
        127,127};

    tick_t fillLen = desc.notes.size() * TickHelper::kStepLen;
    makeSequenceTrack(track, desc, fillLen, lengthInTicks - fillLen);

    return track;
}

SequenceTrack FallingTrackFactory::fallingHandTamb(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("HandTamb", MidiChannel::kSampler);
    track.setPattern(FallingPatterns::kFallingHandTamb, lengthInTicks, startInTicks);
    return track;
}

SequenceTrack FallingTrackFactory::fallingKickFill(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("KickFill", MidiChannel::kDrums);

    uint8_t kick = 36;

    SequenceDesc desc;
    desc.notes = {{kick}, {}};
    desc.rate = 16;

    tick_t fillLen = desc.notes.size() * TickHelper::kStepLen;
    makeSequenceTrack(track, desc, fillLen, lengthInTicks - fillLen);

    return track;
}

SequenceTrack FallingTrackFactory::fallingPiano(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("Piano", MidiChannel::kSampler);

    SequenceDesc desc;
    desc.notes = {
        {pianoLow}, {}, 
        {}, {},
        {}, {},
        {}, {pianoHi},
    
        {}, {}, {}, {}, {}, {}, {}, {},
        {}, {}, {}, {}, {}, {}, {}, {},
        {}, {}, {}, {}, {}, {}, {}, {},
    
        {pianoLow}, {}, 
        {}, {},
        {}, {},
        {}, {},

        {}, {}, {}, {}, {}, {}, {}, {},
        {}, {}, {}, {}, {}, {}, {}, {},
        {}, {}, {}, {}, {}, {}, {}, {},

    };
    desc.rate = 8;
    makeSequenceTrack(track, desc, lengthInTicks, startInTicks);

    return track;
}
SequenceTrack FallingTrackFactory::fallingRimTom(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("RimTom", MidiChannel::kDrums);

    SequenceDesc desc;
    desc.notes = {
        {}, {}, {}, {},
        {}, {}, {}, {},
        {}, {}, {}, {rim},
        {}, {}, {rim}, {},

        {}, {}, {}, {},
        {}, {}, {}, {},
        {}, {}, {}, {rim},
        {}, {}, {rim}, {},

        {}, {}, {}, {},
        {}, {}, {}, {},
        {}, {}, {}, {rim},
        {}, {}, {rim}, {},

        {}, {}, {}, {},
        {}, {}, {rim}, {rim},
        {}, {rim}, {rim}, {rim, tom},
        {}, {}, {rim, tom}, {}
    };
    desc.rate = 16;
    makeSequenceTrack(track, desc, lengthInTicks, startInTicks);

    return track;
}

SequenceTrack FallingTrackFactory::fallingSynthEnd(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("SynthEnd", MidiChannel::kPoly);

    SequenceDesc desc;
    desc.notes = {
        {B4}, {},
        {}, {},
        {A4}, {},
        {}, {},

        {Gd4}, {},
        {}, {},
        {E4}, {},
        {}, {},

        {B3}, {},
        {}, {},
        {}, {},
        {B3}, {Fd4},

        {}, {},
        {}, {},
        {}, {},
        {}, {},

        {B4}, {},
        {}, {},
        {A4}, {},
        {}, {},

        {Gd4}, {},
        {}, {},
        {E4}, {},
        {}, {},

        {B3}, {},
        {}, {},
        {}, {},
        {Gd4}, {Fd4},

        {}, {},
        {}, {},
        {}, {},
        {}, {},

    };
    desc.rate = 8;
    makeSequenceTrack(track, desc, lengthInTicks, startInTicks);

    return track;
}

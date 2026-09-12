#include "SequenceTrackFactory.h"

#include "DrumPatterns.h"
#include "TrackPatternBuilder.h"

#include "MidiConst.h"
#include "MidiNotes.h"

SequenceTrack SequenceTrackFactory::sampler(tick_t lengthInTicks, tick_t startInTicks)
{
    SequenceTrack track("Sampler", MidiChannel::kSampler);
    return track;
}


SequenceTrack SequenceTrackFactory::kickFour(tick_t lengthInTicks, tick_t startInTicks)
{
    SequenceTrack track("Kick", MidiChannel::kDrums);
    track.setPattern(DrumPatterns::kKickFour, lengthInTicks, startInTicks);
    return track;
}

SequenceTrack SequenceTrackFactory::clapFour(tick_t lengthInTicks, tick_t startInTicks)
{
    SequenceTrack track("Clap", MidiChannel::kDrums);
    track.setPattern(DrumPatterns::kSnareFour, lengthInTicks, startInTicks);
    return track;
}

SequenceTrack SequenceTrackFactory::snareFour(tick_t lengthInTicks, tick_t startInTicks)
{
    SequenceTrack track("Snare", MidiChannel::kDrums);
    track.setPattern(DrumPatterns::kSnareFour, lengthInTicks, startInTicks);
    return track;
}

SequenceTrack SequenceTrackFactory::rideOff(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("Ride", MidiChannel::kDrums);
    track.setPattern(DrumPatterns::kRideOff, lengthInTicks, startInTicks);
    return track;
}

SequenceTrack SequenceTrackFactory::gtrPedal(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("HXStomp", MidiChannel::kGtrPedal);
    return track;
}

SequenceTrack SequenceTrackFactory::gtrLoop(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("GtrLoop", MidiChannel::kGtrLoop);
    return track;
}

SequenceTrack SequenceTrackFactory::gtrLoopMute(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("GtrLoop Mute", MidiChannel::kGtrLoop);
    track.addControlChange({ startInTicks, BossRC::kVolume_cc, 0 });
    return track;
}

SequenceTrack SequenceTrackFactory::gtrLoopUnmute(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("GtrLoop Unmute", MidiChannel::kGtrLoop);
    track.addControlChange({ startInTicks, BossRC::kVolume_cc, 65 });
    return track;
}

SequenceTrack SequenceTrackFactory::gtrLoopErase(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("GtrLoop Erase", MidiChannel::kGtrLoop);
    track.addControlChange({ startInTicks, BossRC::kErase_cc, 0 });
    track.addControlChange({ static_cast<tick_t>(startInTicks + 2), BossRC::kErase_cc, 127 });
    return track;
}

SequenceTrack SequenceTrackFactory::polySynth(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("PolySynth", MidiChannel::kPoly);
    return track;
}

SequenceTrack SequenceTrackFactory::bass(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("Bass", MidiChannel::kBass);
    return track;
}

SequenceTrack SequenceTrackFactory::vocoder(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("Vocoder", MidiChannel::kVocoder);
    return track;
}

SequenceTrack SequenceTrackFactory::microfreak(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("Microfreak", MidiChannel::kMicrofreak);
    return track;
}

SequenceTrack SequenceTrackFactory::midiLoop(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("MidiLoop", MidiChannel::kMidiLoop);
    return track;
}

SequenceTrack SequenceTrackFactory::modularA(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("Modular", MidiChannel::kModularA);
    return track;
}

SequenceTrack SequenceTrackFactory::drumMachine(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("DrumMachine", MidiChannel::kDrumMachine);
    return track;
}

SequenceTrack SequenceTrackFactory::matrix(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("Matrix", MidiChannel::kMatrix);
    return track;
}

SequenceTrack SequenceTrackFactory::matrixKill(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track = matrix(lengthInTicks, startInTicks);
    track.addProgramChange({ 0, LedMatrix::kKill });
    return track;
}

SequenceTrack SequenceTrackFactory::ledStrips(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("LedStrips", MidiChannel::kLedStrips);
    return track;
}

SequenceTrack SequenceTrackFactory::ledStripsTest(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("LedStrips", MidiChannel::kLedStrips);

    SequenceDesc desc;
    desc.notes = {
        {LedStrips::kRed_A}, {LedStrips::kGreen_A}, {LedStrips::kBlue_A}, {LedStrips::kWhite_A},
        {LedStrips::kRed_B}, {LedStrips::kGreen_B}, {LedStrips::kBlue_B}, {LedStrips::kWhite_B},
        {LedStrips::kRed_C}, {LedStrips::kGreen_C}, {LedStrips::kBlue_C}, {LedStrips::kWhite_C},
        {LedStrips::kRed_D}, {LedStrips::kGreen_D}, {LedStrips::kBlue_D}, {LedStrips::kWhite_D},
    };
    desc.rate = 4;
    makeSequenceTrack(track, desc, lengthInTicks, startInTicks);

    return track;
}
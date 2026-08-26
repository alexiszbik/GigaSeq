#include "SequenceTrackFactory.h"

#include "DrumPatterns.h"
#include "TrackPatternBuilder.h"

#include "MidiConst.h"
#include "MidiNotes.h"

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


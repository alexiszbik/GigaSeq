#include "WaterTrackFactory.h"

#include "factories/SequenceTrackFactory.h"
#include "factories/TrackPatternBuilder.h"
#include "MidiChannel.h"
#include "factories/MidiNotes.h"

namespace
{
constexpr tick_t oneBarTick = 384;
}

SequenceTrack WaterTrackFactory::waterMarimba(tick_t lengthInTicks) {
    SequenceTrack track("Marimba", MidiChannel::kDrums);

    SequenceDesc desc;
    //TODO : might be a better way to do it
    desc.notes = {{55}};
    desc.rate = 0.25;
    makeSequenceTrack(track, desc, lengthInTicks);

    return track;
}

SequenceTrack WaterTrackFactory::waterHats(tick_t lengthInTicks) {
    SequenceTrack track("Hats", MidiChannel::kDrums);

    SequenceDesc desc;
    //TODO : might be a better way to do it
    desc.notes = {{}, {40}, {40}, {40}};
    desc.velocities = {55, 127, 55};
    desc.rate = 16;
    makeSequenceTrack(track, desc, lengthInTicks);

    return track;
}

SequenceTrack WaterTrackFactory::waterFreak(tick_t lengthInTicks) {
    SequenceTrack track("Freak", MidiChannel::kMicrofreak);

    SequenceDesc desc;
    uint8_t note = Eb2;
    desc.notes = {{}, {note}, {}, {note}, {}, {}, {}, {}};
    desc.rate = 16;
    makeSequenceTrack(track, desc, lengthInTicks);

    return track;
}

SequenceTrack WaterTrackFactory::waterBass(tick_t lengthInTicks) {
    SequenceTrack track("Bass", MidiChannel::kBass);

    SequenceDesc desc;
    uint8_t note = Eb1;
    desc.notes = {{}, {}, {note}, {note}};
    desc.rate = 16;
    makeSequenceTrack(track, desc, lengthInTicks);

    return track;
}

SequenceTrack WaterTrackFactory::waterChorus(tick_t lengthInTicks) {
    SequenceTrack track("Chorus", MidiChannel::kSampler);

    SequenceDesc desc;
    desc.notes = {{56}};
    desc.rate = 0.125;
    makeSequenceTrack(track, desc, lengthInTicks);

    return track;
}

SequenceTrack WaterTrackFactory::waterXmas(tick_t lengthInTicks) {
    SequenceTrack track("Xmas", MidiChannel::kSampler);

    SequenceDesc desc;
    uint8_t note = 45;
    desc.notes = {
        {}, {}, {note}, {},
        {}, {}, {note}, {},
        {}, {}, {note}, {},
        {}, {note}, {note}, {},
    };
    desc.velocities = {127, 127, 127, 60, 127};
    desc.rate = 16;
    makeSequenceTrack(track, desc, lengthInTicks);

    return track;
}

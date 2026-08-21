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
    desc.notes = {{}, {40}, {40}, {40}};
    desc.velocities = {55, 127, 55};
    desc.rate = 16;
    makeSequenceTrack(track, desc, lengthInTicks);

    return track;
}

SequenceTrack WaterTrackFactory::waterFreak(tick_t lengthInTicks) {
    SequenceTrack track("Freak", MidiChannel::kMicrofreak);

    SequenceDesc desc;
    uint8_t note = Eb1;
    desc.notes = {{}, {note}, {}, {note}, {}, {}, {}, {}};
    desc.rate = 16;
    makeSequenceTrack(track, desc, lengthInTicks);

    return track;
}

SequenceTrack WaterTrackFactory::waterBass(tick_t lengthInTicks) {
    SequenceTrack track("Bass", MidiChannel::kBass);

    SequenceDesc desc;
    uint8_t note = Eb2;
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

SequenceTrack WaterTrackFactory::waterCongas(tick_t lengthInTicks) {
    SequenceTrack track("Congas", MidiChannel::kDrums);

    SequenceDesc desc;
    desc.notes = {
        {}, {43}, {44}, {44},
        {44}, {44}, {43}, {43}
    };
    desc.velocities = {55, 127, 112, 45, 30, 112, 28};
    desc.rate = 16;
    makeSequenceTrack(track, desc, lengthInTicks);

    return track;
}

SequenceTrack WaterTrackFactory::waterClaves(tick_t lengthInTicks) {
    SequenceTrack track("Claves", MidiChannel::kDrums);

    SequenceDesc desc;
    uint8_t note = 46;
    desc.notes = {
        {}, {note}, {}, {}, 
        {}, {}, {}, {},
        {}, {}, {}, {},
        {}, {}, {}, {},
    };
    desc.rate = 4;
    makeSequenceTrack(track, desc, lengthInTicks);

    return track;
}

SequenceTrack WaterTrackFactory::waterFm(tick_t lengthInTicks) {
    SequenceTrack track("Fm", MidiChannel::kSampler);

    SequenceDesc desc;
    desc.notes = {{65}};
    desc.rate = 0.25;
    makeSequenceTrack(track, desc, lengthInTicks);

    return track;
}

SequenceTrack WaterTrackFactory::waterBalafon(tick_t lengthInTicks) {
    SequenceTrack track("Balafon", MidiChannel::kSampler);

    SequenceDesc desc;
    desc.notes = {{62}, {63}, {64}};
    desc.rate = 16;
    makeSequenceTrack(track, desc, lengthInTicks);

    return track;
}

SequenceTrack WaterTrackFactory::waterShakes(tick_t lengthInTicks) {
    SequenceTrack track("Shakes", MidiChannel::kSampler);

    SequenceDesc desc;
    desc.notes = {{}, {41}, {41}, {41}};
    desc.velocities = {55, 127, 55};
    desc.rate = 16;
    makeSequenceTrack(track, desc, lengthInTicks);

    return track;
}

SequenceTrack WaterTrackFactory::waterFmbass(tick_t lengthInTicks) {
    SequenceTrack track("Fmbass", MidiChannel::kModularB);

    SequenceDesc desc;
    desc.notes = {
        {}, {}, {}, {},
        {}, {}, {}, {},
        {}, {}, {}, {},
        {}, {}, {}, {},

        {}, {}, {}, {},
        {}, {}, {}, {},
        {}, {}, {Gd2}, {Gd2},
        {Ad2}, {Ad2}, {Cd3}, {Cd3},

        {}, {}, {}, {},
        {}, {}, {}, {},
        {}, {}, {}, {},
        {}, {}, {}, {},

        {}, {}, {}, {},
        {}, {}, {}, {},
        {}, {}, {Gd2}, {Gd2},
        {Ad2}, {Ad2}, {Cd3}, {Cd3},

        {}, {}, {}, {},
        {}, {}, {}, {},
        {}, {}, {}, {},
        {}, {}, {}, {},

        {}, {}, {}, {},
        {}, {}, {}, {},
        {}, {}, {Cd3}, {Cd3},
        {Ad2}, {Ad2}, {Cd3}, {Cd3},

        {}, {}, {}, {},
        {}, {}, {}, {},
        {}, {}, {}, {},
        {}, {}, {}, {},

        {}, {}, {}, {},
        {}, {}, {}, {},
        {}, {}, {Gd2}, {Gd2},
        {Ad2}, {Ad2}, {Cd3}, {Cd3},
        };
    desc.rate = 16;
    makeSequenceTrack(track, desc, lengthInTicks);

    return track;
}

SequenceTrack WaterTrackFactory::waterKickPreChorus(tick_t lengthInTicks) {
    SequenceTrack track("KickPreChorus", MidiChannel::kDrums);

    SequenceDesc desc;
    desc.notes = {
        {36}, {36}, {36}, {36},
        {36}, {36}, {36}, {36},
        {36}, {36}, {36}, {36},
        {36}, {36}, {36}, {36},

        {36}, {36}, {36}, {36},
        {36}, {36}, {36}, {36},
        {36}, {36}, {36}, {36},
        {36}, {}, {}, {36},
    };
    desc.rate = 4;
    makeSequenceTrack(track, desc, lengthInTicks);

    return track;
}

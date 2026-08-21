#include "SequenceTrackFactory.h"

#include "TrackPatternBuilder.h"

#include "MidiChannel.h"
#include "MidiNotes.h"

SequenceTrack SequenceTrackFactory::kickFour(tick_t lengthInTicks, tick_t startInTicks)
{
    SequenceTrack track("Kick", MidiChannel::kDrums);

    SequenceDesc desc;
    desc.notes = {{36}};
    desc.rate = 4;
    makeSequenceTrack(track, desc, lengthInTicks, startInTicks);

    return track;
}

SequenceTrack SequenceTrackFactory::snareFour(tick_t lengthInTicks, tick_t startInTicks)
{
    SequenceTrack track("Clap", MidiChannel::kDrums);

    SequenceDesc desc;
    desc.notes = {{}, {38}, {}, {38}};
    desc.rate = 4;
    makeSequenceTrack(track, desc, lengthInTicks, startInTicks);

    return track;
}


SequenceTrack SequenceTrackFactory::createCMaj7Arpeggio(tick_t lengthInTicks, tick_t startInTicks)
{
    SequenceTrack track("abcdefghijklmnopqrstuvwxyz123456789", MidiChannel::kModularA);

    SequenceDesc desc;
    desc.notes = {{60}, {64}, {67}, {71}};
    desc.rate = 4;
    makeSequenceTrack(track, desc, lengthInTicks, startInTicks);

    makeAutomationTrack(track, startInTicks, startInTicks + 96 * 4, 10, 0, 127);
    makeAutomationTrack(track, startInTicks + 96 * 4, startInTicks + 96 * 8, 10, 0, 127);
    makeAutomationTrack(track, startInTicks + 96 * 8, startInTicks + 96 * 12, 10, 0, 127);
    makeAutomationTrack(track, startInTicks + 96 * 12, startInTicks + 96 * 16, 10, 0, 127);

    return track;
}

SequenceTrack SequenceTrackFactory::createAm7Arpeggio(tick_t lengthInTicks, tick_t startInTicks)
{
    SequenceTrack track("Am7 Arpeggio", MidiChannel::kModularA);

    SequenceDesc desc;
    desc.notes = {{57}, {60}, {64}, {67}};
    desc.velocities = {95};
    desc.rate = 4;
    makeSequenceTrack(track, desc, lengthInTicks, startInTicks);

    return track;
}

SequenceTrack SequenceTrackFactory::createKickSnare(tick_t lengthInTicks, tick_t startInTicks)
{
    SequenceTrack track("Kick/Snare", MidiChannel::kDrums);

    SequenceDesc desc;
    desc.notes = {{36}, {36, 38}, {36}, {36, 38}};
    desc.rate = 4;
    makeSequenceTrack(track, desc, lengthInTicks, startInTicks);

    return track;
}

SequenceTrack SequenceTrackFactory::createKickSnareWithHats(tick_t lengthInTicks, tick_t startInTicks)
{
    SequenceTrack track("Kick/Snare + Hats", MidiChannel::kDrums);

    SequenceDesc hats;
    hats.notes = {{42}};
    hats.velocities = {32, 64, 96, 127, 32, 64, 96, 127};
    hats.rate = 16;
    makeSequenceTrack(track, hats, lengthInTicks, startInTicks);

    SequenceDesc drums;
    drums.notes = {
        {36}, {}, {36, 37}, {}, {36}, {}, {36, 37}, {},
        {36}, {}, {36, 37}, {}, {36}, {37}};
    drums.rate = 8;
    makeSequenceTrack(track, drums, lengthInTicks, startInTicks);

    track.addMuteEvent(startInTicks);

    return track;
}

SequenceTrack SequenceTrackFactory::createBassLine(tick_t lengthInTicks, tick_t startInTicks)
{
    SequenceTrack track("Bassline", MidiChannel::kModularA);

    SequenceDesc desc;
    desc.notes = {
        {36}, {36}, {36}, {36},
        {36}, {36}, {36}, {36},
        {36}, {36}, {36}, {36},
        {48}, {48}, {48}, {48},
    };
    desc.velocities = {100};
    desc.rate = 4;
    makeSequenceTrack(track, desc, lengthInTicks, startInTicks);

    return track;
}

SequenceTrack SequenceTrackFactory::createMelodicBass(tick_t lengthInTicks, tick_t startInTicks)
{
    SequenceTrack track("Melodic Bass", MidiChannel::kModularA);

    SequenceDesc desc;
    desc.notes = {{36}, {36}, {43}, {41}, {38}, {38}, {43}, {41}};
    desc.velocities = {110};
    desc.rate = 8;
    makeSequenceTrack(track, desc, lengthInTicks, startInTicks);

    return track;
}

SequenceTrack SequenceTrackFactory::createHiHatPattern(tick_t lengthInTicks, tick_t startInTicks)
{
    SequenceTrack track("Hi-Hat", MidiChannel::kDrums);

    SequenceDesc desc;
    desc.notes = {
        {42}, {}, {42}, {},
        {42}, {46}, {42}, {},
        {42}, {}, {42}, {46},
        {42}, {}, {42}, {},
    };
    desc.velocities = {
        100, 80,
        100, 80, 80,
        100, 80, 100,
        100, 80};
    desc.rate = 16;
    makeSequenceTrack(track, desc, lengthInTicks, startInTicks);

    return track;
}

SequenceTrack SequenceTrackFactory::createSnareBackbeat(tick_t lengthInTicks, tick_t startInTicks)
{
    SequenceTrack track("Snare Backbeat", MidiChannel::kDrums);

    SequenceDesc desc;
    desc.notes = {{}, {37}, {}, {37}};
    desc.velocities = {120};
    desc.rate = 4;
    makeSequenceTrack(track, desc, lengthInTicks, startInTicks);

    return track;
}

SequenceTrack SequenceTrackFactory::createPadChords(tick_t lengthInTicks, tick_t startInTicks)
{
    SequenceTrack track("Pad Chords", MidiChannel::kModularA);

    SequenceDesc desc;
    desc.notes = {
        {}, {60, 64, 67}, {}, {},
        {}, {65, 69, 72}, {}, {},
        {}, {67, 72, 75}, {}, {},
        {}, {60, 64, 67}, {}, {},
    };
    desc.velocities = {70};
    desc.durations = {3};
    desc.rate = 4;
    makeSequenceTrack(track, desc, lengthInTicks, startInTicks);

    return track;
}

SequenceTrack SequenceTrackFactory::createSynthStabs(tick_t lengthInTicks, tick_t startInTicks)
{
    SequenceTrack track("Synth Stabs", MidiChannel::kModularA);

    SequenceDesc desc;
    desc.notes = {{}, {72}, {}, {74}, {}, {76}, {}, {77}};
    desc.velocities = {105};
    desc.rate = 8;
    makeSequenceTrack(track, desc, lengthInTicks, startInTicks);

    return track;
}

SequenceTrack SequenceTrackFactory::createClapBackbeat(tick_t lengthInTicks, tick_t startInTicks)
{
    SequenceTrack track("Clap", MidiChannel::kDrums);

    SequenceDesc desc;
    desc.notes = {{}, {39}, {}, {39}};
    desc.velocities = {115};
    desc.rate = 4;
    makeSequenceTrack(track, desc, lengthInTicks, startInTicks);

    return track;
}

SequenceTrack SequenceTrackFactory::createOpenHat(tick_t lengthInTicks, tick_t startInTicks)
{
    SequenceTrack track("Open Hat", MidiChannel::kDrums);

    SequenceDesc desc;
    desc.notes = {{}, {46}, {}, {46}};
    desc.velocities = {90};
    desc.rate = 4;
    makeSequenceTrack(track, desc, lengthInTicks, startInTicks);

    return track;
}

SequenceTrack SequenceTrackFactory::createTomFill(tick_t lengthInTicks, tick_t startInTicks)
{
    SequenceTrack track("Tom Fill", MidiChannel::kDrums);

    SequenceDesc desc;
    desc.notes = {
        {}, {}, {}, {},
        {}, {}, {}, {},
        {50}, {48}, {47}, {45},
        {45}, {47}, {48}, {50},
    };
    desc.velocities = {110};
    desc.rate = 16;
    makeSequenceTrack(track, desc, lengthInTicks, startInTicks);

    return track;
}

SequenceTrack SequenceTrackFactory::createRimshot(tick_t lengthInTicks, tick_t startInTicks)
{
    SequenceTrack track("Rimshot", MidiChannel::kDrums);

    SequenceDesc desc;
    desc.notes = {{37}, {}, {37}, {}, {37}, {}, {37}, {}};
    desc.velocities = {95};
    desc.rate = 8;
    makeSequenceTrack(track, desc, lengthInTicks, startInTicks);

    return track;
}

SequenceTrack SequenceTrackFactory::createCymbalRide(tick_t lengthInTicks, tick_t startInTicks)
{
    SequenceTrack track("Ride", MidiChannel::kDrums);

    SequenceDesc desc;
    desc.notes = {{51}, {51}, {51}, {51}};
    desc.velocities = {70, 85, 70, 90};
    desc.rate = 4;
    makeSequenceTrack(track, desc, lengthInTicks, startInTicks);

    return track;
}

SequenceTrack SequenceTrackFactory::createTambourine(tick_t lengthInTicks, tick_t startInTicks)
{
    SequenceTrack track("Tambourine", MidiChannel::kDrums);

    SequenceDesc desc;
    desc.notes = {{54}, {54}, {54}, {54}, {54}, {54}, {54}, {54}};
    desc.velocities = {100, 60, 100, 60, 100, 60, 100, 60};
    desc.rate = 8;
    makeSequenceTrack(track, desc, lengthInTicks, startInTicks);

    return track;
}

SequenceTrack SequenceTrackFactory::createShaker(tick_t lengthInTicks, tick_t startInTicks)
{
    SequenceTrack track("Shaker", MidiChannel::kDrums);

    SequenceDesc desc;
    desc.notes = {
        {70}, {}, {70}, {},
        {70}, {}, {70}, {},
        {70}, {}, {70}, {},
        {70}, {}, {70}, {},
    };
    desc.velocities = {80, 50};
    desc.rate = 16;
    makeSequenceTrack(track, desc, lengthInTicks, startInTicks);

    return track;
}

SequenceTrack SequenceTrackFactory::createClave(tick_t lengthInTicks, tick_t startInTicks)
{
    SequenceTrack track("Clave", MidiChannel::kDrums);

    SequenceDesc desc;
    desc.notes = {{75}, {}, {}, {75}, {}, {75}, {}, {}};
    desc.velocities = {105};
    desc.rate = 8;
    makeSequenceTrack(track, desc, lengthInTicks, startInTicks);

    return track;
}

SequenceTrack SequenceTrackFactory::createCowbell(tick_t lengthInTicks, tick_t startInTicks)
{
    SequenceTrack track("Cowbell", MidiChannel::kDrums);

    SequenceDesc desc;
    desc.notes = {{56}, {}, {56}, {}};
    desc.velocities = {120};
    desc.rate = 4;
    makeSequenceTrack(track, desc, lengthInTicks, startInTicks);

    return track;
}

SequenceTrack SequenceTrackFactory::createChordStab(tick_t lengthInTicks, tick_t startInTicks)
{
    SequenceTrack track("Chord Stab", MidiChannel::kModularA);

    SequenceDesc desc;
    desc.notes = {
        {}, {60, 63, 67}, {}, {},
        {}, {65, 69, 72}, {}, {},
        {}, {60, 63, 67}, {}, {60, 63, 67},
        {}, {65, 69, 72}, {}, {},
    };
    desc.velocities = {100};
    desc.durations = {1};
    desc.rate = 4;
    makeSequenceTrack(track, desc, lengthInTicks, startInTicks);

    return track;
}

SequenceTrack SequenceTrackFactory::createPluck(tick_t lengthInTicks, tick_t startInTicks)
{
    SequenceTrack track("Pluck", MidiChannel::kModularB);

    SequenceDesc desc;
    desc.notes = {{72}, {}, {76}, {}, {79}, {}, {76}, {}};
    desc.velocities = {85};
    desc.rate = 8;
    makeSequenceTrack(track, desc, lengthInTicks, startInTicks);

    return track;
}

SequenceTrack SequenceTrackFactory::createLead(tick_t lengthInTicks, tick_t startInTicks)
{
    SequenceTrack track("Lead", MidiChannel::kModularB);

    SequenceDesc desc;
    desc.notes = {{76}, {77}, {79}, {81}, {79}, {77}, {76}, {74}};
    desc.velocities = {95};
    desc.rate = 8;
    makeSequenceTrack(track, desc, lengthInTicks, startInTicks);

    return track;
}

SequenceTrack SequenceTrackFactory::createSubBass(tick_t lengthInTicks, tick_t startInTicks)
{
    SequenceTrack track("Sub Bass", MidiChannel::kBass);

    SequenceDesc desc;
    desc.notes = {{36}, {36}, {36}, {36}, {36}, {36}, {36}, {41}};
    desc.velocities = {120};
    desc.rate = 8;
    makeSequenceTrack(track, desc, lengthInTicks, startInTicks);

    return track;
}

SequenceTrack SequenceTrackFactory::createPadSwells(tick_t lengthInTicks, tick_t startInTicks)
{
    SequenceTrack track("Pad Swell", MidiChannel::kPoly);

    SequenceDesc desc;
    desc.notes = {
        {}, {60, 64, 67}, {}, {},
        {}, {62, 65, 69}, {}, {},
        {}, {64, 67, 71}, {}, {},
        {}, {65, 69, 72}, {}, {},
    };
    desc.velocities = {60};
    desc.durations = {3};
    desc.rate = 4;
    makeSequenceTrack(track, desc, lengthInTicks, startInTicks);

    makeAutomationTrack(track, startInTicks, startInTicks + 96 * 4, 7, 0, 110);
    makeAutomationTrack(track, startInTicks + 96 * 4, startInTicks + 96 * 8, 7, 110, 40);
    makeAutomationTrack(track, startInTicks + 96 * 8, startInTicks + 96 * 12, 7, 40, 110);
    makeAutomationTrack(track, startInTicks + 96 * 12, startInTicks + 96 * 16, 7, 110, 0);

    return track;
}

SequenceTrack SequenceTrackFactory::createFxBleep(tick_t lengthInTicks, tick_t startInTicks)
{
    SequenceTrack track("FX Bleep", MidiChannel::kFM);

    SequenceDesc desc;
    desc.notes = {
        {}, {}, {}, {},
        {}, {}, {}, {},
        {}, {}, {}, {},
        {}, {}, {96}, {99},
    };
    desc.velocities = {127};
    desc.rate = 16;
    makeSequenceTrack(track, desc, lengthInTicks, startInTicks);

    return track;
}

SequenceTrack SequenceTrackFactory::createArpFast(tick_t lengthInTicks, tick_t startInTicks)
{
    SequenceTrack track("Arp Fast", MidiChannel::kModularA);

    SequenceDesc desc;
    desc.notes = {{60}, {64}, {67}, {72}, {67}, {64}, {60}, {64}};
    desc.velocities = {90};
    desc.rate = 16;
    makeSequenceTrack(track, desc, lengthInTicks, startInTicks);

    return track;
}

SequenceTrack SequenceTrackFactory::createGtrChug(tick_t lengthInTicks, tick_t startInTicks)
{
    SequenceTrack track("Gtr Chug", MidiChannel::kGtrPedal);

    SequenceDesc desc;
    desc.notes = {
        {40}, {40}, {40}, {40},
        {40}, {40}, {40}, {40},
        {40}, {40}, {40}, {40},
        {40}, {40}, {40}, {40},
    };
    desc.velocities = {110, 80};
    desc.durations = {1};
    desc.rate = 16;
    makeSequenceTrack(track, desc, lengthInTicks, startInTicks);

    return track;
}

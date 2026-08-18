#include "SequenceTrackFactory.h"

#include "MidiNotes.h"
#include "MidiChannel.h"
#include "Sequence.h"
#include "Tick.h"

#include <cstdint>
#include <vector>

namespace
{

//For together, maybe but it elsewhere after
constexpr tick_t oneBarTick = 384;
constexpr tick_t vocoderLength = 32*oneBarTick;
constexpr tick_t repeatPartLength = 4*oneBarTick;

struct SequenceDesc
{
    std::vector<std::vector<uint8_t>> notes;
    std::vector<uint8_t> velocities;
    std::vector<uint8_t> durations;
    double rate = 4;
};

void makeSequenceTrack(
    SequenceTrack& track,
    const SequenceDesc& desc,
    tick_t lengthInTicks,
    tick_t startTick = 0)
{
    const int barDuration = Sequence::kTicksPerQuarterNote * 4;
    const int stepDuration = barDuration / desc.rate;

    const int seqSize = static_cast<int>(desc.notes.size());
    int seqIdx = 0;

    const int velSize = static_cast<int>(desc.velocities.size());
    int velIdx = 0;

    const int durationSize = static_cast<int>(desc.durations.size());
    int durIdx = 0;

    for (tick_t tick = startTick; tick < (startTick + lengthInTicks); tick = static_cast<tick_t>(tick + stepDuration))
    {
        int noteDuration = stepDuration;
        const std::vector<uint8_t>& stepNotes = desc.notes[seqIdx];

        uint8_t velocity = 127;
        if (velIdx < velSize) {
            velocity = desc.velocities[velIdx];
        }

        if (durIdx < durationSize) {
            noteDuration *= desc.durations[durIdx];
        }

        bool noteExists = false;

        for (uint8_t note : stepNotes) {
            track.addNote(tick, noteDuration, note, velocity);
            noteExists = true;
        }

        seqIdx = (seqIdx + 1) % seqSize;

        if (noteExists) {
            if (velSize > 0) {
                velIdx = (velIdx + 1) % velSize;
            }

            if (durationSize > 0) {
                durIdx = (durIdx + 1) % durationSize;
            }
        }
    }
}

void makeAutomationTrack(
    SequenceTrack& track,
    tick_t startInTicks,
    tick_t endInTicks,
    uint8_t controller,
    uint8_t startValue,
    uint8_t endValue)
{
    if (startInTicks > endInTicks) {
        return;
    }

    if (startInTicks == endInTicks) {
        track.addControlChange(startInTicks, controller, endValue);
        return;
    }

    const tick_t duration = endInTicks - startInTicks;
    uint8_t lastSentValue = startValue;

    track.addControlChange(startInTicks, controller, startValue);

    for (tick_t tick = startInTicks + 1; tick < endInTicks; ++tick) {
        const tick_t delta = tick - startInTicks;
        const int range = static_cast<int>(endValue) - startValue;

        const uint8_t value = static_cast<uint8_t>(
            startValue + range * static_cast<int>(delta) / static_cast<int>(duration));

        if (value != lastSentValue) {
            track.addControlChange(tick, controller, value);
            lastSentValue = value;
        }
    }

    track.addControlChange(endInTicks, controller, endValue);
}

} // namespace

SequenceTrack SequenceTrackFactory::togetherArp(tick_t lengthInTicks) {
    SequenceTrack track("Modular", MidiChannel::kModularA);

    SequenceDesc desc;
    desc.notes = {
        {Gd4}, {Gd3}, {Gd2}, {Gd3}, {Gd4}, {Gd3}, {Gd2}, {Gd3}, {Gd4}, {Gd3}, {Gd2}, {Gd3}, {Gd4}, {Gd3}, {Gd2}, {Gd3},
        {Gd4}, {Gd3}, {Gd2}, {Gd3}, {Gd4}, {Gd3}, {Gd2}, {Gd3}, {Gd4}, {Gd3}, {Gd2}, {Gd3}, {Gd4}, {Gd3}, {Gd2}, {Gd3},
        {Gd4}, {Gd3}, {Gd2}, {Gd3}, {Gd4}, {Gd3}, {Gd2}, {Gd3}, {Gd4}, {Gd3}, {Gd2}, {Gd3}, {Gd4}, {Gd3}, {Gd2}, {Gd3},
        {Gd4}, {Gd3}, {Gd2}, {Gd3}, {Gd4}, {Gd3}, {Gd2}, {Gd3}, {Gd4}, {Gd3}, {Gd2}, {Gd3}, {Gd4}, {Gd3}, {Gd2}, {Gd3},
        {C4}, {C3}, {C2}, {C3}, {C4}, {C3}, {C2}, {C3}, {C4}, {C3}, {C2}, {C3}, {C4}, {C3}, {C2}, {C3}, 
        {C4}, {C3}, {C2}, {C3}, {C4}, {C3}, {C2}, {C3}, {C4}, {C3}, {C2}, {C3}, {C4}, {C3}, {C2}, {C3}, 
        {C4}, {C3}, {C2}, {C3}, {C4}, {C3}, {C2}, {C3}, {C4}, {C3}, {C2}, {C3}, {C4}, {C3}, {C2}, {C3}, 
        {C4}, {C3}, {C2}, {C3}, {C4}, {C3}, {C2}, {C3}, {C4}, {C3}, {C2}, {C3}, {C4}, {C3}, {C2}, {C3}
    };
    desc.rate = 16;
    makeSequenceTrack(track, desc, lengthInTicks);

    return track;
}

SequenceTrack SequenceTrackFactory::togetherHiDrum(tick_t lengthInTicks)
{
    SequenceTrack track("Hi Drum", MidiChannel::kDrums);

    SequenceDesc desc;
    desc.notes = {{56}};
    desc.rate = 2;
    makeSequenceTrack(track, desc, lengthInTicks);

    desc.notes = {{37}};
    desc.rate = 4;
    makeSequenceTrack(track, desc, lengthInTicks);

    desc.notes = {{}, {38}};
    desc.rate = 4;
    makeSequenceTrack(track, desc, lengthInTicks);

    desc.notes = {{40}};
    desc.velocities = {127, 56};
    desc.rate = 8;
    makeSequenceTrack(track, desc, lengthInTicks);

    return track;
}

SequenceTrack SequenceTrackFactory::togetherSample(tick_t lengthInTicks)
{
    SequenceTrack track("Sample", MidiChannel::kSampler);

    SequenceDesc desc;
    desc.notes = {{52}, {52}, {53}, {53}};
    desc.rate = 0.5;
    makeSequenceTrack(track, desc, lengthInTicks);

    return track;
}

SequenceTrack SequenceTrackFactory::togetherDX7(tick_t lengthInTicks)
{
    SequenceTrack track("DX7", MidiChannel::kSampler);

    SequenceDesc desc;
    desc.notes = {
        {58}, {58}, {58}, {58}, {58}, {58}, {58}, {58},
        {58}, {58}, {58}, {58}, {58}, {58}, {58}, {58},
        {58}, {58}, {58}, {58}, {58}, {58}, {58}, {58},
        {58}, {58}, {58}, {58}, {58}, {58}, {58}, {58},
        {59}, {59}, {59}, {59}, {59}, {59}, {59}, {59},
        {59}, {59}, {59}, {59}, {59}, {59}, {59}, {59},
        {59}, {59}, {59}, {59}, {59}, {59}, {59}, {59},
        {59}, {59}, {59}, {59}, {59}, {59}, {59}, {59},
    };
    desc.rate = 8;
    makeSequenceTrack(track, desc, lengthInTicks);

    return track;
}

SequenceTrack SequenceTrackFactory::togetherVocoder(tick_t lengthInTicks)
{
    SequenceTrack track("Vocoder", MidiChannel::kVocoder);

    SequenceDesc desc;
    desc.notes = {
        {C3, Eb3, Bb3}, {}, {}, {C3, Eb3, Ab3}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, 
        {C3, Eb3, Bb3}, {}, {}, {C3, Eb3, Ab3}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {},
        {C3, Eb3, Ab3}, {}, {}, {C3, Eb3, G3},  {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {},
        {Bb2, Eb3, F3}, {}, {}, {C3, Eb3, G3},  {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}
    };
    desc.rate = 8;
    desc.durations = {3, 11};
    
    makeSequenceTrack(track, desc, oneBarTick*16);

    return track;
}

SequenceTrack SequenceTrackFactory::togetherVocoderPartArp(tick_t lengthInTicks) {
    auto original = SequenceTrackFactory::togetherArp(vocoderLength + repeatPartLength);

    return original;
}

SequenceTrack SequenceTrackFactory::togetherVocoderPartDX7(tick_t lengthInTicks) {
    auto original = SequenceTrackFactory::togetherDX7(vocoderLength + repeatPartLength);
    
    return original;
}

SequenceTrack SequenceTrackFactory::togetherVocoderPartSample(tick_t lengthInTicks)
{
    auto original = SequenceTrackFactory::togetherSample(vocoderLength);
        
    original.addControlChange(0, 13, 70);
    original.addControlChange(24 * oneBarTick, 13, 127);

    SequenceDesc desc;
    desc.notes = {{52}};
    desc.rate = 4;
    makeSequenceTrack(original, desc, 3*oneBarTick, vocoderLength);

    desc.rate = 8;
    makeSequenceTrack(original, desc, oneBarTick, vocoderLength + 3*oneBarTick);

    original.addNote(vocoderLength + repeatPartLength, 24, 54, 127);

    return original;
}

SequenceTrack SequenceTrackFactory::togetherVocoderPartKick(tick_t lengthInTicks)
{
    auto original = SequenceTrackFactory::kickFour(vocoderLength + 3*oneBarTick);
    original.removeEvents(oneBarTick*16, oneBarTick*8);

    SequenceDesc desc;
    desc.notes = {{36}};
    desc.rate = 8;
    makeSequenceTrack(original, desc, oneBarTick, vocoderLength + 3*oneBarTick);

    return original;
}

SequenceTrack SequenceTrackFactory::togetherVocoderPartHiDrum(tick_t lengthInTicks)
{
    auto original = SequenceTrackFactory::togetherHiDrum(vocoderLength);
    original.removeNotes(oneBarTick*16, oneBarTick*8, {56,37,38});

    SequenceDesc desc;
    desc.notes = {{40}};
    desc.velocities = {127, 56};
    desc.rate = 8;
    makeSequenceTrack(original, desc, 4*oneBarTick, vocoderLength);

    SequenceDesc hiKickDesc;
    hiKickDesc.notes = {{37}};
    hiKickDesc.rate = 4;
    makeSequenceTrack(original, hiKickDesc, 3*oneBarTick, vocoderLength);

    hiKickDesc.rate = 8;
    makeSequenceTrack(original, hiKickDesc, 1*oneBarTick, vocoderLength + 3*oneBarTick);

    return original;
}

SequenceTrack SequenceTrackFactory::togetherVocoderPartExtraBass(tick_t lengthInTicks)
{
    SequenceTrack track("Extra Bass", MidiChannel::kDrums);

    SequenceDesc desc;
    desc.notes = {{57}};
    desc.rate = 4;
    makeSequenceTrack(track, desc, 4*oneBarTick, vocoderLength);

    return track;
}

SequenceTrack SequenceTrackFactory::togetherVocoderPartRiser(tick_t lengthInTicks)
{
    SequenceTrack track("Riser", MidiChannel::kDrums);
    track.addNote(34*oneBarTick, 2*oneBarTick, 60, 127);

    return track;
}

SequenceTrack SequenceTrackFactory::togetherPartBSynth(tick_t lengthInTicks)
{   
    SequenceTrack track("Poly Synth", MidiChannel::kPoly);

    SequenceDesc desc;
    desc.notes = {
        {Ab2, C4, Eb4, Bb4}, {}, {}, {Ab2, C4, Eb4, Ab4}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, 
        {G2, B3, D4, Bb4}, {}, {}, {G2, B3, D4, G4}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {},
        {Bb2, Bb3, D4, F4}, {}, {}, {Bb2, Bb3, D4, G4},  {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {},
        {C3, C4, Eb4, Ab4}, {}, {}, {C3, C4, Eb4, G4},  {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}
    };
    desc.rate = 8;
    desc.durations = {2, 9};
    
    makeSequenceTrack(track, desc, lengthInTicks);

    return track;
}

SequenceTrack SequenceTrackFactory::togetherPartBAh(tick_t lengthInTicks)
{
    SequenceTrack track("Ah", MidiChannel::kSampler);

    SequenceDesc desc;
    desc.notes = {{39}};
    desc.rate = 4;
    makeSequenceTrack(track, desc, lengthInTicks);

    return track;
}

SequenceTrack SequenceTrackFactory::togetherPartBDaDaDa(tick_t lengthInTicks)
{
    SequenceTrack track("DaDaDa", MidiChannel::kDrums);

    SequenceDesc desc;
    desc.notes = {{41}, {42}, {43}, {42}, {41}, {42}, {43}, {43}};
    desc.rate = 8;
    makeSequenceTrack(track, desc, lengthInTicks);

    return track;
}

SequenceTrack SequenceTrackFactory::togetherPartBHat(tick_t lengthInTicks)
{
    SequenceTrack track("Hat", MidiChannel::kDrums);

    SequenceDesc desc;
    desc.notes = {{40}};
    desc.velocities = {127, 56};
    desc.rate = 8;
    makeSequenceTrack(track, desc, lengthInTicks);

    return track;
}


SequenceTrack SequenceTrackFactory::kickFour(tick_t lengthInTicks)
{
    SequenceTrack track("Kick", MidiChannel::kDrums);

    SequenceDesc desc;
    desc.notes = {{36}};
    desc.rate = 4;
    makeSequenceTrack(track, desc, lengthInTicks);

    return track;
}

SequenceTrack SequenceTrackFactory::createCMaj7Arpeggio(tick_t lengthInTicks)
{
    SequenceTrack track("abcdefghijklmnopqrstuvwxyz123456789", MidiChannel::kModularA);

    SequenceDesc desc;
    desc.notes = {{60}, {64}, {67}, {71}};
    desc.rate = 4;
    makeSequenceTrack(track, desc, lengthInTicks);

    makeAutomationTrack(track, 0, 96 * 4, 10, 0, 127);
    makeAutomationTrack(track, 96 * 4, 96 * 8, 10, 0, 127);
    makeAutomationTrack(track, 96 * 8, 96 * 12, 10, 0, 127);
    makeAutomationTrack(track, 96 * 12, 96 * 16, 10, 0, 127);

    return track;
}

SequenceTrack SequenceTrackFactory::createAm7Arpeggio(tick_t lengthInTicks)
{
    SequenceTrack track("Am7 Arpeggio", MidiChannel::kModularA);

    SequenceDesc desc;
    desc.notes = {{57}, {60}, {64}, {67}};
    desc.velocities = {95};
    desc.rate = 4;
    makeSequenceTrack(track, desc, lengthInTicks);

    return track;
}

SequenceTrack SequenceTrackFactory::createKickSnare(tick_t lengthInTicks)
{
    SequenceTrack track("Kick/Snare", MidiChannel::kDrums);

    SequenceDesc desc;
    desc.notes = {{36}, {36, 38}, {36}, {36, 38}};
    desc.rate = 4;
    makeSequenceTrack(track, desc, lengthInTicks);

    return track;
}

SequenceTrack SequenceTrackFactory::createKickSnareWithHats(tick_t lengthInTicks)
{
    SequenceTrack track("Kick/Snare + Hats", MidiChannel::kDrums);

    SequenceDesc hats;
    hats.notes = {{42}};
    hats.velocities = {32, 64, 96, 127, 32, 64, 96, 127};
    hats.rate = 16;
    makeSequenceTrack(track, hats, lengthInTicks);

    SequenceDesc drums;
    drums.notes = {
        {36}, {}, {36, 37}, {}, {36}, {}, {36, 37}, {},
        {36}, {}, {36, 37}, {}, {36}, {37}};
    drums.rate = 8;
    makeSequenceTrack(track, drums, lengthInTicks);

    track.addMuteEvent(0);

    return track;
}

SequenceTrack SequenceTrackFactory::createBassLine(tick_t lengthInTicks)
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
    makeSequenceTrack(track, desc, lengthInTicks);

    return track;
}

SequenceTrack SequenceTrackFactory::createMelodicBass(tick_t lengthInTicks)
{
    SequenceTrack track("Melodic Bass", MidiChannel::kModularA);

    SequenceDesc desc;
    desc.notes = {{36}, {36}, {43}, {41}, {38}, {38}, {43}, {41}};
    desc.velocities = {110};
    desc.rate = 8;
    makeSequenceTrack(track, desc, lengthInTicks);

    return track;
}

SequenceTrack SequenceTrackFactory::createHiHatPattern(tick_t lengthInTicks)
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
    makeSequenceTrack(track, desc, lengthInTicks);

    return track;
}

SequenceTrack SequenceTrackFactory::createSnareBackbeat(tick_t lengthInTicks)
{
    SequenceTrack track("Snare Backbeat", MidiChannel::kDrums);

    SequenceDesc desc;
    desc.notes = {{}, {37}, {}, {37}};
    desc.velocities = {120};
    desc.rate = 4;
    makeSequenceTrack(track, desc, lengthInTicks);

    return track;
}

SequenceTrack SequenceTrackFactory::createPadChords(tick_t lengthInTicks)
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
    makeSequenceTrack(track, desc, lengthInTicks);

    return track;
}

SequenceTrack SequenceTrackFactory::createSynthStabs(tick_t lengthInTicks)
{
    SequenceTrack track("Synth Stabs", MidiChannel::kModularA);

    SequenceDesc desc;
    desc.notes = {{}, {72}, {}, {74}, {}, {76}, {}, {77}};
    desc.velocities = {105};
    desc.rate = 8;
    makeSequenceTrack(track, desc, lengthInTicks);

    return track;
}

SequenceTrack SequenceTrackFactory::createClapBackbeat(tick_t lengthInTicks)
{
    SequenceTrack track("Clap", MidiChannel::kDrums);

    SequenceDesc desc;
    desc.notes = {{}, {39}, {}, {39}};
    desc.velocities = {115};
    desc.rate = 4;
    makeSequenceTrack(track, desc, lengthInTicks);

    return track;
}

SequenceTrack SequenceTrackFactory::createOpenHat(tick_t lengthInTicks)
{
    SequenceTrack track("Open Hat", MidiChannel::kDrums);

    SequenceDesc desc;
    desc.notes = {{}, {46}, {}, {46}};
    desc.velocities = {90};
    desc.rate = 4;
    makeSequenceTrack(track, desc, lengthInTicks);

    return track;
}

SequenceTrack SequenceTrackFactory::createTomFill(tick_t lengthInTicks)
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
    makeSequenceTrack(track, desc, lengthInTicks);

    return track;
}

SequenceTrack SequenceTrackFactory::createRimshot(tick_t lengthInTicks)
{
    SequenceTrack track("Rimshot", MidiChannel::kDrums);

    SequenceDesc desc;
    desc.notes = {{37}, {}, {37}, {}, {37}, {}, {37}, {}};
    desc.velocities = {95};
    desc.rate = 8;
    makeSequenceTrack(track, desc, lengthInTicks);

    return track;
}

SequenceTrack SequenceTrackFactory::createCymbalRide(tick_t lengthInTicks)
{
    SequenceTrack track("Ride", MidiChannel::kDrums);

    SequenceDesc desc;
    desc.notes = {{51}, {51}, {51}, {51}};
    desc.velocities = {70, 85, 70, 90};
    desc.rate = 4;
    makeSequenceTrack(track, desc, lengthInTicks);

    return track;
}

SequenceTrack SequenceTrackFactory::createTambourine(tick_t lengthInTicks)
{
    SequenceTrack track("Tambourine", MidiChannel::kDrums);

    SequenceDesc desc;
    desc.notes = {{54}, {54}, {54}, {54}, {54}, {54}, {54}, {54}};
    desc.velocities = {100, 60, 100, 60, 100, 60, 100, 60};
    desc.rate = 8;
    makeSequenceTrack(track, desc, lengthInTicks);

    return track;
}

SequenceTrack SequenceTrackFactory::createShaker(tick_t lengthInTicks)
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
    makeSequenceTrack(track, desc, lengthInTicks);

    return track;
}

SequenceTrack SequenceTrackFactory::createClave(tick_t lengthInTicks)
{
    SequenceTrack track("Clave", MidiChannel::kDrums);

    SequenceDesc desc;
    desc.notes = {{75}, {}, {}, {75}, {}, {75}, {}, {}};
    desc.velocities = {105};
    desc.rate = 8;
    makeSequenceTrack(track, desc, lengthInTicks);

    return track;
}

SequenceTrack SequenceTrackFactory::createCowbell(tick_t lengthInTicks)
{
    SequenceTrack track("Cowbell", MidiChannel::kDrums);

    SequenceDesc desc;
    desc.notes = {{56}, {}, {56}, {}};
    desc.velocities = {120};
    desc.rate = 4;
    makeSequenceTrack(track, desc, lengthInTicks);

    return track;
}

SequenceTrack SequenceTrackFactory::createChordStab(tick_t lengthInTicks)
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
    makeSequenceTrack(track, desc, lengthInTicks);

    return track;
}

SequenceTrack SequenceTrackFactory::createPluck(tick_t lengthInTicks)
{
    SequenceTrack track("Pluck", MidiChannel::kModularB);

    SequenceDesc desc;
    desc.notes = {{72}, {}, {76}, {}, {79}, {}, {76}, {}};
    desc.velocities = {85};
    desc.rate = 8;
    makeSequenceTrack(track, desc, lengthInTicks);

    return track;
}

SequenceTrack SequenceTrackFactory::createLead(tick_t lengthInTicks)
{
    SequenceTrack track("Lead", MidiChannel::kModularB);

    SequenceDesc desc;
    desc.notes = {{76}, {77}, {79}, {81}, {79}, {77}, {76}, {74}};
    desc.velocities = {95};
    desc.rate = 8;
    makeSequenceTrack(track, desc, lengthInTicks);

    return track;
}

SequenceTrack SequenceTrackFactory::createSubBass(tick_t lengthInTicks)
{
    SequenceTrack track("Sub Bass", MidiChannel::kBass);

    SequenceDesc desc;
    desc.notes = {{36}, {36}, {36}, {36}, {36}, {36}, {36}, {41}};
    desc.velocities = {120};
    desc.rate = 8;
    makeSequenceTrack(track, desc, lengthInTicks);

    return track;
}

SequenceTrack SequenceTrackFactory::createPadSwells(tick_t lengthInTicks)
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
    makeSequenceTrack(track, desc, lengthInTicks);

    makeAutomationTrack(track, 0, 96 * 4, 7, 0, 110);
    makeAutomationTrack(track, 96 * 4, 96 * 8, 7, 110, 40);
    makeAutomationTrack(track, 96 * 8, 96 * 12, 7, 40, 110);
    makeAutomationTrack(track, 96 * 12, 96 * 16, 7, 110, 0);

    return track;
}

SequenceTrack SequenceTrackFactory::createFxBleep(tick_t lengthInTicks)
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
    makeSequenceTrack(track, desc, lengthInTicks);

    return track;
}

SequenceTrack SequenceTrackFactory::createArpFast(tick_t lengthInTicks)
{
    SequenceTrack track("Arp Fast", MidiChannel::kModularA);

    SequenceDesc desc;
    desc.notes = {{60}, {64}, {67}, {72}, {67}, {64}, {60}, {64}};
    desc.velocities = {90};
    desc.rate = 16;
    makeSequenceTrack(track, desc, lengthInTicks);

    return track;
}

SequenceTrack SequenceTrackFactory::createGtrChug(tick_t lengthInTicks)
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
    makeSequenceTrack(track, desc, lengthInTicks);

    return track;
}

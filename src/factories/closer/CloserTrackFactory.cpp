#include "CloserTrackFactory.h"

#include "factories/TrackPatternBuilder.h"
#include "factories/MidiNotes.h"
#include "factories/closer/CloserPatterns.h"
#include "factories/DrumPatterns.h"
#include "MidiChannel.h"

SequenceTrack CloserTrackFactory::closerHats(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("Hats", MidiChannel::kSampler);
    track.setPattern(CloserPatterns::kCloserHat, lengthInTicks, startInTicks);
    return track;
}

SequenceTrack CloserTrackFactory::closerLoopHat(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("LoopHat", MidiChannel::kDrums);
    track.setPattern(CloserPatterns::kCloserLoopHat, lengthInTicks, startInTicks);
    return track;
}

SequenceTrack CloserTrackFactory::closerTambourin(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("Tambourin", MidiChannel::kSampler);
    track.setPattern(CloserPatterns::kCloserTambourin, lengthInTicks, startInTicks);
    return track;
}

SequenceTrack CloserTrackFactory::closerClapTom(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("ClapTom", MidiChannel::kDrums);
    track.setPattern(CloserPatterns::kCloserClapTom, lengthInTicks, startInTicks);
    return track;
}

SequenceTrack CloserTrackFactory::closerRiser(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("Riser", MidiChannel::kSampler);
    makeRiser(track, Closer::triRizstr, lengthInTicks, TickHelper::bars(2));
    return track;
}

SequenceTrack CloserTrackFactory::closerModular(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("Modular", MidiChannel::kModularA);
    track.setPattern(CloserPatterns::kCloserModular, lengthInTicks, startInTicks);
    return track;
}

SequenceTrack CloserTrackFactory::closerStab(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("Stab", MidiChannel::kPoly);

    SequenceDesc desc;
    desc.notes = {
        {}, {}, {}, {},
        {}, {}, {}, {},
        {}, {}, {}, {},
        {}, {}, {}, {},

        {}, {}, {}, {},
        {}, {}, {}, {},
        {}, {}, {}, {},
        {}, {}, {}, {},

        {}, {}, {}, {},
        {}, {}, {}, {},
        {}, {}, {}, {},
        {}, {}, {}, {},

        {}, {}, {}, {},
        {}, {}, {}, {},
        {}, {}, {}, {},
        {}, {}, {}, {Cd3, E3, Gd3, B3}
    };
    desc.rate = 16;
    makeSequenceTrack(track, desc, lengthInTicks, startInTicks);

    return track;
}

SequenceTrack CloserTrackFactory::closerArp(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("Arp", MidiChannel::kModularA);

    SequenceDesc desc;
    desc.notes = {
        {A1}, {A2}, {Cd3}, {E3}, {A2}, {A3}, {Cd4}, {E4},
        {A1}, {A2}, {Cd3}, {E3}, {A2}, {A3}, {Cd4}, {E4},
        {A1}, {A2}, {Cd3}, {E3}, {A2}, {A3}, {Cd4}, {E4},
        {A1}, {A2}, {Cd3}, {E3}, {A2}, {A3}, {Cd4}, {E4},

        {Fd1}, {A2}, {Cd3}, {E3}, {Fd2}, {A3}, {Cd4}, {E4},
        {Fd1}, {A2}, {Cd3}, {E3}, {Fd2}, {A3}, {Cd4}, {E4},
        {Fd1}, {A2}, {Cd3}, {E3}, {Fd2}, {A3}, {Cd4}, {E4},
        {Fd1}, {A2}, {Cd3}, {E3}, {Fd2}, {A3}, {Cd4}, {E4},

        {E3}, {E1}, {Gd2}, {B2}, {E4}, {E2}, {Gd3}, {B3},
        {E3}, {E1}, {Gd2}, {B2}, {E4}, {E2}, {Gd3}, {B3},
        {E3}, {E1}, {Gd2}, {B2}, {E4}, {E2}, {Gd3}, {B3},
        {E3}, {E1}, {Gd2}, {B2}, {E4}, {E2}, {Gd3}, {B3},

        {Cd1}, {Gd2}, {Cd3}, {E4}, {E2}, {Gd3}, {Cd4}, {E3},
        {Cd1}, {Gd2}, {Cd3}, {E4}, {E2}, {Gd3}, {Cd4}, {E3},
        {Cd1}, {Gd2}, {Cd3}, {E4}, {E2}, {Gd3}, {Cd4}, {E3},
        {Cd1}, {Gd2}, {Cd3}, {E4}, {E2}, {Gd3}, {Cd4}, {E3},
    };
    desc.rate = 16;
    makeSequenceTrack(track, desc, lengthInTicks, startInTicks);

    return track;
}

SequenceTrack CloserTrackFactory::closerFill808(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("Fill808", MidiChannel::kDrums);

    uint8_t snr = Closer::sd1050;

    tick_t fillStart = lengthInTicks - TickHelper::bars(2);

    tick_t grooveLen = TICK(1,2);

    SequenceDesc desc;
    desc.notes = {{snr}};
    desc.rate = 16;
    desc.groove = 10;
    makeSequenceTrack(track, desc, grooveLen, fillStart);

    SequenceDesc descTri;
    descTri.notes = {{snr}};
    descTri.rate = 24;
    makeSequenceTrack(track, descTri, TICK(0,2), fillStart + grooveLen);

    return track;
}

SequenceTrack CloserTrackFactory::closerChords(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("Chords", MidiChannel::kMicrofreak);
    track.setPattern(CloserPatterns::kCloserChords, lengthInTicks, startInTicks);
    return track;
}

SequenceTrack CloserTrackFactory::closerSing(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("Sing", MidiChannel::kSampler);
    track.setPattern(CloserPatterns::kCloserSing, lengthInTicks, startInTicks);
    return track;
}

SequenceTrack CloserTrackFactory::closerTop(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("Top", MidiChannel::kSampler);
    track.setPattern(CloserPatterns::kCloserTop, lengthInTicks, startInTicks);
    return track;
}

SequenceTrack CloserTrackFactory::closerBlastCymb(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("BlastCymb", MidiChannel::kDrums);
    track.setPattern(CloserPatterns::kCloserBlastCymb, lengthInTicks, startInTicks);
    return track;
}

SequenceTrack CloserTrackFactory::closerBlastKick(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("Kick", MidiChannel::kDrums);
    track.setPattern(DrumPatterns::kKickFour, lengthInTicks, startInTicks);

    uint8_t kick = 36;

    tick_t fourBars = TickHelper::bars(4);

    SequenceDesc desc;
    desc.notes = {{}, {kick}};
    desc.rate = 8;
    desc.velocities = {96};
    makeSequenceTrack(track, desc, fourBars, lengthInTicks - fourBars);

    return track;
}

SequenceTrack CloserTrackFactory::closerBlastSnare(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("BlastSnare", MidiChannel::kDrums);

    uint8_t snr = Closer::discoSnr;
    tick_t sixBars = TickHelper::bars(6);
    tick_t oneBar = TickHelper::bars(1);

    SequenceDesc desc;
    desc.notes = {{snr}};
    desc.rate = 4;
    makeSequenceTrack(track, desc, sixBars, startInTicks);

    desc.rate = 8;
    makeSequenceTrack(track, desc, oneBar, startInTicks + sixBars);
    
    desc.rate = 16;
    makeSequenceTrack(track, desc, oneBar, startInTicks + sixBars + oneBar);

    return track;
}

SequenceTrack CloserTrackFactory::closer303(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("303", MidiChannel::kSampler);
    track.addNote(TICK(4), TickHelper::kStepLen, Closer::tri303, 127);
    track.addNote(TICK(6), TickHelper::kStepLen, Closer::tri303, 127);
    return track;
}

SequenceTrack CloserTrackFactory::closerDrumix(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("Drumix", MidiChannel::kSampler);
    track.addNote(TICK(4), TickHelper::kStepLen, Closer::triChopdrum, 127);
    track.addNote(TICK(6), TickHelper::kStepLen, Closer::triChopdrum, 127);
    return track;
}

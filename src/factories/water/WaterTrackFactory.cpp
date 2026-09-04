#include "WaterTrackFactory.h"

#include "factories/DrumPatterns.h"
#include "factories/SequenceTrackFactory.h"
#include "factories/water/WaterPatterns.h"
#include "factories/TrackPatternBuilder.h"
#include "MidiConst.h"
#include "TickHelper.h"
#include "factories/MidiNotes.h"

SequenceTrack WaterTrackFactory::waterMarimba(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("Marimba", MidiChannel::kDrums);
    track.setPattern(WaterPatterns::kWaterMarimba, lengthInTicks, startInTicks);
    return track;
}

SequenceTrack WaterTrackFactory::waterHats(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("Hats", MidiChannel::kDrums);
    track.setPattern(WaterPatterns::kWaterHats, lengthInTicks, startInTicks);
    return track;
}

SequenceTrack WaterTrackFactory::waterFreak(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("Freak", MidiChannel::kMicrofreak);
    track.setPattern(WaterPatterns::kWaterFreak, lengthInTicks, startInTicks);
    return track;
}

SequenceTrack WaterTrackFactory::waterBass(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("Bass", MidiChannel::kBass);
    track.setPattern(WaterPatterns::kWaterBass, lengthInTicks, startInTicks);
    return track;
}

SequenceTrack WaterTrackFactory::waterChorus(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("Chorus", MidiChannel::kSampler);

    SequenceDesc desc;
    desc.notes = {{Water::wtrJunoa}};
    desc.rate = 0.125;
    makeSequenceTrack(track, desc, lengthInTicks, startInTicks);

    tick_t lastNote = TICK(12, 3, 2);
    track.addNote(startInTicks + lastNote, TickHelper::kStepLen, Water::wtrJunob, 127);

    return track;
}


SequenceTrack WaterTrackFactory::waterXmas(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("Xmas", MidiChannel::kSampler);
    track.setPattern(WaterPatterns::kWaterXmas, lengthInTicks, startInTicks);
    return track;
}

SequenceTrack WaterTrackFactory::waterCongas(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("Congas", MidiChannel::kDrums);
    track.setPattern(WaterPatterns::kWaterCongas, lengthInTicks, startInTicks);
    return track;
}

SequenceTrack WaterTrackFactory::waterClaves(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("Claves", MidiChannel::kDrums);
    track.setPattern(WaterPatterns::kWaterClaves, lengthInTicks, startInTicks);
    return track;
}

SequenceTrack WaterTrackFactory::waterFm(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("Fm", MidiChannel::kSampler);

    SequenceDesc desc;
    desc.notes = {{65}};
    desc.rate = 0.25;
    makeSequenceTrack(track, desc, lengthInTicks, startInTicks);

    return track;
}

SequenceTrack WaterTrackFactory::waterBalafon(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("Balafon", MidiChannel::kSampler);
    track.setPattern(WaterPatterns::kWaterBalafon, lengthInTicks, startInTicks);
    return track;
}

SequenceTrack WaterTrackFactory::waterShakes(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("Shakes", MidiChannel::kSampler);
    track.setPattern(WaterPatterns::kWaterShakes, lengthInTicks, startInTicks);
    return track;
}

SequenceTrack WaterTrackFactory::waterFmbass(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("Fmbass", MidiChannel::kSampler);
    track.setPattern(WaterPatterns::kWaterFmbass, lengthInTicks, startInTicks);
    return track;
}

SequenceTrack WaterTrackFactory::waterChorusFMBass(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("Fmbass", MidiChannel::kSampler);

    SequenceDesc desc;
    desc.notes = {
        {}, {}, {}, {},
        {}, {}, {}, {},
        {}, {}, {Water::fmbassgd}, {Water::fmbassgd},
        {Water::fmbassad}, {Water::fmbassad}, {Water::fmbasscd}, {Water::fmbasscd},
        };
    desc.rate = 16;
    makeSequenceTrack(track, desc, lengthInTicks, startInTicks);

    return track;
}


SequenceTrack WaterTrackFactory::waterKickPreChorus(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("KickPreChorus", MidiChannel::kDrums);

    constexpr uint8_t kick = 36;
    const tick_t patternLen = TickHelper::bars(7);

    track.setPattern(DrumPatterns::kKickFour, patternLen, startInTicks);

    const tick_t lastBar = startInTicks + patternLen;
    track.addNote(lastBar, TickHelper::kStepLen, kick, 127);
    track.addNote(lastBar + TickHelper::quarters(3), TickHelper::kStepLen, kick, 127);

    return track;
}

SequenceTrack WaterTrackFactory::waterKickPartB(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("KickPartB", MidiChannel::kDrums);

    constexpr uint8_t kick = 36;
    const tick_t patternLen = TickHelper::bars(31);

    track.setPattern(DrumPatterns::kKickFour, patternLen, startInTicks);

    const tick_t fillStart = startInTicks + patternLen;
    track.addNote(fillStart, TickHelper::kStepLen, kick, 127);
    track.addNote(fillStart + TickHelper::kTicksPerQuarterNote + TickHelper::kTicksPerEighthNote, TickHelper::kStepLen, kick, 127);
    track.addNote(fillStart + 2 * TickHelper::kTicksPerQuarterNote + TickHelper::kStepLen, TickHelper::kStepLen, kick, 127);
    track.addNote(fillStart + TickHelper::quarters(3), TickHelper::kStepLen, kick, 127);

    return track;
}

SequenceTrack WaterTrackFactory::waterEventsPartB(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("EventsPartB", MidiChannel::kSampler);
    track.addNote(TickHelper::bars(28), TickHelper::kStepLen, 61, 127);

    return track;
}

SequenceTrack WaterTrackFactory::waterFreakChorusB(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("FreakChorusB", MidiChannel::kMicrofreak);
    track.setPattern(WaterPatterns::kWaterChorusBFreak, lengthInTicks, startInTicks);
    return track;
}

SequenceTrack WaterTrackFactory::waterKickPartC(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("KickPartC", MidiChannel::kDrums);

    constexpr uint8_t kick = 36;
    const tick_t patternLen = TickHelper::bars(7) + TickHelper::quarters(2);

    track.setPattern(DrumPatterns::kKickFour, patternLen, startInTicks);

    const tick_t fillStart = startInTicks + patternLen;
    track.addNote(fillStart + TickHelper::kTicksPerEighthNote, TickHelper::kStepLen, kick, 127);
    track.addNote(fillStart + TickHelper::kTicksPerQuarterNote + TickHelper::kStepLen, TickHelper::kStepLen, kick, 127);

    return track;
}

SequenceTrack WaterTrackFactory::waterEventsPartC(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("EventsPartC", MidiChannel::kSampler);
    track.addNote(TickHelper::bars(4), TickHelper::kStepLen, 66, 127);

    return track;
}

SequenceTrack WaterTrackFactory::waterEventsEnd(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("EventsEnd", MidiChannel::kSampler);
    track.addNote(TickHelper::bars(16), TickHelper::kStepLen, 67, 127);

    return track;
}

SequenceTrack WaterTrackFactory::waterChorusEnd(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("ChorusEnd", MidiChannel::kSampler);

    SequenceDesc desc;
    desc.notes = {{Water::wtrJunoa}};
    desc.rate = 0.125;
    makeSequenceTrack(track, desc, lengthInTicks, startInTicks);

    tick_t lastNote = TICK(28, 3, 2);
    track.addNote(startInTicks + lastNote, TickHelper::kStepLen, Water::wtrJunob, 127);

    return track;
}

SequenceTrack WaterTrackFactory::waterFreakWind(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("FreakWind", MidiChannel::kMicrofreak);

    SequenceDesc desc;
    desc.notes = {{C3}};
    desc.rate = 1;
    makeSequenceTrack(track, desc, lengthInTicks, startInTicks);

    return track;
}

SequenceTrack WaterTrackFactory::waterMatrix(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("Matrix", MidiChannel::kMatrix);
    track.setPattern(WaterPatterns::kWaterMatrix, lengthInTicks, startInTicks);
    return track;
}

SequenceTrack WaterTrackFactory::waterCyanBlink(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("CyanBlink", MidiChannel::kLedStrips);
    track.setPattern(WaterPatterns::kWaterCyanBlink, lengthInTicks, startInTicks);
    return track;
}

SequenceTrack WaterTrackFactory::waterChorusLed(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("ChorusLed", MidiChannel::kLedStrips);

    SequenceDesc desc;
    desc.notes = {
        {LedStrips::kWhite_ALL}, {}, {}, {}, {}, {}, {}, {LedStrips::kWhite_ALL},
        {}, {}, {}, {}, {}, {}, {}, {},
        {LedStrips::kWhite_ALL}, {}, {}, {}, {}, {}, {}, {},
        {}, {}, {}, {}, {}, {}, {}, {},
    };
    desc.rate = 8;
    desc.durations = {4,4,8};
    makeSequenceTrack(track, desc, lengthInTicks, startInTicks);

    return track;
}

SequenceTrack WaterTrackFactory::waterLedPattern(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("LedPattern", MidiChannel::kLedStrips);
    track.setPattern(WaterPatterns::kWaterLedPattern, lengthInTicks, startInTicks);
    return track;
}

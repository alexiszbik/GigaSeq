#include "BibimbapLedRules.h"
#include "BibimbapSamples.h"

#include "MidiChannel.h"
#include "MidiConst.h"
#include "RandomHelper.h"

BibimbapLedRules kBibimbapLedRules;

constexpr uint8_t kGreenLeds[] = {
    LedStrips::kGreen_A,
    LedStrips::kGreen_B,
    LedStrips::kGreen_C,
    LedStrips::kGreen_D,
};

constexpr uint8_t kGreenLedCount = sizeof(kGreenLeds) / sizeof(kGreenLeds[0]);

constexpr uint8_t kWhiteLeds[] = {
    LedStrips::kWhite_A,
    LedStrips::kWhite_B,
    LedStrips::kWhite_C,
    LedStrips::kWhite_D,
};

constexpr uint8_t kWhiteLedCount = sizeof(kWhiteLeds) / sizeof(kWhiteLeds[0]);

bool isKickNote(uint8_t channel, uint8_t note)
{
    return note == Bibimbap::bbbKickhi
        && (channel == MidiChannel::kDrums || channel == MidiChannel::kSampler);
}

bool isTomNote(uint8_t channel, uint8_t note)
{
    return note == Bibimbap::bbbTom1
        && (channel == MidiChannel::kDrums || channel == MidiChannel::kSampler);
}

bool isRim(uint8_t channel, uint8_t note)
{
    return note == Bibimbap::bbbRim
        && (channel == MidiChannel::kDrums || channel == MidiChannel::kSampler);
}

bool isSnare(uint8_t channel, uint8_t note)
{
    return note == Bibimbap::bbbSnr
        && (channel == MidiChannel::kDrums || channel == MidiChannel::kSampler);
}

bool isDizzee(uint8_t channel, uint8_t note)
{
    return note == Bibimbap::bbbDz
        && (channel == MidiChannel::kDrums || channel == MidiChannel::kSampler);
}

bool isBass(uint8_t channel, uint8_t note)
{
    return channel == MidiChannel::kBass;
}

bool isDropSnare(uint8_t channel, uint8_t note)
{
    return note == Bibimbap::sd1050
        && (channel == MidiChannel::kDrums || channel == MidiChannel::kSampler);
}

void BibimbapLedRules::processNoteOn(
    const Note& note,
    uint8_t channel,
    tick_t durationTicks,
    MidiInOut& midi)
{
    if (isKickNote(channel, note.note)) {
        addNote(MidiChannel::kMatrix, LedMatrix::kBibimbap_vu_noteA_note, 127, durationTicks, midi);
        return;
    }

    if (isTomNote(channel, note.note)) {
        addNote(MidiChannel::kMatrix, LedMatrix::kBibimbap_vu_noteB_note, 127, durationTicks, midi);
    }

    if (isRim(channel, note.note)) {
        addNote(MidiChannel::kLedStrips, LedStrips::kWhite_ALL, 127, durationTicks, midi);
    }

    if (isSnare(channel, note.note)) {
        addNote(MidiChannel::kLedStrips, LedStrips::kGreen_ALL, 127, durationTicks, midi);
        addNote(MidiChannel::kLedStrips, LedStrips::kRed_ALL, 127, durationTicks, midi);
    }

    if (isDizzee(channel, note.note)) {
        const uint8_t ledNote = kGreenLeds[RandomHelper::nextRandomIndex(rngState_, kGreenLedCount)];
        addNote(MidiChannel::kLedStrips, ledNote, note.velocity, durationTicks, midi);
    }

    if (isBass(channel, note.note)) {
        addNote(MidiChannel::kLedStrips, LedStrips::kGreen_D, 127, durationTicks, midi);
    }

    if (isDropSnare(channel, note.note)) {
        const uint8_t ledNote = kWhiteLeds[RandomHelper::nextRandomIndex(rngState_B, kWhiteLedCount)];
        addNote(MidiChannel::kLedStrips, ledNote, note.velocity, durationTicks, midi);
    }

    
}

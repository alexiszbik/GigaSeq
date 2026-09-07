#include "UandiLedRules.h"

#include "MidiChannel.h"
#include "MidiConst.h"

#include "UandiSamples.h"

UandiLedRules kUandiLedRules;

bool isVoice(uint8_t channel, uint8_t note)
{
    return note == Uandi::uaiVo1
        && (channel == MidiChannel::kDrums || channel == MidiChannel::kSampler);
}


void UandiLedRules::processNoteOn(
    const Note& note,
    uint8_t channel,
    tick_t durationTicks,
    MidiInOut& midi)
{

    if (isVoice(channel, note.note)) {
        addNote(MidiChannel::kLedStrips, LedStrips::kBlue_ALL, 127, 24, midi);
        addNote(MidiChannel::kLedStrips, LedStrips::kRed_ALL, 127, 24, midi);
    }
}

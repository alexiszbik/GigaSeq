#include "midiinrules/InMidiRules.h"

uint8_t transposeMidiNote(uint8_t note, int8_t semitones) noexcept
{
    const int result = static_cast<int>(note) + static_cast<int>(semitones);

    if (result < 0) {
        return 0;
    }

    if (result > 127) {
        return 127;
    }

    return static_cast<uint8_t>(result);
}

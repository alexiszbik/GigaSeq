#pragma once

#include <Arduino.h>
#include <MIDI.h>

namespace GigaSeq {

class MidiInOut {
public:
    void begin(uint8_t channel = MIDI_CHANNEL_OMNI);
    void read();

    void sendNoteOn(uint8_t note, uint8_t velocity, uint8_t channel);
    void sendNoteOff(uint8_t note, uint8_t velocity, uint8_t channel);
};

}  // namespace GigaSeq

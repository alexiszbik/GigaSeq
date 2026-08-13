#pragma once

#include <Arduino.h>
#include <MIDI.h>

namespace GigaSeq {

class GigaMidiInOut {
public:
    void begin(uint8_t channel = MIDI_CHANNEL_OMNI);
    void read();

    void sendNoteOn(uint8_t note, uint8_t velocity, uint8_t channel);
    void sendNoteOff(uint8_t note, uint8_t velocity, uint8_t channel);
    void sendControlChange(uint8_t channel, uint8_t controller, uint8_t value);
    void sendProgramChange(uint8_t channel, uint8_t program);
    void sendClock();
    void sendStart();
    void sendStop();
};

}  // namespace GigaSeq

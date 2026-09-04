#pragma once

#include "MidiQueue.h"

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

    bool flush();

private:
    static void onNoteOn(byte channel, byte note, byte velocity);
    static void onNoteOff(byte channel, byte note, byte velocity);
    static void onControlChange(byte channel, byte control, byte value);

    void write1(uint8_t b);
    void write2(uint8_t b1, uint8_t b2);
    void write3(uint8_t b1, uint8_t b2, uint8_t b3);

    static GigaMidiInOut* instance_;
    MidiQueue queue_;
};

}  // namespace GigaSeq

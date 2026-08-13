#pragma once

#include "GigaMidiInOut.h"
#include "MidiInOut.h"

class EngineMidiBridge : public MidiInOut {
public:
    explicit EngineMidiBridge(GigaSeq::GigaMidiInOut& midi);

    void sendClock() override;
    void sendStart() override;
    void sendStop() override;
    void sendNoteOn(uint8_t channel, uint8_t note, uint8_t velocity) override;
    void sendNoteOff(uint8_t channel, uint8_t note, uint8_t velocity) override;
    void sendControlChange(uint8_t channel, uint8_t controller, uint8_t value) override;
    void sendProgramChange(uint8_t channel, uint8_t program) override;

private:
    GigaSeq::GigaMidiInOut& midi_;
};

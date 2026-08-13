#pragma once

#include <Arduino.h>

class Mux {
    static constexpr uint8_t channelCount = 16;

public:
    Mux(uint8_t sigPin, uint8_t s0, uint8_t s1, uint8_t s2, uint8_t s3);

    void begin();
    uint8_t readNext();
    uint16_t getStates();
    uint16_t getChangedStates();
    void clearChangedStates();

private:
    void selectChannel(uint8_t channel);
    bool readChannel(uint8_t channel);

    uint8_t sigPin_;
    uint8_t selectPins_[4];
    uint8_t currentReadIndex_ = 0;
    uint16_t states_ = 0;
    uint16_t changed_ = 0;
};

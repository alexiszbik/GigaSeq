#include "Mux.h"

Mux::Mux(uint8_t sigPin, uint8_t s0, uint8_t s1, uint8_t s2, uint8_t s3) : sigPin_(sigPin) {
    selectPins_[0] = s0;
    selectPins_[1] = s1;
    selectPins_[2] = s2;
    selectPins_[3] = s3;
}

void Mux::begin() {
    for (uint8_t i = 0; i < 4; ++i) {
        pinMode(selectPins_[i], OUTPUT);
        digitalWrite(selectPins_[i], LOW);
    }

    pinMode(sigPin_, INPUT_PULLUP);
    states_ = 0;
    changed_ = 0;
}

uint8_t Mux::readNext() {
    const uint8_t readIndex = currentReadIndex_;
    const uint16_t bitMask = 1u << readIndex;
    const bool newState = readChannel(readIndex);
    const bool oldState = (states_ & bitMask) != 0;

    if (newState != oldState) {
        changed_ |= bitMask;
        if (newState) {
            states_ |= bitMask;
        } else {
            states_ &= ~bitMask;
        }
    }

    if (++currentReadIndex_ >= channelCount) {
        currentReadIndex_ = 0;
    }

    return readIndex;
}

bool Mux::getValue(uint8_t channel) {
    if (channel >= channelCount) {
        return false;
    }
    clearChanged(channel);
    return (states_ >> channel) & 1u;
}

bool Mux::hasChanged(uint8_t channel)  {
    if (channel >= channelCount) {
        return false;
    }
    return (changed_ >> channel) & 1u;
}

void Mux::clearChanged(uint8_t channel) {
    if (channel < channelCount) {
        changed_ &= ~(1u << channel);
    }
}

void Mux::selectChannel(uint8_t channel) {
    for (uint8_t i = 0; i < 4; ++i) {
        digitalWrite(selectPins_[i], (channel >> i) & 1);
    }
}

bool Mux::readChannel(uint8_t channel) {
    selectChannel(channel);
    delayMicroseconds(10);
    return digitalRead(sigPin_) == LOW;
}

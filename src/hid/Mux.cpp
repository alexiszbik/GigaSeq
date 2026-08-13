#include "Mux.h"

Mux::Mux(uint8_t sigPin, uint8_t s0, uint8_t s1, uint8_t s2, uint8_t s3) : sigPin_(sigPin)
{
    selectPins_[0] = s0;
    selectPins_[1] = s1;
    selectPins_[2] = s2;
    selectPins_[3] = s3;
}

void Mux::begin()
{
    for (uint8_t i = 0; i < 4; ++i)
    {
        pinMode(selectPins_[i], OUTPUT);
        digitalWrite(selectPins_[i], LOW);
    }

    pinMode(sigPin_, INPUT_PULLUP);
    states_ = 0;
    changed_ = 0;
    currentReadIndex_ = 0;
    selectChannel(0);
}

uint8_t Mux::readNext()
{
    const uint8_t readIndex = currentReadIndex_;
    const uint16_t bitMask = 1u << readIndex;
    const bool newState = digitalRead(sigPin_) == LOW;
    const bool oldState = (states_ & bitMask) != 0;

    if (newState != oldState)
    {
        changed_ |= bitMask;
        if (newState)
        {
            states_ |= bitMask;
        }
        else
        {
            states_ &= ~bitMask;
        }
    }

    if (++currentReadIndex_ >= channelCount)
    {
        currentReadIndex_ = 0;
    }

    selectChannel(currentReadIndex_);

    return readIndex;
}

uint16_t Mux::getStates()
{
    return states_;
}

uint16_t Mux::getChangedStates()
{
    return changed_;
}

void Mux::clearChangedStates()
{
    changed_ = 0;
}

void Mux::selectChannel(uint8_t channel)
{
    for (uint8_t i = 0; i < 4; ++i)
    {
        digitalWrite(selectPins_[i], (channel >> i) & 1);
    }
}

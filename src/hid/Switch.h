#pragma once

#include <Arduino.h>

class Switch {
public:
    explicit Switch(byte pin);

    bool isPushed();

    bool debounce();
    bool getState();

private:
    static constexpr uint8_t FLAG_STATE = 0x01;
    static constexpr uint8_t FLAG_STATE_CHANGED = 0x02;

    byte pin_;
    uint8_t flags_ = 0;
};

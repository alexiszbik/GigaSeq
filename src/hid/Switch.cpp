#include "Switch.h"

Switch::Switch(byte pin) : pin_(pin) {
    pinMode(pin_, INPUT_PULLUP);
}

bool Switch::debounce() {
    bool currentState = digitalRead(pin_) == HIGH;
    bool previousState = flags_ & FLAG_STATE;
    if (currentState != previousState) {
        flags_ = (currentState ? FLAG_STATE : 0) | FLAG_STATE_CHANGED;
    }

    return flags_ & FLAG_STATE_CHANGED;
}

bool Switch::getState() {
    bool state = flags_ & FLAG_STATE;
    flags_ &= FLAG_STATE;
    return state;
}

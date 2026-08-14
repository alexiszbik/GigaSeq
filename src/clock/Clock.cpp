#include "Clock.h"

namespace GigaSeq {

TransportClock* TransportClock::instance_ = nullptr;

uint32_t TransportClock::intervalFor(uint16_t bpm) {
    // Microseconds per output tick at kPpqn.
    return 60000000u / (static_cast<uint32_t>(bpm) * kPpqn);
}

void TransportClock::begin(uint16_t bpm) {
    instance_ = this;
    currentTick_ = 0;
    bpm_ = bpm;
    intervalUs_ = intervalFor(bpm);
    // Ticker is armed by start(); begin() only configures the tempo.
}

void TransportClock::start() {
    if (playing_) {
        return;
    }
    currentTick_ = 0;
    playing_ = true;
#if defined(__MBED__)
    ticker_.attach_us(mbed::callback(this, &TransportClock::onTicker), intervalUs_);
#endif
}

void TransportClock::stop() {
    if (!playing_) {
        return;
    }
    playing_ = false;
#if defined(__MBED__)
    ticker_.detach();
#endif
}

void TransportClock::toggleStartStop() {
    if (playing_) {
        stop();
    } else {
        start();
    }
}

void TransportClock::setTempo(uint16_t bpm) {
    bpm_ = bpm;
    intervalUs_ = intervalFor(bpm);
#if defined(__MBED__)
    if (playing_) {
        // Re-arm with the new interval (mbed::Ticker supports re-attach).
        ticker_.attach_us(mbed::callback(this, &TransportClock::onTicker), intervalUs_);
    }
#endif
}

void TransportClock::setOnTick(TickCallback callback, void* context) {
    tickCallback_ = callback;
    tickContext_ = context;
}

bool TransportClock::isPlaying() const {
    return playing_;
}

uint32_t TransportClock::getRawTick() const {
    return currentTick_;
}

uint16_t TransportClock::getBar() const {
    return static_cast<uint16_t>(currentTick_ / (kPpqn * kBeatsPerBar) + 1);
}

uint8_t TransportClock::getBeat() const {
    return static_cast<uint8_t>((currentTick_ / kPpqn) % kBeatsPerBar + 1);
}

uint8_t TransportClock::getTick() const {
    return static_cast<uint8_t>(currentTick_ % kPpqn);
}

void TransportClock::onTicker() {
    // Runs in the us_ticker ISR: keep it short and IRQ-safe.
    ++currentTick_;
    if (tickCallback_) {
        tickCallback_(currentTick_, tickContext_);
    }
}

}  // namespace GigaSeq

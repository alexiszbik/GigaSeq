#include "Clock.h"

#include "ClockCalibration.h"

namespace GigaSeq {

TransportClock* TransportClock::instance_ = nullptr;

uint32_t TransportClock::intervalFor(uint16_t bpm) {
    const uint32_t intervalUs = 60000000u / (static_cast<uint32_t>(bpm) * kPpqn);
    return applyHardwareClockPpmCorrection(intervalUs);
}

void TransportClock::begin(uint16_t bpm) {
    instance_ = this;
    bpm_ = bpm;
    intervalUs_ = intervalFor(bpm);
    // Ticker is armed by start(); begin() only configures the tempo.
}

void TransportClock::start() {
    if (playing_) {
        return;
    }
    playing_ = true;
    ticker_.attach_us(mbed::callback(this, &TransportClock::onTicker), intervalUs_);
}

void TransportClock::stop() {
    if (!playing_) {
        return;
    }
    playing_ = false;
    ticker_.detach();
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
    const uint32_t newInterval = intervalFor(bpm);
    if (playing_) {
        pendingIntervalUs_ = newInterval;
        intervalDirty_ = true;
    } else {
        intervalUs_ = newInterval;
    }
}

void TransportClock::setOnTick(TickCallback callback, void* context) {
    tickCallback_ = callback;
    tickContext_ = context;
}

bool TransportClock::isPlaying() const {
    return playing_;
}

void TransportClock::onTicker() {
    // Apply pending tempo changes at tick boundary, before the tick callback.
    // setTempo() only marks dirty when playing — never re-arms from inside the callback chain.
    if (intervalDirty_) {
        intervalDirty_ = false;
        intervalUs_ = pendingIntervalUs_;
        ticker_.attach_us(mbed::callback(this, &TransportClock::onTicker), intervalUs_);
    }

    // Runs in the us_ticker ISR: keep it short and IRQ-safe.
    if (tickCallback_) {
        tickCallback_(tickContext_);
    }
}

}  // namespace GigaSeq

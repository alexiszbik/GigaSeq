#include "Clock.h"

#include <uClock.h>

namespace GigaSeq {

TransportClock* TransportClock::instance_ = nullptr;

void TransportClock::onOutputPPQN(uint32_t tick) {
    if (!instance_) {
        return;
    }

    instance_->currentTick_ = tick;

    if (instance_->tickCallback_) {
        instance_->tickCallback_(tick, instance_->tickContext_);
    }
}

void TransportClock::begin(uint16_t bpm) {
    instance_ = this;
    currentTick_ = 0;

    uClock.init();
    uClock.setTempo(bpm);
    uClock.setOutputPPQN(uClock.PPQN_96);
    uClock.setOnOutputPPQN(onOutputPPQN);
}

void TransportClock::run() {
    uClock.run();
}

void TransportClock::start() {
    uClock.start();
    playing_ = true;
}

void TransportClock::stop() {
    uClock.stop();
    playing_ = false;
}

void TransportClock::toggleStartStop() {
    if (playing_) {
        stop();
    } else {
        start();
    }
}

void TransportClock::setTempo(uint16_t bpm) {
    uClock.setTempo(bpm);
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

}  // namespace GigaSeq

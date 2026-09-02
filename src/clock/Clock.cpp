#include "Clock.h"

#include <chrono>

namespace GigaSeq {

TransportClock::Scheduler::Scheduler(TransportClock& owner)
    : owner_(owner)
{
}

void TransportClock::Scheduler::handler()
{
    if (owner_.intervalDirty_) {
        owner_.intervalDirty_ = false;
        owner_.interval_.reset(owner_.pendingBpm_);
    }

    _delay = std::chrono::microseconds(owner_.interval_.next());
    mbed::TickerBase::handler();
}

TransportClock::TransportClock()
    : scheduler_(*this)
{
}

void TransportClock::begin(uint16_t bpm)
{
    bpm_ = bpm;
    pendingBpm_ = bpm;
    interval_.reset(bpm);
}

void TransportClock::start()
{
    if (playing_) {
        return;
    }
    playing_ = true;
    intervalDirty_ = false;
    interval_.reset(bpm_);
    const auto firstDelay = std::chrono::microseconds(interval_.next());
    scheduler_.attach(mbed::callback(this, &TransportClock::invokeTick), firstDelay);
}

void TransportClock::stop()
{
    if (!playing_) {
        return;
    }
    playing_ = false;
    scheduler_.detach();
}

void TransportClock::toggleStartStop()
{
    if (playing_) {
        stop();
    } else {
        start();
    }
}

void TransportClock::setTempo(uint16_t bpm)
{
    bpm_ = bpm;
    if (playing_) {
        pendingBpm_ = bpm;
        intervalDirty_ = true;
    } else {
        pendingBpm_ = bpm;
        interval_.reset(bpm);
    }
}

void TransportClock::setOnTick(TickCallback callback, void* context)
{
    tickCallback_ = callback;
    tickContext_ = context;
}

bool TransportClock::isPlaying() const
{
    return playing_;
}

void TransportClock::invokeTick()
{
    if (tickCallback_) {
        tickCallback_(tickContext_);
    }
}

}  // namespace GigaSeq

#pragma once

#include <algorithm>
#include <cstddef>
#include <utility>
#include <vector>

template<typename T>
class TimedEventList
{
public:
    void add(T event)
    {
        events_.push_back(std::move(event));
        sort();
    }

    void reset()
    {
        nextIndex_ = 0;
    }

    template<typename Handler>
    void process(tick_t position, bool loopWrap, Handler&& onEvent)
    {
        if (loopWrap) {
            nextIndex_ = 0;
        }

        while (nextIndex_ < events_.size() && events_[nextIndex_].tick < position) {
            ++nextIndex_;
        }

        while (nextIndex_ < events_.size() && events_[nextIndex_].tick == position)
        {
            onEvent(events_[nextIndex_]);
            ++nextIndex_;
        }
    }

    void removeInRange(tick_t startTick, tick_t durationTicks)
    {
        removeInRangeIf(startTick, durationTicks, [](const T&) { return true; });
    }

    template<typename Predicate>
    void removeInRangeIf(tick_t startTick, tick_t durationTicks, Predicate&& predicate)
    {
        if (durationTicks == 0) {
            return;
        }

        const uint32_t start = static_cast<uint32_t>(startTick);
        const uint32_t endTick = start + static_cast<uint32_t>(durationTicks);

        events_.erase(
            std::remove_if(
                events_.begin(),
                events_.end(),
                [start, endTick, pred = std::forward<Predicate>(predicate)](const T& event) {
                    const uint32_t eventTick = static_cast<uint32_t>(event.tick);
                    if (eventTick < start || eventTick >= endTick) {
                        return false;
                    }
                    return pred(event);
                }),
            events_.end());

        nextIndex_ = 0;
    }

private:
    void sort()
    {
        std::sort(events_.begin(), events_.end(), [](const T& a, const T& b) {
            return a.tick < b.tick;
        });
    }

    std::vector<T> events_;
    std::size_t nextIndex_ = 0;
};

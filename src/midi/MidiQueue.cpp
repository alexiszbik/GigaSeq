#include "MidiQueue.h"

bool MidiQueue::push(const MidiEvent &event)
{
    if (count_ >= kCapacity)
    {
        return false;
    }
    buffer_[head_] = event;
    head_ = (head_ + 1);
    if (head_ >= kCapacity) head_ = 0;
    ++count_;
    return true;
}

bool MidiQueue::peek(MidiEvent &out) const
{
    if (count_ == 0)
    {
        return false;
    }
    out = buffer_[tail_];
    return true;
}

bool MidiQueue::pop()
{
    if (count_ == 0)
    {
        return false;
    }
    tail_ = (tail_ + 1);
    if (tail_ >= kCapacity) tail_ = 0;
    --count_;
    return true;
}

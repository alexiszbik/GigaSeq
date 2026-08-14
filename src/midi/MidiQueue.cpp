#include "MidiQueue.h"

#include "../platform/CriticalSection.h"

bool MidiQueue::push(const MidiEvent &event)
{
    // Producer side: called from the clock ISR. Guard count_ against the
    // consumer (loop) which reads/pops concurrently.
    CriticalSection cs;
    if (count_ >= kCapacity)
    {
        return false;
    }
    buffer_[head_] = event;
    ++head_;
    if (head_ >= kCapacity) head_ = 0;
    ++count_;
    return true;
}

bool MidiQueue::peek(MidiEvent &out) const
{
    CriticalSection cs;
    if (count_ == 0)
    {
        return false;
    }
    out = buffer_[tail_];
    return true;
}

bool MidiQueue::pop()
{
    // Consumer side: called from the main loop. Guard against the ISR push.
    CriticalSection cs;
    if (count_ == 0)
    {
        return false;
    }
    ++tail_;
    if (tail_ >= kCapacity) tail_ = 0;
    --count_;
    return true;
}

#include "LedStripRandom.h"

#include "RandomHelper.h"

namespace {

uint8_t gLedRngState = 1;

} // namespace

uint8_t LedStripRandom::nextRandom() const
{
    return notes_[RandomHelper::nextRandomIndex(gLedRngState, count_)];
}

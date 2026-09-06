#include "RandomHelper.h"

namespace RandomHelper
{

uint8_t nextRandomIndex(uint8_t& state, uint8_t count)
{
    if (count == 0) {
        return 0;
    }

    state ^= static_cast<uint8_t>(state << 7);
    state ^= static_cast<uint8_t>(state >> 5);
    state ^= static_cast<uint8_t>(state << 3);
    return state % count;
}

} // namespace RandomHelper

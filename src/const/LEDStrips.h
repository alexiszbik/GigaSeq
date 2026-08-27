#pragma once

namespace LedStrips {

#define STRIPE_START 60

#define STRIP_NOTES(stripName, nbr) \
    constexpr uint8_t kRed_##stripName = STRIPE_START + 0 + nbr*4; \
    constexpr uint8_t kGreen_##stripName = STRIPE_START + 1 + nbr*4; \
    constexpr uint8_t kBlue_##stripName = STRIPE_START + 2 + nbr*4; \
    constexpr uint8_t kWhite_##stripName = STRIPE_START + 3 + nbr*4; \

STRIP_NOTES(A, 0)
STRIP_NOTES(B, 1)
STRIP_NOTES(C, 2)
STRIP_NOTES(D, 3)

#undef STRIPE_START

}
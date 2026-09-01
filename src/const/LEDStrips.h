#pragma once

namespace LedStrips {

#define STRIPE_START 60

#define STRIP_NOTES(stripName, nbr) \
    constexpr uint8_t kRed_##stripName = STRIPE_START + 0 + nbr*4; \
    constexpr uint8_t kGreen_##stripName = STRIPE_START + 1 + nbr*4; \
    constexpr uint8_t kBlue_##stripName = STRIPE_START + 2 + nbr*4; \
    constexpr uint8_t kWhite_##stripName = STRIPE_START + 3 + nbr*4; \


#define STRIP_CC(name, nbr) constexpr uint8_t k##name##_cc = nbr;

STRIP_NOTES(A, 0)
STRIP_NOTES(B, 1)
STRIP_NOTES(C, 2)
STRIP_NOTES(D, 3)

constexpr uint8_t kRainbow_note = 58;
constexpr uint8_t kExplode_note = 59;

STRIP_CC(Decay, 3)
STRIP_CC(RainbowSpeed, 4)
STRIP_CC(ExplodeSpeed, 5)

#undef STRIPE_START
#undef STRIP_NOTES
#undef STRIP_CC

}
#pragma once

#include <cstdint>

namespace MidiChannel
{
    constexpr uint8_t kNone = 0;        // 1
    constexpr uint8_t kModularA = 1;    // 2
    constexpr uint8_t kModularB = 2;    // 3
    constexpr uint8_t kSampler = 3;  constexpr uint8_t kDrums = 3;      // 4
    constexpr uint8_t kPoly = 4;        // 5
    constexpr uint8_t kBass = 5;        // 6
    constexpr uint8_t kVocoder = 6;     // 7
    constexpr uint8_t kFM = 7;  constexpr uint8_t kMicrofreak = 7;        // 8
         // 9 maybe some CCs for the drum machine here

    constexpr uint8_t kDrumMachine = 8;    // 10
    constexpr uint8_t kGtrPedal = 9;    // 10
    constexpr uint8_t kGtrLoop = 10;    // 11
    constexpr uint8_t kMidiLoop = 11;   // 12
    constexpr uint8_t kCommon = 12;     // 13
    constexpr uint8_t kVJ = 13;         // 14
    constexpr uint8_t kLedStrips = 14; // 15
    constexpr uint8_t KMatrix = 15;    // 16

} // namespace MidiChannel

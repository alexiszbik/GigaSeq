#pragma once

#include "TrackPattern.h"
#include "factories/MidiNotes.h"
#include "FriendshipSamples.h"

namespace FriendshipPatterns
{


constexpr PatternStep kFriendshipStabsSteps[] = {
    {{Friendship::fbrStabs}, 127, 1},
    _NO_STEP
};

MAKE_PATTERN(kFriendshipStabs, kFriendshipStabsSteps, 1);


constexpr PatternStep kFriendshipHatsSteps[] = {
    {{Friendship::fbrHat}, 127, 1},
};

MAKE_PATTERN(kFriendshipHats, kFriendshipHatsSteps, 4);


constexpr PatternStep kFriendshipBraverySteps[] = {
    _NO_STEP, _NO_STEP, _NO_STEP,
    {{Friendship::fbrSpl2}, 127, 1},
};

MAKE_PATTERN(kFriendshipBravery, kFriendshipBraverySteps, 4);

constexpr PatternStep kFriendshipAndBraverySteps[] = {
    {{Friendship::fbrSpl1}, 127, 1}, _NO_STEP, _NO_STEP,
    {{Friendship::fbrSpl2}, 127, 1},
};

MAKE_PATTERN(kFriendshipAndBravery, kFriendshipAndBraverySteps, 4);


constexpr PatternStep kFriendshipXyloSteps[] = {
    _NO_STEP,
    {{Friendship::fbrXylo}, 127, 1},
};

MAKE_PATTERN(kFriendshipXylo, kFriendshipXyloSteps, 8);

constexpr PatternStep kFriendshipBalafonSteps[] = {
    {{Friendship::fbrBalaf}, 127, 1},
};

MAKE_PATTERN(kFriendshipBalafon, kFriendshipBalafonSteps, 4);


constexpr PatternStep kFriendshipTranceSteps[] = {
    STEP(Cd3), _NO_STEP, STEP(Cd3), _NO_STEP,
    {{Cd3}, 127, 2}, _NO_STEP, _NO_STEP, _NO_STEP,
 };

MAKE_PATTERN(kFriendshipTrance, kFriendshipTranceSteps, 32);

} // namespace FriendshipPatterns

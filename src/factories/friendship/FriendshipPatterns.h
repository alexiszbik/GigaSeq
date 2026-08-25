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

constexpr PatternStep kFriendshipTranceBSteps[] = {
    STEP(Cd3, Gd3), _NO_STEP, STEP(Cd3, Gd3), _NO_STEP,
    {{Cd3, Gd3}, 127, 2}, _NO_STEP, _NO_STEP, _NO_STEP,

    _NO_STEP, _NO_STEP, STEP(Cd3, Gd3), _NO_STEP,
    {{Cd3, Gd3}, 127, 2}, _NO_STEP, _NO_STEP, _NO_STEP,
};

MAKE_PATTERN(kFriendshipTranceB, kFriendshipTranceBSteps, 32);


constexpr PatternStep kFriendshipBassSteps[] = {
    STEP(Cd2), _NO_STEP, STEP(Cd2), _NO_STEP,
    _NO_STEP, STEP(Cd2), _NO_STEP, _NO_STEP,

    STEP(Cd2), _NO_STEP, STEP(Cd2), _NO_STEP,
    _NO_STEP, STEP(Cd2), _NO_STEP, _NO_STEP,

    STEP(Cd2), _NO_STEP, STEP(Cd2), _NO_STEP,
    _NO_STEP, STEP(Cd2), _NO_STEP, _NO_STEP,

    STEP(Cd2), _NO_STEP, STEP(Cd2), _NO_STEP,
    _NO_STEP, STEP(Cd2), STEP(Fd2), STEP(Gd2),



    STEP(Cd2), _NO_STEP, STEP(Cd2), _NO_STEP,
    _NO_STEP, STEP(Cd2), _NO_STEP, _NO_STEP,

    STEP(Cd2), _NO_STEP, STEP(Cd2), _NO_STEP,
    _NO_STEP, STEP(Cd2), _NO_STEP, _NO_STEP,

    STEP(Cd2), _NO_STEP, STEP(Cd2), _NO_STEP,
    _NO_STEP, STEP(Cd2), _NO_STEP, _NO_STEP,

    STEP(Cd2), _NO_STEP, STEP(Cd2), _NO_STEP,
    _NO_STEP, STEP(Cd2), STEP(Fd2), STEP(Gd2),



    STEP(Gd1), _NO_STEP, STEP(Gd1), _NO_STEP,
    _NO_STEP, STEP(Gd1), _NO_STEP, _NO_STEP,

    STEP(Gd1), _NO_STEP, STEP(Gd1), _NO_STEP,
    _NO_STEP, STEP(Gd1), _NO_STEP, _NO_STEP,

    STEP(Gd1), _NO_STEP, STEP(Gd1), _NO_STEP,
    _NO_STEP, STEP(Gd1), _NO_STEP, _NO_STEP,

    STEP(Gd1), _NO_STEP, STEP(Gd1), _NO_STEP,
    _NO_STEP, STEP(Gd1), STEP(Fd2), STEP(Gd2),


    STEP(Fd1), _NO_STEP, STEP(Fd1), _NO_STEP,
    _NO_STEP, STEP(Fd1), _NO_STEP, _NO_STEP,

    STEP(Fd1), _NO_STEP, STEP(Fd1), _NO_STEP,
    _NO_STEP, STEP(Fd1), _NO_STEP, _NO_STEP,

     STEP(Fd1), _NO_STEP, STEP(Fd1), _NO_STEP,
    _NO_STEP, STEP(Fd1), _NO_STEP, _NO_STEP,

    STEP(Fd1), STEP(Cd3), STEP(Gd2), STEP(Fd2), 
    STEP(Gd2), STEP(Cd3), STEP(Fd2), STEP(Fd3)

};

MAKE_PATTERN(kFriendshipBass, kFriendshipBassSteps, 16);


constexpr PatternStep kFriendshipJungleSteps[] = {
    {{Friendship::fbdrummy}, 127, 1},
};

MAKE_PATTERN(kFriendshipJungle, kFriendshipJungleSteps, 1);

//TODO : well if fact, i might not need _NO_STEP

constexpr PatternStep kFriendshipStabzSteps[] = {
    {{Friendship::fbstab}}, {}, {}, {}, {}, {}, {}, {}
};

MAKE_PATTERN(kFriendshipStabz, kFriendshipStabzSteps, 1);



constexpr PatternStep kFriendshipOpenH909Steps[] = {
    {}, {{Friendship::openhat}},
};

MAKE_PATTERN(kFriendshipOpenH909, kFriendshipOpenH909Steps, 8);


} // namespace FriendshipPatterns

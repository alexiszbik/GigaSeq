#pragma once

#include "Sequence.h"

class FriendshipSequenceFactory
{
public:
    static Sequence friendshipIntro();

    static Sequence friendshipChill();
    static Sequence friendshipBreak();
};

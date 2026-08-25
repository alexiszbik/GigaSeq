#pragma once

#include "Sequence.h"

class FriendshipSequenceFactory
{
public:
    static Sequence friendshipIntro();
    static Sequence friendshipChill();
    static Sequence friendshipBack();
    static Sequence friendshipMain();
    static Sequence friendshipBreak();
    static Sequence friendshipRising();
    static Sequence friendshipClimax();


    static Sequence friendshipEnd();
};

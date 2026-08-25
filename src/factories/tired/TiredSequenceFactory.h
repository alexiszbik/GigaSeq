#pragma once

#include "Sequence.h"

class TiredSequenceFactory
{
public:
    static Sequence tiredIntro();

    static Sequence tiredDropA();
    static Sequence tiredMain();

    static Sequence tiredPause();

    static Sequence tiredDropB();
    static Sequence tiredMainB();
    static Sequence tiredMainBBass();

    static Sequence tiredPartBStart();
    static Sequence tiredPartBSolo();
    static Sequence tiredPartBMain();
    static Sequence tiredPartBMain_2();
    static Sequence tiredBigEnd();

};

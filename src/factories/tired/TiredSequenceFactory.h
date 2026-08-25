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

    static Sequence tiredFreakArp();
    static Sequence tiredBigEnd();
   


};

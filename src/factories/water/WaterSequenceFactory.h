#pragma once

#include "Sequence.h"

class WaterSequenceFactory
{
public:
    static Sequence waterIntro();
    static Sequence waterPrechorus();
    static Sequence waterChorus();
    static Sequence waterPartB();
    static Sequence waterChorus2();
    static Sequence waterPartC();
    static Sequence waterPartCEnd();
    static Sequence waterChorusEnd();
};

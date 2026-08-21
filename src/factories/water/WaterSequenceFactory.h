#pragma once

#include "Sequence.h"

class WaterSequenceFactory
{
public:
    static Sequence waterIntro();
    static Sequence waterPrechorus();
    static Sequence waterChorus();
    static Sequence waterFull();
    static Sequence waterChorus2();
};

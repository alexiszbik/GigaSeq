#pragma once

#include "Sequence.h"

class TogetherSequenceFactory
{
public:
    static Sequence togetherIntro();
    static Sequence togetherSample();
    static Sequence togetherKick();
    static Sequence togetherVocoder();
    static Sequence togetherPause();
    static Sequence togetherClimax();
    static Sequence togetherRepeat();
    static Sequence togetherPartB();
    static Sequence togetherPartBWithHats();
    static Sequence togetherPartBDrums();
    static Sequence togetherPartBClimax();
};

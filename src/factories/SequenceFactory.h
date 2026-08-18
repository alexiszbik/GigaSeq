#pragma once

#include "Sequence.h"

class SequenceFactory
{
public:
    static Sequence togetherIntro();
    static Sequence togetherSample();
    static Sequence togetherKick();
    static Sequence togetherVocoder();

    static Sequence createSequenceOne();
    static Sequence createSequenceTwo();
    static Sequence createSequenceThree();
    static Sequence createSequenceFour();
    static Sequence createSequenceFive();
    static Sequence createSequenceSix();
    static Sequence createSequenceSeven();
};

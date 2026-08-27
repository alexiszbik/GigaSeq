#pragma once

#include "Sequence.h"

class CloserSequenceFactory
{
public:
    static Sequence closerIntro();

    static Sequence closerChords();
    static Sequence closerBass();
    static Sequence closerBlast();
    static Sequence closerBackKick();
    static Sequence closerClimax();

    static Sequence closerEnd();
};

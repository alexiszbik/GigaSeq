#pragma once

#include "Sequence.h"

class FantasySequenceFactory
{
public:
    static Sequence fantasyRave();

    static Sequence fantasyIntro();
    static Sequence fantasyStart();
    static Sequence fantasyBreak();
    static Sequence fantasyBack();
    static Sequence fantasyGuitar();
    static Sequence fantasyGuitarRiz();
    static Sequence fantasyClimax();
    static Sequence fantasyEnd();
};

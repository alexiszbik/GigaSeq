#!/bin/bash

read -p "Which song ? : " SONG

TRACK_CPP="$SONG"TrackFactory.cpp
TRACK_H="$SONG"TrackFactory.h

cd src/factories/SONG

sed -i '' '/mot_cle/{a nouvelle_ligne; q}' TRACK_H
(tac fichier.txt | sed '0,/}/s/}/NEW_LINE\n&/' | tac) > temp.cpp
mv temp.cpp TRACK_CPP

#!/bin/bash

SONG_NAME="$1"
UPPERCASE_SONG="$(tr '[:lower:]' '[:upper:]' <<< ${SONG_NAME:0:1})${SONG_NAME:1}"

SONG_FILE_CPP="$UPPERCASE_SONG"Song.cpp
TRACK_FILE_CPP="$UPPERCASE_SONG"TrackFactory.cpp
SEQUENCE_FILE_CPP="$UPPERCASE_SONG"SequenceFactory.cpp

SONG_FILE_H="$UPPERCASE_SONG"Song.h
TRACK_FILE_H="$UPPERCASE_SONG"TrackFactory.h
SEQUENCE_FILE_H="$UPPERCASE_SONG"SequenceFactory.h
PATTERNS_FILE_H="$UPPERCASE_SONG"Patterns.h

cd src/factories/

mkdir $SONG_NAME

_replace_words() {
 	sed -i -e "s/dummy/$SONG_NAME/g" $SONG_NAME/$1
 	sed -i -e "s/Dummy/$UPPERCASE_SONG/g" $SONG_NAME/$1

	rm $SONG_NAME/$1-e
}

cp dummy/DummySong.cpp $SONG_NAME/$SONG_FILE_CPP
_replace_words $SONG_FILE_CPP

cp dummy/DummySong.h $SONG_NAME/$SONG_FILE_H
_replace_words $SONG_FILE_H

cp dummy/DummyTrackFactory.cpp $SONG_NAME/$TRACK_FILE_CPP
_replace_words $TRACK_FILE_CPP

cp dummy/DummyTrackFactory.h $SONG_NAME/$TRACK_FILE_H
_replace_words $TRACK_FILE_H

cp dummy/DummySequenceFactory.cpp $SONG_NAME/$SEQUENCE_FILE_CPP
_replace_words $SEQUENCE_FILE_CPP

cp dummy/DummySequenceFactory.h $SONG_NAME/$SEQUENCE_FILE_H
_replace_words $SEQUENCE_FILE_H

cp dummy/DummyPatterns.h $SONG_NAME/$PATTERNS_FILE_H
_replace_words $PATTERNS_FILE_H



#!/usr/bin/env bash

if [ -z "${BASH_VERSION:-}" ]; then
    exec bash "$0" "$@"
fi

set -euo pipefail

SCRIPT_DIR="$(cd "$(dirname "$0")" && pwd)"
FACTORIES_DIR="${SCRIPT_DIR}/src/factories"
CMAKE_FILE="${SCRIPT_DIR}/CMakeLists.txt"

SONG_NAME="${1:-}"

if [[ -z "$SONG_NAME" ]]; then
    echo "Usage: $0 <song>" >&2
    exit 1
fi

SONG_NAME="$(tr '[:upper:]' '[:lower:]' <<< "$SONG_NAME")"
UPPERCASE_SONG="$(tr '[:lower:]' '[:upper:]' <<< "${SONG_NAME:0:1}")${SONG_NAME:1}"

SONG_FILE_CPP="${UPPERCASE_SONG}Song.cpp"
TRACK_FILE_CPP="${UPPERCASE_SONG}TrackFactory.cpp"
SEQUENCE_FILE_CPP="${UPPERCASE_SONG}SequenceFactory.cpp"

SONG_FILE_H="${UPPERCASE_SONG}Song.h"
TRACK_FILE_H="${UPPERCASE_SONG}TrackFactory.h"
SEQUENCE_FILE_H="${UPPERCASE_SONG}SequenceFactory.h"
PATTERNS_FILE_H="${UPPERCASE_SONG}Patterns.h"

SONG_DIR="${FACTORIES_DIR}/${SONG_NAME}"

if [[ -d "$SONG_DIR" ]]; then
    echo "Song folder already exists: ${SONG_DIR}" >&2
    exit 1
fi

if [[ ! -f "$CMAKE_FILE" ]]; then
    echo "CMakeLists.txt not found: ${CMAKE_FILE}" >&2
    exit 1
fi

replace_words() {
    local file="$1"
    if [[ "$(uname)" == "Darwin" ]]; then
        sed -i '' -e "s/dummy/${SONG_NAME}/g" -e "s/Dummy/${UPPERCASE_SONG}/g" "$file"
    else
        sed -i -e "s/dummy/${SONG_NAME}/g" -e "s/Dummy/${UPPERCASE_SONG}/g" "$file"
    fi
}

add_to_cmake() {
    local cmake_entry="src/factories/${SONG_NAME}/${UPPERCASE_SONG}Song.cpp"

    if grep -qF "$cmake_entry" "$CMAKE_FILE"; then
        echo "CMakeLists.txt already contains ${SONG_NAME} song sources."
        return
    fi

    local close_line
    close_line="$(grep -n '^)$' "$CMAKE_FILE" | head -1 | cut -d: -f1)"
    if [[ -z "$close_line" ]]; then
        echo "Could not find add_executable closing parenthesis in ${CMAKE_FILE}" >&2
        exit 1
    fi

    local tmpfile
    tmpfile="$(mktemp)"
    trap 'rm -f "$tmpfile"' RETURN

    {
        head -n $((close_line - 1)) "$CMAKE_FILE"
        cat <<EOF

    src/factories/${SONG_NAME}/${UPPERCASE_SONG}SequenceFactory.cpp
    src/factories/${SONG_NAME}/${UPPERCASE_SONG}Song.cpp
    src/factories/${SONG_NAME}/${UPPERCASE_SONG}TrackFactory.cpp

EOF
        tail -n +"$close_line" "$CMAKE_FILE"
    } > "$tmpfile"

    mv "$tmpfile" "$CMAKE_FILE"
    trap - RETURN
}

mkdir -p "$SONG_DIR"

cp "${FACTORIES_DIR}/dummy/DummySong.cpp" "${SONG_DIR}/${SONG_FILE_CPP}"
replace_words "${SONG_DIR}/${SONG_FILE_CPP}"

cp "${FACTORIES_DIR}/dummy/DummySong.h" "${SONG_DIR}/${SONG_FILE_H}"
replace_words "${SONG_DIR}/${SONG_FILE_H}"

cp "${FACTORIES_DIR}/dummy/DummyTrackFactory.cpp" "${SONG_DIR}/${TRACK_FILE_CPP}"
replace_words "${SONG_DIR}/${TRACK_FILE_CPP}"

cp "${FACTORIES_DIR}/dummy/DummyTrackFactory.h" "${SONG_DIR}/${TRACK_FILE_H}"
replace_words "${SONG_DIR}/${TRACK_FILE_H}"

cp "${FACTORIES_DIR}/dummy/DummySequenceFactory.cpp" "${SONG_DIR}/${SEQUENCE_FILE_CPP}"
replace_words "${SONG_DIR}/${SEQUENCE_FILE_CPP}"

cp "${FACTORIES_DIR}/dummy/DummySequenceFactory.h" "${SONG_DIR}/${SEQUENCE_FILE_H}"
replace_words "${SONG_DIR}/${SEQUENCE_FILE_H}"

cp "${FACTORIES_DIR}/dummy/DummyPatterns.h" "${SONG_DIR}/${PATTERNS_FILE_H}"
replace_words "${SONG_DIR}/${PATTERNS_FILE_H}"

add_to_cmake

echo "Created song '${SONG_NAME}'"
echo "  - ${SONG_DIR}/"
echo "  - ${CMAKE_FILE}"

#!/usr/bin/env bash

if [ -z "${BASH_VERSION:-}" ]; then
    exec bash "$0" "$@"
fi

set -euo pipefail

SONG_NAME="${1:-}"
PATTERN_NAME="${2:-}"
PATTERN_RATE="${3:-}"
PATTERN_GROOVE="${4:-}"

if [[ -z "$SONG_NAME" ]]; then
    read -r -p "Which song? : " SONG_NAME
fi

if [[ -z "$PATTERN_NAME" ]]; then
    read -r -p "Pattern name (e.g. hats, bass, arp) : " PATTERN_NAME
fi

if [[ -z "$PATTERN_RATE" ]]; then
    read -r -p "Pattern rate (steps per bar, default 16) : " PATTERN_RATE
    PATTERN_RATE="${PATTERN_RATE:-16}"
fi

if [[ -z "$PATTERN_GROOVE" ]]; then
    read -r -p "Pattern groove (0-25, default 0) : " PATTERN_GROOVE
    PATTERN_GROOVE="${PATTERN_GROOVE:-0}"
fi

if [[ -z "$SONG_NAME" || -z "$PATTERN_NAME" ]]; then
    echo "Usage: $0 <song> <pattern> [rate] [groove]" >&2
    exit 1
fi

if [[ "$PATTERN_GROOVE" -lt 0 || "$PATTERN_GROOVE" -gt 25 ]]; then
    echo "Groove must be between 0 and 25." >&2
    exit 1
fi

SONG_NAME="$(tr '[:upper:]' '[:lower:]' <<< "$SONG_NAME")"
UPPERCASE_SONG="$(tr '[:lower:]' '[:upper:]' <<< "${SONG_NAME:0:1}")${SONG_NAME:1}"
UPPERCASE_PATTERN="$(tr '[:lower:]' '[:upper:]' <<< "${PATTERN_NAME:0:1}")${PATTERN_NAME:1}"

PATTERN_CONST="k${UPPERCASE_SONG}${UPPERCASE_PATTERN}"
STEPS_CONST="${PATTERN_CONST}Steps"
NAMESPACE="${UPPERCASE_SONG}Patterns"
PATTERNS_H="src/factories/${SONG_NAME}/${UPPERCASE_SONG}Patterns.h"

if [[ ! -f "$PATTERNS_H" ]]; then
    echo "Patterns file not found: ${PATTERNS_H}" >&2
    echo "Run make_song.sh first to create the song." >&2
    exit 1
fi

if grep -q "${PATTERN_CONST}" "$PATTERNS_H"; then
    echo "Pattern '${PATTERN_CONST}' already exists in ${PATTERNS_H}." >&2
    exit 1
fi

if [[ "$PATTERN_GROOVE" == "0" ]]; then
    PATTERN_MACRO="MAKE_PATTERN(${PATTERN_CONST}, ${STEPS_CONST}, ${PATTERN_RATE})"
else
    PATTERN_MACRO="MAKE_PATTERN_GROOVE(${PATTERN_CONST}, ${STEPS_CONST}, ${PATTERN_RATE}, ${PATTERN_GROOVE})"
fi

NAMESPACE_CLOSE_LINE="$(grep -n "^} // namespace ${NAMESPACE}$" "$PATTERNS_H" | head -1 | cut -d: -f1)"
if [[ -z "$NAMESPACE_CLOSE_LINE" ]]; then
    echo "Could not find namespace closing brace in ${PATTERNS_H}" >&2
    exit 1
fi

TMPFILE="$(mktemp)"
trap 'rm -f "$TMPFILE"' EXIT

{
    head -n $((NAMESPACE_CLOSE_LINE - 1)) "$PATTERNS_H"
    cat <<EOF

constexpr PatternStep ${STEPS_CONST}[] = {
    {{C3}, 127, 1},
};

${PATTERN_MACRO};

EOF
    tail -n +"$NAMESPACE_CLOSE_LINE" "$PATTERNS_H"
} > "$TMPFILE"

mv "$TMPFILE" "$PATTERNS_H"
trap - EXIT

echo "Added ${NAMESPACE}::${PATTERN_CONST}"
echo "  steps  : ${STEPS_CONST}"
echo "  rate   : ${PATTERN_RATE}"
echo "  groove : ${PATTERN_GROOVE}"
echo "  - ${PATTERNS_H}"

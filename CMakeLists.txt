cmake_minimum_required(VERSION 3.20)
project(GigaSeq VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(FetchContent)

FetchContent_Declare(
    rtmidi
    GIT_REPOSITORY https://github.com/thestk/rtmidi.git
    GIT_TAG 6.0.0
)

set(RTMIDI_BUILD_TESTING OFF CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(rtmidi)

add_executable(GigaSeq
    src/desktop/main.cpp
    src/desktop/MidiClock.cpp
    src/desktop/TerminalLogger.cpp
    src/desktop/TransportPosition.cpp
    src/desktop/VirtualMidiSender.cpp
    src/engine/StringHelper.cpp
    src/engine/Sequence.cpp
    src/engine/Song.cpp
    src/engine/SequencePool.cpp
    src/engine/SequenceTrack.cpp
    src/factories/SequenceBuilder.cpp
    src/factories/SequenceTrackFactory.cpp
    src/factories/TrackPatternBuilder.cpp
    src/factories/TrackSpec.cpp
    src/platform/MemoryMonitor.cpp

    src/factories/together/TogetherSequenceFactory.cpp
    src/factories/together/TogetherSong.cpp
    src/factories/together/TogetherTrackFactory.cpp

    src/factories/water/WaterSequenceFactory.cpp
    src/factories/water/WaterSong.cpp
    src/factories/water/WaterTrackFactory.cpp

    src/factories/falling/FallingSequenceFactory.cpp
    src/factories/falling/FallingSong.cpp
    src/factories/falling/FallingTrackFactory.cpp

    src/factories/closer/CloserSequenceFactory.cpp
    src/factories/closer/CloserSong.cpp
    src/factories/closer/CloserTrackFactory.cpp

    src/factories/fantasy/FantasySequenceFactory.cpp
    src/factories/fantasy/FantasySong.cpp
    src/factories/fantasy/FantasyTrackFactory.cpp

)

target_include_directories(GigaSeq PRIVATE src src/engine src/desktop)
target_compile_definitions(GigaSeq PRIVATE GIGASEQ_LOCAL)
target_link_libraries(GigaSeq PRIVATE rtmidi)

if(APPLE)
    target_link_libraries(GigaSeq PRIVATE "-framework CoreMIDI" "-framework CoreFoundation")
endif()

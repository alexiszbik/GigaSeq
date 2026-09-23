#pragma once

#include "Logger.h"
#include "SequencerConsoleUI.h"

class UiTerminalLogger : public Logger
{
public:
    explicit UiTerminalLogger(SequencerConsoleUI& ui) : ui_(ui) {}

    void info(const char* message) override;
    void error(const char* message) override;

private:
    SequencerConsoleUI& ui_;
};

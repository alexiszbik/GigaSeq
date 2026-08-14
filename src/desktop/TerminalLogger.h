#pragma once

#include "Logger.h"

class TerminalLogger : public Logger
{
public:
    void info(const char* message) override;
    void error(const char* message) override;
};

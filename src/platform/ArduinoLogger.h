#pragma once

#include "Logger.h"

class ArduinoLogger : public Logger {
public:
    void info(const char* message) override;
    void error(const char* message) override;
};

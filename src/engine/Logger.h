#pragma once

class Logger
{
public:
    virtual ~Logger() = default;

    virtual void info(const char* message) = 0;
    virtual void error(const char* message) = 0;
};

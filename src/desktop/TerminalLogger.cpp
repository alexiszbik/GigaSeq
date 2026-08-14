#include "TerminalLogger.h"

#include <iostream>

void TerminalLogger::info(const char* message)
{
    if (message) {
        std::cout << message;
    }
}

void TerminalLogger::error(const char* message)
{
    if (message) {
        std::cerr << message;
    }
}

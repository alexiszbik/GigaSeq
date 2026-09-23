#include "UiTerminalLogger.h"

#include <string>

void UiTerminalLogger::info(const char* message)
{
    if (message != nullptr) {
        ui_.appendLog(message);
    }
}

void UiTerminalLogger::error(const char* message)
{
    if (message != nullptr) {
        ui_.appendLog(std::string("ERROR: ") + message);
    }
}

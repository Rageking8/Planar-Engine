#include "Planar/Engine/Export/Planar/Engine/Core/Log/TerminalLogger.hpp"
#include "Planar/Engine/Core/Log/TerminalLogger.hpp"

extern "C" __declspec(dllexport) void
Planar_Engine_Core_Log_TerminalLogger_log(const char* name,
    const char* text)
{
    Planar::Engine::Core::Log::TerminalLogger::get(name)->log(text);
}

extern "C" __declspec(dllexport) void
Planar_Engine_Core_Log_TerminalLogger_warn(const char* name,
    const char* text)
{
    Planar::Engine::Core::Log::TerminalLogger::get(name)->warn(text);
}

extern "C" __declspec(dllexport) void
Planar_Engine_Core_Log_TerminalLogger_error(const char* name,
    const char* text)
{
    Planar::Engine::Core::Log::TerminalLogger::get(name)->error(text);
}

extern "C" __declspec(dllexport) void
Planar_Engine_Core_Log_TerminalLogger_success(const char* name,
    const char* text)
{
    Planar::Engine::Core::Log::TerminalLogger::get(name)->success(text);
}

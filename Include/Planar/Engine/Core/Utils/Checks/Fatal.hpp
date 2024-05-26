#pragma once

#include "Planar/Engine/Core/Log/TerminalLogger.hpp"
#include "Planar/Engine/Core/Utils/Macros/StringMacros.hpp"

#include <exception>

#define PLANAR_FATAL(message)      \
    PLANAR_FATAL_TERMINAL(message) \

#define PLANAR_FATAL_TERMINAL(message)                             \
    do                                                             \
    {                                                              \
        Planar::Engine::Core::Log::TerminalLogger::get("Engine")-> \
            error("Fatal error occurred\n"                         \
                  "    Message: " #message "\n"                    \
                  "    File:    \"" __FILE__ "\" "                 \
                  "(line " PLANAR_LINE_STRING ")\n\n"              \
                  "Aborting...\n");                                \
        std::terminate();                                          \
    } while (false)                                                \

#pragma once

#include "Planar/Engine/Core/Log/TerminalLogger.hpp"
#include "Planar/Engine/Core/Utils/Macros/StringMacros.hpp"

#include <exception>

#define PLANAR_ASSERT(condition, message)      \
    PLANAR_ASSERT_TERMINAL(condition, message) \

#define PLANAR_ASSERT_TERMINAL(condition, message)                     \
    do                                                                 \
    {                                                                  \
        if (!(condition))                                              \
        {                                                              \
            Planar::Engine::Core::Log::TerminalLogger::get("Engine")-> \
                error("Assertion failed at \"" #condition "\"\n"       \
                      "    Message: " #message "\n"                    \
                      "    File:    \"" __FILE__ "\" "                 \
                      "(line " PLANAR_LINE_STRING ")\n\n"              \
                      "Aborting...\n");                                \
            std::terminate();                                          \
        }                                                              \
    } while (false)                                                    \

#define PLANAR_ASSERT_EMPTY(variable)                         \
    PLANAR_ASSERT(variable.empty(), `variable` must be empty) \

#define PLANAR_ASSERT_NOT_EMPTY(variable)                          \
    PLANAR_ASSERT(!variable.empty(), `variable` must not be empty) \

#define PLANAR_ASSERT_CONTAINS(container, value) \
    PLANAR_ASSERT(container.contains(value),     \
        `container` must contain `value`)        \

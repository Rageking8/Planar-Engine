#pragma once

#include "Planar/Engine/Export/ExportMacros.hpp"

#include <string>

namespace Planar::Engine::Core::Utils::Time
{
    enum class Format
    {
        // HH:MM:SS
        HHMMSS,

        // DD/MM/YYYY
        DDMMYYYY,

        // DD/MM/YYYY HH:MM:SS
        DDMMYYYYHHMMSS,
    };

    PLANAR_API std::string get_time_string(Format format);
}

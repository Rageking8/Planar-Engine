#pragma once

#include "Planar/Engine/Export/ExportMacros.hpp"
#include "Planar/Engine/Core/Utils/Time/Format.hpp"

#include <string>

namespace Planar::Engine::Core::Utils::Time
{
    PLANAR_API std::string get_time_string(Format format);
}

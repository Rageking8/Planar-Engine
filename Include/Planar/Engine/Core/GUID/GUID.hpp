#pragma once

#include "Planar/Engine/Export/ExportMacros.hpp"
#include "Planar/Engine/Core/GUID/Representation.hpp"

#include <string>

namespace Planar::Engine::Core::GUID
{
    PLANAR_API std::string generate_guid(
        Representation representation = Representation::DEFAULT);
}

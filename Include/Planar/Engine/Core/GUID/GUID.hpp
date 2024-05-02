#pragma once

#include "Planar/Engine/Core/ExportMacros.hpp"

#include <string>

namespace Planar::Engine::Core::GUID
{
    enum class Representation
    {
        // HHHHHHHH-HHHH-HHHH-HHHH-HHHHHHHHHHHH
        DEFAULT,

        // HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
        DEFAULT_COMPACT,
    };

    PLANAR_API std::string generate_guid(
        Representation representation = Representation::DEFAULT);
}

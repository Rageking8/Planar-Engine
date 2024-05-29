#pragma once

#include "Planar/Engine/Export/ExportMacros.hpp"

#include <filesystem>

namespace Planar::Engine::Core::Archive
{
    PLANAR_API void extract_7z(
        std::filesystem::path program_path,
        const std::filesystem::path& input_path);
}

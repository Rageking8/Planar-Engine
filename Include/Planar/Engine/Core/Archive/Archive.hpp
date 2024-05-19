#pragma once

#include "Planar/Engine/Export/ExportMacros.hpp"

#include <filesystem>

namespace Planar::Engine::Core::Archive
{
    PLANAR_API bool extract_zip(
        const std::filesystem::path& input_zip,
        const std::filesystem::path& output_path,
        unsigned buffer_size = 1024);
}

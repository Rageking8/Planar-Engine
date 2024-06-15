#pragma once

#include <filesystem>

namespace Planar::Editor::Build::Compression
{
    void compress(std::filesystem::path program_path,
        const std::filesystem::path& input_path,
        unsigned compression_level);
}

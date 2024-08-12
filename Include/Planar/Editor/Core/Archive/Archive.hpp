#pragma once

#include <filesystem>

namespace Planar::Editor::Core::Archive
{
    void extract_7z(std::filesystem::path program_path,
        const std::filesystem::path& input_path);
}

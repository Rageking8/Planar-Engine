#pragma once

#include "Planar/Engine/Export/ExportMacros.hpp"

#include <string>
#include <filesystem>

namespace Planar::Engine::Core::FileSystem
{
    PLANAR_API std::wstring select_folder_dialog();

    PLANAR_API void create_file(const std::filesystem::path& path,
        const std::string& contents);

    PLANAR_API std::string read_file(const std::filesystem::path& path);
}

#pragma once

#include "Planar/Engine/Export/ExportMacros.hpp"
#include "Planar/Engine/Core/FileSystem/ListingSortType.hpp"

#include <string>
#include <vector>
#include <filesystem>

namespace Planar::Engine::Core::FileSystem
{
    PLANAR_API std::wstring select_folder_dialog();

    PLANAR_API void create_file(const std::filesystem::path& path,
        const std::string& contents);

    PLANAR_API std::string read_file(const std::filesystem::path& path);

    PLANAR_API void sort_path_vector(
        std::vector<std::filesystem::path>& path_vector);

    PLANAR_API std::vector<std::filesystem::path> get_listing(
        const std::filesystem::path& path = ".",
        ListingSortType sort_type = ListingSortType::
        FOLDER_THEN_FILE_ALPHABETICAL);

    PLANAR_API void clear_file(const std::filesystem::path& path);
}

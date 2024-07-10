#pragma once

#include "Planar/Engine/Export/ExportMacros.hpp"
#include "Planar/Engine/Core/FileSystem/ListingSortType.hpp"
#include "Planar/Engine/Core/FileSystem/SelectDialogFilter.hpp"
#include "Planar/Engine/Core/Utils/Macros/DeclarationMacros.hpp"

#include <string>
#include <vector>
#include <cstddef>
#include <optional>
#include <functional>
#include <filesystem>
#include <unordered_set>

PLANAR_ENGINE_FORWARD_DECLARE_CLASS(Core::FileSystem,
    SelectDialogResult)

namespace Planar::Engine::Core::FileSystem
{
    PLANAR_API SelectDialogResult select_folder_dialog();

    PLANAR_API SelectDialogResult select_file_dialog(
        std::optional<SelectDialogFilter> filter = {});

    PLANAR_API void create_file(const std::filesystem::path& path,
        const std::string& contents);

    PLANAR_API std::string read_file(const std::filesystem::path& path);

    PLANAR_API void iterate_files_recursive(
        const std::filesystem::path& root,
        const std::function<void(const std::filesystem::path&)>& callback,
        const std::unordered_set<std::string>& skip_folders = {});

    PLANAR_API void sort_path_vector(
        std::vector<std::filesystem::path>& path_vector);

    PLANAR_API std::vector<std::filesystem::path> get_listing(
        const std::filesystem::path& path = ".",
        ListingSortType sort_type = ListingSortType::
        FOLDER_THEN_FILE_ALPHABETICAL);

    PLANAR_API unsigned file_count_with_extension(
        const std::filesystem::path& path,
        const std::string& extension);

    PLANAR_API std::filesystem::path first_file_with_extension(
        const std::filesystem::path& path,
        const std::string& extension);

    PLANAR_API void clear_file(const std::filesystem::path& path);

    template <typename T, std::size_t N>
    void append_array_to_file(const std::filesystem::path& path,
        T(&array)[N]);

    template <typename T>
    void append_array_to_file(const std::filesystem::path& path,
        T* array, std::size_t size);
}

#include "Planar/Engine/Core/FileSystem/FileSystem.tpp"

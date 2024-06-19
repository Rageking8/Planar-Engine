#pragma once

#include "Planar/Editor/Core/Progress/ProgressHandler.hpp"

#include <filesystem>

namespace Planar::Editor::Script::Init
{
    void verify_dotnet_sdk(const std::filesystem::path& path,
        const Core::Progress::ProgressHandler& progress_handler);

    void write_dotnet_sdk_7z(const std::filesystem::path& path);

    void extract_dotnet_sdk_7z(const std::filesystem::path& path,
        bool delete_zip = true);
}

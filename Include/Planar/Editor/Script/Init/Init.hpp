#pragma once

#include <filesystem>

namespace Planar::Editor::Script::Init
{
    void verify_dotnet_sdk(const std::filesystem::path& path);

    void write_dotnet_sdk_7z(const std::filesystem::path& path);

    void extract_dotnet_sdk_7z(const std::filesystem::path& path,
        bool delete_zip = true);
}

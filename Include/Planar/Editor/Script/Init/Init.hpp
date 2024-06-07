#pragma once

#include <string>
#include <filesystem>

namespace Planar::Editor::Script::Init
{
    void write_dotnet_sdk_7z(const std::filesystem::path& path);

    void extract_dotnet_sdk_7z(const std::filesystem::path& path,
        bool delete_zip = true);

    void create_cs_project_file(const std::filesystem::path& path,
        const std::string& project_name);
}

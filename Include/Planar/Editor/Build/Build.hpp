#pragma once

#include <filesystem>

namespace Planar::Editor::Build
{
    void build(std::filesystem::path project_root,
        std::filesystem::path dotnet_exe_path,
        std::filesystem::path build_path,
        bool remove_artifacts = true);
}

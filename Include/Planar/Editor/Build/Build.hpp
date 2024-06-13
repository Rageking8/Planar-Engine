#pragma once

#include "Planar/Editor/Script/CSProject.hpp"

#include <filesystem>

namespace Planar::Editor::Build
{
    void build(const Script::CSProject& cs_project,
        std::filesystem::path dotnet_exe_path,
        std::filesystem::path build_path,
        bool remove_artifacts = true);
}

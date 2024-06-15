#pragma once

#include "Planar/Editor/Project/Project.hpp"

#include <filesystem>

namespace Planar::Editor::Build
{
    void build(const Project::Project& project,
        std::filesystem::path build_path,
        bool show_console_window, unsigned compression_level,
        bool remove_artifacts = true);
}

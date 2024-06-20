#pragma once

#include "Planar/Editor/Project/Project.hpp"
#include "Planar/Editor/Core/Progress/ProgressHandler.hpp"

#include <filesystem>

namespace Planar::Editor::Build
{
    unsigned build_dry_run(const Project::Project& project,
        std::filesystem::path build_path,
        bool show_console_window, unsigned compression_level,
        bool remove_artifacts = true);

    void build(const Project::Project& project,
        std::filesystem::path build_path,
        bool show_console_window, unsigned compression_level,
        const Core::Progress::ProgressHandler& progress_handler,
        bool remove_artifacts = true);
}

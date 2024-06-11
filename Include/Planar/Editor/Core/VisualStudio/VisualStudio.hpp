#pragma once

#include "Planar/Editor/Script/CSProject.hpp"
#include "Planar/Editor/Core/Progress/Progress.hpp"

#include <filesystem>

namespace Planar::Editor::Core::VisualStudio
{
    void create_solution_file(const std::filesystem::path& path,
        const std::filesystem::path& dotnet_exe_path,
        const Script::CSProject& cs_project,
        const Progress::ProgressHandler& progress_handler);
}

#pragma once

#include "Planar/Editor/Core/Utils/Macros/DeclarationMacros.hpp"

#include <filesystem>

PLANAR_EDITOR_FORWARD_DECLARE_CLASS(Script, CSProject)
PLANAR_EDITOR_FORWARD_DECLARE_CLASS(Core::Progress, ProgressHandler)

namespace Planar::Editor::Core::VisualStudio
{
    void create_solution_file(const std::filesystem::path& path,
        const std::filesystem::path& dotnet_exe_path,
        const Script::CSProject& cs_project,
        const Progress::ProgressHandler& progress_handler);
}

#include "Planar/Editor/Core/VisualStudio/VisualStudio.hpp"
#include "Planar/Editor/Core/Progress/ProgressHandler.hpp"
#include "Planar/Editor/Core/Execute/Execute.hpp"
#include "Planar/Editor/Script/CSProject.hpp"

namespace Planar::Editor::Core::VisualStudio
{
    void create_solution_file(const std::filesystem::path& path,
        const std::filesystem::path& dotnet_exe_path,
        const Script::CSProject& cs_project,
        const Progress::ProgressHandler& progress_handler)
    {
        progress_handler("Creating new solution file");
        Execute::run_program(dotnet_exe_path, { "new", "sln",
            "--name", cs_project.get_name() }, path);
        progress_handler();

        progress_handler("Adding C# project to solution file");
        Execute::run_program(dotnet_exe_path, { "sln", "add",
            cs_project.get_absolute_path_string() }, path);
        progress_handler();
    }
}

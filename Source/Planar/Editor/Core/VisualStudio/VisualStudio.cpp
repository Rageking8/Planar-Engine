#include "Planar/Editor/Core/VisualStudio/VisualStudio.hpp"
#include "Planar/Engine/Core/Execute/Execute.hpp"

namespace Planar::Editor::Core::VisualStudio
{
    void create_solution_file(const std::filesystem::path& path,
        const std::filesystem::path& dotnet_exe_path,
        const Script::CSProject& cs_project,
        const Progress::ProgressHandler& progress_handler)
    {
        progress_handler("Creating new solution file");
        Engine::Core::Execute::run_program(path, dotnet_exe_path,
            { "new", "sln", "--name", cs_project.get_name() });
        progress_handler();

        progress_handler("Adding C# project to solution file");
        Engine::Core::Execute::run_program(path, dotnet_exe_path,
            { "sln", "add", cs_project.get_full_path().string() });
        progress_handler();
    }
}

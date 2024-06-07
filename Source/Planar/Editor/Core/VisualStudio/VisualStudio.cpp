#include "Planar/Editor/Core/VisualStudio/VisualStudio.hpp"
#include "Planar/Engine/Core/Execute/Execute.hpp"

namespace Planar::Editor::Core::VisualStudio
{
    void create_solution_file(const std::filesystem::path& path,
        const std::filesystem::path& dotnet_exe_path,
        const Script::CSProject& cs_project)
    {
        Engine::Core::Execute::run_program(path, dotnet_exe_path,
            { "new", "sln", "--name", cs_project.get_name() });
        Engine::Core::Execute::run_program(path, dotnet_exe_path,
            { "sln", "add", cs_project.get_full_path().string() });
    }
}

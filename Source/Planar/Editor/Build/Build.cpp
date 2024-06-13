#include "Planar/Editor/Build/Build.hpp"
#include "Planar/Editor/Build/Platform.hpp"
#include "Planar/Editor/Build/DotnetArguments.hpp"
#include "Planar/Engine/Core/Execute/Execute.hpp"

namespace Planar::Editor::Build
{
    void build(const Script::CSProject& cs_project,
        std::filesystem::path dotnet_exe_path,
        std::filesystem::path build_path,
        bool remove_artifacts)
    {
        dotnet_exe_path /= "dotnet.exe";

        DotnetArguments dotnet_arguments(Platform::WINDOWS_X64,
            cs_project.get_absolute_path_string());
        dotnet_arguments.add_property("SuppressOutputFolders", "False");
        dotnet_arguments.set_artifacts_path(build_path);
        dotnet_arguments.set_output_path(build_path);

        Engine::Core::Execute::run_program(".", dotnet_exe_path,
            dotnet_arguments.generate_publish_vector());

        if (remove_artifacts)
        {
            for (auto& i :
                std::filesystem::directory_iterator(build_path))
            {
                if (i.is_directory() || (i.is_regular_file() &&
                    i.path().extension() != ".exe"))
                {
                    std::filesystem::remove_all(i);
                }
            }
        }
    }
}

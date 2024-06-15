#include "Planar/Editor/Build/Build.hpp"
#include "Planar/Editor/Build/Platform.hpp"
#include "Planar/Editor/Build/DotnetArguments.hpp"
#include "Planar/Editor/Build/Compression/Compression.hpp"
#include "Planar/Engine/Core/Execute/Execute.hpp"

namespace Planar::Editor::Build
{
    void build(const Project::Project& project,
        std::filesystem::path build_path,
        bool show_console_window, unsigned compression_level,
        bool remove_artifacts)
    {
        const std::filesystem::path cache_path =
            project.get_root_path() / "Cache";
        const std::filesystem::path dotnet_exe_path =
            cache_path / "DotnetSDK" / "dotnet.exe";

        DotnetArguments dotnet_arguments(Platform::WINDOWS_X64,
            project.get_cs_project().get_absolute_path_string());

        if (show_console_window)
        {
            dotnet_arguments.add_property("OutputType", "Exe");
        }
        dotnet_arguments.add_property("SuppressOutputFolders", "False");

        dotnet_arguments.set_artifacts_path(build_path);
        dotnet_arguments.set_output_path(build_path);

        Engine::Core::Execute::run_program(dotnet_exe_path,
            dotnet_arguments.generate_publish_vector());

        if (compression_level > 0)
        {
            Compression::compress(cache_path, build_path /
                (project.get_project_name() + ".exe"),
                compression_level);
        }

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

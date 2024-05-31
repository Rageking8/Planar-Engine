#include "Planar/Editor/Build/Build.hpp"
#include "Planar/Engine/Core/Execute/Execute.hpp"

#include <string>

namespace Planar::Editor::Build
{
    void build(std::filesystem::path project_root,
        std::filesystem::path dotnet_exe_path,
        std::filesystem::path build_path,
        bool remove_artifacts)
    {
        project_root = std::filesystem::absolute(project_root);

        dotnet_exe_path /= "dotnet.exe";
        dotnet_exe_path = std::filesystem::absolute(dotnet_exe_path);

        build_path = std::filesystem::absolute(build_path);

        std::string build_path_string = build_path.string();

        Engine::Core::Execute::run(project_root, dotnet_exe_path,
            { "publish", project_root.string(), "--artifacts-path",
            build_path_string, "-r", "win-x64", "-o",
            build_path_string });

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

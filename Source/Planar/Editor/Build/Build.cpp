#include "Planar/Editor/Build/Build.hpp"
#include "Planar/Editor/Build/Platform.hpp"
#include "Planar/Editor/Build/DotnetArguments.hpp"
#include "Planar/Editor/Build/Compression/Compression.hpp"
#include "Planar/Editor/Core/Progress/Progress.hpp"
#include "Planar/Editor/Core/Progress/ProgressHandler.hpp"
#include "Planar/Editor/Core/Execute/Execute.hpp"
#include "Planar/Editor/Project/Project.hpp"
#include "Planar/Engine/Core/ApplicationAsset.hpp"

namespace
{
    unsigned build(bool dry_run,
        const Planar::Editor::Project::Project& project,
        std::filesystem::path build_path, bool show_console_window,
        unsigned compression_level, bool advanced_size_optimizations,
        const Planar::Engine::Core::ApplicationAsset& application_asset,
        const Planar::Editor::Core::Progress::ProgressHandler&
        progress_handler, bool remove_artifacts)
    {
        unsigned tasks = 0;

        const std::filesystem::path cache_path =
            project.get_root_path() / "Cache";
        const std::filesystem::path dotnet_exe_path =
            cache_path / "DotnetSDK" / "dotnet.exe";

        Planar::Editor::Core::Progress::task(
            "Writing application asset", [&]
            {
                application_asset.write(build_path /
                    "Application.planarapp");
            }, progress_handler, dry_run, tasks);

        Planar::Editor::Build::DotnetArguments dotnet_arguments(
            Planar::Editor::Build::Platform::WINDOWS_X64,
            project.get_cs_project().get_absolute_path_string());

        Planar::Editor::Core::Progress::task(
            "Generating build arguments", [&]
            {
                if (show_console_window)
                {
                    dotnet_arguments.add_property("OutputType", "Exe");
                }

                dotnet_arguments.add_property("SuppressOutputFolders",
                    "False");

                if (advanced_size_optimizations)
                {
                    dotnet_arguments.add_property(
                        "AdvancedSizeOptimizations", "True");
                }

                dotnet_arguments.set_artifacts_path(build_path);
                dotnet_arguments.set_output_path(build_path);
            }, progress_handler, dry_run, tasks);

        Planar::Editor::Core::Progress::task(
            "Building project", [&]
            {
                Planar::Editor::Core::Execute::run_program(
                    dotnet_exe_path, dotnet_arguments.
                    generate_publish_vector());
            }, progress_handler, dry_run, tasks);

        if (compression_level > 0)
        {
            Planar::Editor::Core::Progress::task(
                "Compressing build using UPX", [&]
                {
                    Planar::Editor::Build::Compression::compress(cache_path,
                        build_path / (project.get_project_name() + ".exe"),
                        compression_level);
                }, progress_handler, dry_run, tasks);
        }

        if (remove_artifacts)
        {
            Planar::Editor::Core::Progress::task(
                "Removing build artifacts", [&]
                {
                    for (auto& i : std::filesystem::directory_iterator(
                        build_path))
                    {
                        if (i.is_directory() || (i.is_regular_file() &&
                            i.path().extension() != ".exe"))
                        {
                            std::filesystem::remove_all(i);
                        }
                    }
                }, progress_handler, dry_run, tasks);
        }

        return tasks;
    }
}

namespace Planar::Editor::Build
{
    unsigned build_dry_run(const Project::Project& project,
        std::filesystem::path build_path, bool show_console_window,
        unsigned compression_level, bool advanced_size_optimizations,
        const Engine::Core::ApplicationAsset& application_asset,
        bool remove_artifacts)
    {
        return ::build(true, project, build_path, show_console_window,
            compression_level, advanced_size_optimizations,
            application_asset, {}, remove_artifacts);
    }

    void build(const Project::Project& project,
        std::filesystem::path build_path, bool show_console_window,
        unsigned compression_level, bool advanced_size_optimizations,
        const Engine::Core::ApplicationAsset& application_asset,
        const Core::Progress::ProgressHandler& progress_handler,
        bool remove_artifacts)
    {
        ::build(false, project, build_path, show_console_window,
            compression_level, advanced_size_optimizations,
            application_asset, progress_handler, remove_artifacts);
    }
}

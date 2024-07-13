#pragma once

#include "Planar/Editor/Core/Utils/Macros/DeclarationMacros.hpp"
#include "Planar/Engine/Core/Utils/Macros/DeclarationMacros.hpp"

#include <filesystem>

PLANAR_EDITOR_FORWARD_DECLARE_CLASS(Project, Project)
PLANAR_EDITOR_FORWARD_DECLARE_CLASS(Core::Progress, ProgressHandler)
PLANAR_ENGINE_FORWARD_DECLARE_CLASS(Core, ApplicationAsset)

namespace Planar::Editor::Build
{
    unsigned build_dry_run(const Project::Project& project,
        std::filesystem::path build_path,
        bool show_console_window, unsigned compression_level,
        const Engine::Core::ApplicationAsset& application_asset,
        bool remove_artifacts = true);

    void build(const Project::Project& project,
        std::filesystem::path build_path,
        bool show_console_window, unsigned compression_level,
        const Engine::Core::ApplicationAsset& application_asset,
        const Core::Progress::ProgressHandler& progress_handler,
        bool remove_artifacts = true);
}

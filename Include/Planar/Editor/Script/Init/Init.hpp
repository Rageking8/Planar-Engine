#pragma once

#include "Planar/Editor/Core/Utils/Macros/DeclarationMacros.hpp"

#include <filesystem>

PLANAR_EDITOR_FORWARD_DECLARE_CLASS(Core::Progress, ProgressHandler)

namespace Planar::Editor::Script::Init
{
    void verify_dotnet_sdk(const std::filesystem::path& path,
        const Core::Progress::ProgressHandler& progress_handler);

    void write_dotnet_sdk_7z(const std::filesystem::path& path);

    void extract_dotnet_sdk_7z(const std::filesystem::path& path,
        bool delete_zip = true);
}

#include "Planar/Editor/Script/Init/Init.hpp"
#include "Asset/Editor/dotnet_sdk.h"
#include "Planar/Engine/Asset/LoadAssetMacros.hpp"
#include "Planar/Engine/Core/FileSystem/FileSystem.hpp"
#include "Planar/Engine/Core/Archive/Archive.hpp"

PLANAR_LOAD_UNSIGNED_CHAR_ARRAY_ASSET_ALL_CHUNKS(Editor, dotnet_sdk)

namespace Planar::Editor::Script::Init
{
    void verify_dotnet_sdk(const std::filesystem::path& path)
    {
        if (!std::filesystem::exists(path / "DotnetSDK"))
        {
            std::filesystem::path dotnet_sdk_zip_path =
                path / "dotnet_sdk.7z";

            write_dotnet_sdk_7z(dotnet_sdk_zip_path);
            extract_dotnet_sdk_7z(dotnet_sdk_zip_path);
        }
    }

    void write_dotnet_sdk_7z(const std::filesystem::path& path)
    {
        Engine::Core::FileSystem::clear_file(path);
        PLANAR_APPEND_ALL_CHUNKS_TO_FILE(path, Editor, dotnet_sdk)
    }

    void extract_dotnet_sdk_7z(const std::filesystem::path& path,
        bool delete_zip)
    {
        Engine::Core::Archive::extract_7z(path.parent_path(),
            path);

        if (delete_zip)
        {
            std::filesystem::remove(path);
        }
    }
}

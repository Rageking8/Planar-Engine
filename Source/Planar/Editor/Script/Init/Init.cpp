#include "Planar/Editor/Script/Init/Init.hpp"
#include "Asset/Editor/dotnet_sdk.h"
#include "Planar/Engine/Asset/LoadAssetMacros.hpp"
#include "Planar/Engine/Core/FileSystem/FileSystem.hpp"
#include "Planar/Engine/Core/Archive/Archive.hpp"

#include <filesystem>

PLANAR_LOAD_UNSIGNED_CHAR_ARRAY_ASSET_ALL_CHUNKS(Editor, dotnet_sdk)

namespace Planar::Editor::Script::Init
{
    void write_dotnet_sdk_zip(const std::filesystem::path& path)
    {
        Planar::Engine::Core::FileSystem::clear_file(path);
        PLANAR_APPEND_ALL_CHUNKS_TO_FILE(path, Editor, dotnet_sdk)
    }

    void extract_dotnet_sdk_zip(const std::filesystem::path& path,
        bool delete_zip)
    {
        Planar::Engine::Core::Archive::extract_zip(path,
            path.parent_path());

        if (delete_zip)
        {
            std::filesystem::remove(path);
        }
    }
}

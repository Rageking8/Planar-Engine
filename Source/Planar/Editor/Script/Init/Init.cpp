#include "Planar/Editor/Script/Init/Init.hpp"
#include "Asset/Editor/dotnet_sdk.h"
#include "Planar/Engine/Asset/LoadAssetMacros.hpp"
#include "Planar/Engine/Core/FileSystem/FileSystem.hpp"

PLANAR_LOAD_UNSIGNED_CHAR_ARRAY_ASSET_ALL_CHUNKS(Editor, dotnet_sdk)

namespace Planar::Editor::Script::Init
{
    void write_dotnet_sdk_zip(const std::filesystem::path& path)
    {
        Planar::Engine::Core::FileSystem::clear_file(path);
        PLANAR_APPEND_ALL_CHUNKS_TO_FILE(path, Editor, dotnet_sdk)
    }
}

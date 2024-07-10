#include "Planar/Engine/Asset/AssetDatabase.hpp"
#include "Planar/Engine/Core/Sprite/Sprite.hpp"
#include "Planar/Engine/Core/FileSystem/FileSystem.hpp"

namespace Planar::Engine::Asset
{
    AssetDatabase::AssetDatabase()
    {

    }

    void AssetDatabase::load_asset_recursive(
        const std::filesystem::path& root)
    {
        Core::FileSystem::iterate_files_recursive(root,
            [&](const std::filesystem::path& path)
            {
                if (path.extension() == ".planarsprite")
                {
                    std::filesystem::path texture_path = path;
                    texture_path.replace_extension("png");

                    if (std::filesystem::exists(texture_path))
                    {
                        std::shared_ptr<Core::Sprite::Sprite> sprite =
                            std::make_shared<Core::Sprite::Sprite>();
                        sprite->load(path);

                        add_owning_asset(sprite);
                    }
                }
            }, { "Build", "Cache", "Engine" });
    }
}

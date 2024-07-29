#include "Planar/Engine/Asset/AssetDatabase.hpp"
#include "Planar/Engine/Audio/Audio.hpp"
#include "Planar/Engine/Core/Sprite/Sprite.hpp"
#include "Planar/Engine/Core/FileSystem/FileSystem.hpp"

namespace Planar::Engine::Asset
{
    AssetDatabase::AssetDatabase()
    {

    }

    void AssetDatabase::load_sprite(const std::string& name,
        const std::string& asset, const unsigned char* sprite,
        std::size_t length)
    {
        std::shared_ptr<Core::Sprite::Sprite> new_sprite =
            std::make_shared<Core::Sprite::Sprite>();
        new_sprite->load(name, asset, sprite, length);

        add_owning_asset(new_sprite);
    }

    void AssetDatabase::load_audio(const std::string& name,
        const std::string& asset, const unsigned char* audio,
        std::size_t length)
    {
        std::shared_ptr<Audio::Audio> new_audio =
            std::make_shared<Audio::Audio>();
        new_audio->load(name, asset, audio, length);

        add_owning_asset(new_audio);
    }

    void AssetDatabase::load_asset_recursive(
        const std::filesystem::path& root)
    {
        Core::FileSystem::iterate_files_recursive(root,
            [&](const std::filesystem::path& path)
            {
                if (path.extension() == ".planarsprite" &&
                    std::filesystem::exists(Core::FileSystem::
                    replace_extension(path, "png")))
                {
                    load_owning_asset<Core::Sprite::Sprite>(path);
                }
                else if (path.extension() == ".planaraudio" &&
                    std::filesystem::exists(Core::FileSystem::
                    replace_extension(path, "mp3")))
                {
                    load_owning_asset<Audio::Audio>(path);
                }
            }, { "Build", "Cache", "Engine" });
    }
}

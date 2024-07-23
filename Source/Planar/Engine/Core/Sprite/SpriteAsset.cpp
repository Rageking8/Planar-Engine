#include "Planar/Engine/Core/Sprite/SpriteAsset.hpp"
#include "Planar/Engine/Core/Constants/Version.hpp"
#include "Planar/Engine/Core/Sprite/Sprite.hpp"

namespace Planar::Engine::Core::Sprite
{
    SpriteAsset::SpriteAsset()
    {

    }

    void SpriteAsset::load(const std::filesystem::path& sprite_path)
    {
        Asset::load(sprite_path);
        path = sprite_path;
    }

    void SpriteAsset::create(Sprite& sprite,
        const std::filesystem::path& texture_path)
    {
        clear();
        set_value("Version", Constants::VERSION);
        set_value("GUID", sprite.get_guid());

        path = texture_path;
        path.replace_extension("planarsprite");
    }

    void SpriteAsset::save() const
    {
        write(path);
    }
}

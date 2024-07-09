#include "Planar/Engine/Core/Sprite/SpriteAsset.hpp"
#include "Planar/Engine/Core/Constants/Version.hpp"
#include "Planar/Engine/Core/Sprite/Sprite.hpp"
#include "Planar/Engine/Core/Utils/Checks/Assert.hpp"
#include "Planar/Engine/Core/FileSystem/FileSystem.hpp"
#include "Planar/Engine/Asset/AssetFunction.hpp"

namespace Planar::Engine::Core::Sprite
{
    SpriteAsset::SpriteAsset()
    {

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
        PLANAR_ASSERT_NOT_EMPTY(path);

        FileSystem::create_file(path,
            Engine::Asset::to_string(*asset));
    }
}

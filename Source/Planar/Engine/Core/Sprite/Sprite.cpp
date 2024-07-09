#include "Planar/Engine/Core/Sprite/Sprite.hpp"
#include "Planar/Engine/Core/GUID/GUID.hpp"

namespace Planar::Engine::Core::Sprite
{
    Sprite::Sprite()
    {

    }

    void Sprite::create(const std::filesystem::path& texture_path)
    {
        guid = GUID::generate_guid(
            GUID::Representation::DEFAULT_COMPACT);

        asset.create(*this, texture_path);
        texture.load(texture_path);
    }

    void Sprite::save() const
    {
        asset.save();
    }

    std::string Sprite::get_guid() const
    {
        return guid;
    }

    Graphics::OpenGL::Texture::Texture2D& Sprite::get_texture()
    {
        return texture;
    }
}

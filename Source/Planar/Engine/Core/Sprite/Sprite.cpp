#include "Planar/Engine/Core/Sprite/Sprite.hpp"
#include "Planar/Engine/Core/GUID/GUID.hpp"
#include "Planar/Engine/Graphics/OpenGL/Texture/TextureWrap.hpp"

namespace Planar::Engine::Core::Sprite
{
    Sprite::Sprite()
    {

    }

    void Sprite::load(const std::filesystem::path& sprite_path)
    {
        asset.load(sprite_path);

        name = sprite_path.stem().string();
        guid = asset.get_guid();

        std::filesystem::path texture_path = sprite_path;
        texture_path.replace_extension("png");
        load_texture(texture_path);
    }

    void Sprite::create(const std::filesystem::path& texture_path)
    {
        name = texture_path.stem().string();
        guid = GUID::generate_guid(
            GUID::Representation::DEFAULT_COMPACT);

        asset.create(*this, texture_path);
        load_texture(texture_path);
    }

    void Sprite::save() const
    {
        asset.save();
    }

    std::string Sprite::get_name() const
    {
        return name;
    }

    const std::string& Sprite::get_guid() const
    {
        return guid;
    }

    Graphics::OpenGL::Texture::Texture2D& Sprite::get_texture()
    {
        return texture;
    }

    void Sprite::load_texture(const std::filesystem::path& texture_path)
    {
        texture.load(texture_path);
        texture.set_wrap_s(Graphics::OpenGL::Texture::TextureWrap::REPEAT);
        texture.set_wrap_t(Graphics::OpenGL::Texture::TextureWrap::REPEAT);
    }
}

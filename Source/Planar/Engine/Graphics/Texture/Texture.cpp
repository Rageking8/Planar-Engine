#include "Planar/Engine/Graphics/Texture/Texture.hpp"
#include "Planar/Engine/Graphics/Load/Load.hpp"

namespace Planar::Engine::Graphics::Texture
{
    Texture::Texture() : texture{}
    {

    }

    Texture::Texture(const std::filesystem::path& texture_path) :
        texture{}
    {
        load(texture_path);
    }

    Texture::~Texture()
    {
        free();
    }

    void Texture::load(const std::filesystem::path& texture_path)
    {
        free();

        texture = Planar::Engine::Graphics::Load::load_image(
            texture_path);
    }

    void Texture::load(const unsigned char* buffer, std::size_t length)
    {
        free();

        texture = Planar::Engine::Graphics::Load::load_image(
            buffer, length);
    }

    void Texture::free()
    {
        glDeleteTextures(1, &texture);
        texture = 0;
    }

    GLuint Texture::get_texture() const
    {
        return texture;
    }
}

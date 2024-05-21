#include "Planar/Engine/Graphics/OpenGL/Texture/Texture.hpp"
#include "Planar/Engine/Graphics/OpenGL/Load/Load.hpp"

namespace Planar::Engine::Graphics::OpenGL::Texture
{
    Texture::Texture() : Resource(free_impl)
    {

    }

    Texture::Texture(const std::filesystem::path& texture_path) :
        Texture()
    {
        load(texture_path);
    }

    Texture::~Texture()
    {

    }

    void Texture::load(const std::filesystem::path& texture_path)
    {
        free();

        id =
            Planar::Engine::Graphics::OpenGL::Load::load_image(
            texture_path);
    }

    void Texture::load(const unsigned char* buffer, std::size_t length)
    {
        free();

        id =
            Planar::Engine::Graphics::OpenGL::Load::load_image(
            buffer, length);
    }

    void Texture::Texture::free_impl(GLuint id)
    {
        glDeleteTextures(1, &id);
    }
}

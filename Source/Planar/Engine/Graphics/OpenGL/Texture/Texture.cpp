#include "Planar/Engine/Graphics/OpenGL/Texture/Texture.hpp"

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

    bool Texture::load(const std::filesystem::path& texture_path)
    {
        free();

        Image::STBImage stb_image;
        if (!stb_image.load(texture_path))
        {
            return false;
        }

        id = create(stb_image);

        return true;
    }

    bool Texture::load(const unsigned char* buffer, std::size_t length)
    {
        free();

        Image::STBImage stb_image;
        if (!stb_image.load(buffer, length))
        {
            return false;
        }

        id = create(stb_image);

        return true;
    }

    GLuint Texture::create(Image::STBImage& stb_image)
    {
        GLuint texture = 0;

        glGenTextures(1, &texture);
        glBindTexture(GL_TEXTURE_2D, texture);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S,
            GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T,
            GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,
            GL_LINEAR_MIPMAP_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,
            GL_LINEAR);

        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, stb_image.get_width(),
            stb_image.get_height(), 0, GL_RGBA, GL_UNSIGNED_BYTE,
            stb_image.get_data());
        glGenerateMipmap(GL_TEXTURE_2D);

        return texture;
    }

    void Texture::Texture::free_impl(GLuint id)
    {
        glDeleteTextures(1, &id);
    }
}

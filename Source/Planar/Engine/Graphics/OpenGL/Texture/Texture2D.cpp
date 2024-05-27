#include "Planar/Engine/Graphics/OpenGL/Texture/Texture2D.hpp"

#include "ThirdParty/glad/gl.h"

namespace Planar::Engine::Graphics::OpenGL::Texture
{
    Texture2D::Texture2D()
    {

    }

    Texture2D::~Texture2D()
    {

    }

    void Texture2D::create(Image::STBImage& stb_image,
        Core::ObjectHandlingMode object_handling_mode)
    {
        create_texture(object_handling_mode);

        set_wrap_s(TextureWrap::CLAMP_TO_EDGE, object_handling_mode);
        set_wrap_t(TextureWrap::CLAMP_TO_EDGE, object_handling_mode);
        set_min_filter(TextureMinFilter::LINEAR_MIPMAP_LINEAR,
            object_handling_mode);
        set_mag_filter(TextureMagFilter::LINEAR,
            object_handling_mode);

        if (object_handling_mode == Core::ObjectHandlingMode::DSA)
        {
            bind();
        }

        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, stb_image.get_width(),
            stb_image.get_height(), 0, GL_RGBA, GL_UNSIGNED_BYTE,
            stb_image.get_data());

        switch (object_handling_mode)
        {
        case Core::ObjectHandlingMode::BIND:
            glGenerateMipmap(GL_TEXTURE_2D);
            break;

        case Core::ObjectHandlingMode::DSA:
            glGenerateTextureMipmap(id);
            break;
        }

        glBindTexture(GL_TEXTURE_2D, 0);
    }

    void Texture2D::create_raw(GLsizei width, GLsizei height,
        Core::ObjectHandlingMode object_handling_mode)
    {
        create_texture(object_handling_mode);

        set_min_filter(TextureMinFilter::LINEAR,
            object_handling_mode);
        set_mag_filter(TextureMagFilter::LINEAR,
            object_handling_mode);

        if (object_handling_mode == Core::ObjectHandlingMode::DSA)
        {
            bind();
        }

        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0,
            GL_RGBA, GL_UNSIGNED_BYTE, nullptr);

        glBindTexture(GL_TEXTURE_2D, 0);
    }

    void Texture2D::set_min_filter(TextureMinFilter new_min_filter,
        Core::ObjectHandlingMode object_handling_mode)
    {
        switch (object_handling_mode)
        {
        case Core::ObjectHandlingMode::BIND:
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,
                (GLint)new_min_filter);
            break;

        case Core::ObjectHandlingMode::DSA:
            glTextureParameteri(id, GL_TEXTURE_MIN_FILTER,
                (GLint)new_min_filter);
            break;
        }

        min_filter = new_min_filter;
    }

    void Texture2D::set_mag_filter(TextureMagFilter new_mag_filter,
        Core::ObjectHandlingMode object_handling_mode)
    {
        switch (object_handling_mode)
        {
        case Core::ObjectHandlingMode::BIND:
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,
                (GLint)new_mag_filter);
            break;

        case Core::ObjectHandlingMode::DSA:
            glTextureParameteri(id, GL_TEXTURE_MAG_FILTER,
                (GLint)new_mag_filter);
            break;
        }

        mag_filter = new_mag_filter;
    }

    void Texture2D::set_wrap_s(TextureWrap new_wrap_s,
        Core::ObjectHandlingMode object_handling_mode)
    {
        switch (object_handling_mode)
        {
        case Core::ObjectHandlingMode::BIND:
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S,
                (GLint)new_wrap_s);
            break;

        case Core::ObjectHandlingMode::DSA:
            glTextureParameteri(id, GL_TEXTURE_WRAP_S,
                (GLint)new_wrap_s);
            break;
        }
    }

    void Texture2D::set_wrap_t(TextureWrap new_wrap_t,
        Core::ObjectHandlingMode object_handling_mode)
    {
        switch (object_handling_mode)
        {
        case Core::ObjectHandlingMode::BIND:
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T,
                (GLint)new_wrap_t);
            break;

        case Core::ObjectHandlingMode::DSA:
            glTextureParameteri(id, GL_TEXTURE_WRAP_T,
                (GLint)new_wrap_t);
            break;
        }
    }

    void Texture2D::bind() const
    {
        glBindTexture(GL_TEXTURE_2D, id);
    }

    void Texture2D::create_texture(Core::ObjectHandlingMode
        object_handling_mode)
    {
        free();

        switch (object_handling_mode)
        {
        case Core::ObjectHandlingMode::BIND:
            glGenTextures(1, &id);
            bind();
            break;

        case Core::ObjectHandlingMode::DSA:
            glCreateTextures(GL_TEXTURE_2D, 1, &id);
            break;
        }
    }
}

#pragma once

#include "Planar/Engine/Export/ExportMacros.hpp"
#include "Planar/Engine/Graphics/OpenGL/Texture/Texture2D.hpp"
#include "Planar/Engine/Graphics/OpenGL/Core/Resource.hpp"
#include "Planar/Engine/Graphics/OpenGL/Core/ObjectHandlingMode.hpp"

#include "ThirdParty/glad/gl.h"

namespace Planar::Engine::Graphics::OpenGL::Framebuffer
{
    class PLANAR_API Framebuffer : public Core::Resource
    {
    public:
        Framebuffer();
        ~Framebuffer();

        void create(GLsizei width, GLsizei height,
            Core::ObjectHandlingMode object_handling_mode =
            Core::ObjectHandlingMode::DSA);

        GLuint get_color_texture_id() const;

        void resize_color_texture(GLsizei width, GLsizei height);

        void bind() const;
        void unbind() const;

    private:
        Texture::Texture2D color_texture;

        static void free_impl(GLuint id);
    };
}

#pragma once

#include "Planar/Engine/Export/ExportMacros.hpp"
#include "Planar/Engine/Graphics/OpenGL/Texture/Texture.hpp"
#include "Planar/Engine/Graphics/OpenGL/Texture/TextureMinFilter.hpp"
#include "Planar/Engine/Graphics/OpenGL/Texture/TextureMagFilter.hpp"
#include "Planar/Engine/Graphics/OpenGL/Core/ObjectHandlingMode.hpp"
#include "Planar/Engine/Graphics/Image/STBImage.hpp"

namespace Planar::Engine::Graphics::OpenGL::Texture
{
    class PLANAR_API Texture2D : public Texture
    {
    public:
        Texture2D();
        virtual ~Texture2D();

        virtual void create(Image::STBImage& stb_image,
            Core::ObjectHandlingMode object_handling_mode =
            Core::ObjectHandlingMode::DSA) override;
        virtual void create_raw(GLsizei width, GLsizei height,
            Core::ObjectHandlingMode object_handling_mode =
            Core::ObjectHandlingMode::DSA);

        virtual void set_min_filter(TextureMinFilter new_min_filter,
            Core::ObjectHandlingMode object_handling_mode =
            Core::ObjectHandlingMode::DSA) override;
        virtual void set_mag_filter(TextureMagFilter new_mag_filter,
            Core::ObjectHandlingMode object_handling_mode =
            Core::ObjectHandlingMode::DSA) override;

        virtual void set_wrap_s(TextureWrap new_wrap_s,
            Core::ObjectHandlingMode object_handling_mode =
            Core::ObjectHandlingMode::DSA) override;
        virtual void set_wrap_t(TextureWrap new_wrap_t,
            Core::ObjectHandlingMode object_handling_mode =
            Core::ObjectHandlingMode::DSA) override;

        void resize(GLsizei width, GLsizei height);

        virtual void bind() const override;
        virtual void unbind() const override;

    private:
        void create_texture(Core::ObjectHandlingMode
            object_handling_mode);
    };
}

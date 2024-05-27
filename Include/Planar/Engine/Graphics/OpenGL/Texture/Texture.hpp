#pragma once

#include "Planar/Engine/Export/ExportMacros.hpp"
#include "Planar/Engine/Graphics/OpenGL/Texture/TextureMinFilter.hpp"
#include "Planar/Engine/Graphics/OpenGL/Texture/TextureMagFilter.hpp"
#include "Planar/Engine/Graphics/OpenGL/Texture/TextureWrap.hpp"
#include "Planar/Engine/Graphics/OpenGL/Core/ObjectHandlingMode.hpp"
#include "Planar/Engine/Graphics/OpenGL/Core/Resource.hpp"
#include "Planar/Engine/Graphics/Image/STBImage.hpp"

#include "ThirdParty/glad/gl.h"

#include <cstddef>
#include <filesystem>

namespace Planar::Engine::Graphics::OpenGL::Texture
{
    class PLANAR_API Texture : public Core::Resource
    {
    public:
        Texture();
        Texture(const std::filesystem::path& texture_path,
            Core::ObjectHandlingMode object_handling_mode =
            Core::ObjectHandlingMode::DSA);
        virtual ~Texture();

        bool load(const std::filesystem::path& texture_path,
            Core::ObjectHandlingMode object_handling_mode =
            Core::ObjectHandlingMode::DSA);
        bool load(const unsigned char* buffer, std::size_t length,
            Core::ObjectHandlingMode object_handling_mode =
            Core::ObjectHandlingMode::DSA);

        virtual void create(Image::STBImage& stb_image,
            Core::ObjectHandlingMode object_handling_mode =
            Core::ObjectHandlingMode::DSA) = 0;
        virtual void create_raw(GLsizei width, GLsizei height,
            Core::ObjectHandlingMode object_handling_mode =
            Core::ObjectHandlingMode::DSA) = 0;

        TextureMinFilter get_min_filter() const;
        virtual void set_min_filter(TextureMinFilter new_min_filter,
            Core::ObjectHandlingMode object_handling_mode =
            Core::ObjectHandlingMode::DSA) = 0;

        TextureMagFilter get_mag_filter() const;
        virtual void set_mag_filter(TextureMagFilter new_mag_filter,
            Core::ObjectHandlingMode object_handling_mode =
            Core::ObjectHandlingMode::DSA) = 0;

        virtual void set_wrap_s(TextureWrap new_wrap_s,
            Core::ObjectHandlingMode object_handling_mode =
            Core::ObjectHandlingMode::DSA);
        virtual void set_wrap_t(TextureWrap new_wrap_t,
            Core::ObjectHandlingMode object_handling_mode =
            Core::ObjectHandlingMode::DSA);
        virtual void set_wrap_r(TextureWrap new_wrap_r,
            Core::ObjectHandlingMode object_handling_mode =
            Core::ObjectHandlingMode::DSA);

        virtual void bind() const = 0;

    protected:
        TextureMinFilter min_filter;
        TextureMagFilter mag_filter;

    private:
        static void free_impl(GLuint id);
    };
}

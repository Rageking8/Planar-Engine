#pragma once

#include "Planar/Engine/Export/ExportMacros.hpp"
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
        Texture(const std::filesystem::path& texture_path);
        ~Texture();

        bool load(const std::filesystem::path& texture_path);
        bool load(const unsigned char* buffer, std::size_t length);

        GLuint create(Image::STBImage& stb_image);

    private:
        static void free_impl(GLuint id);
    };
}

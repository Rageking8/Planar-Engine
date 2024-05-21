#pragma once

#include "Planar/Engine/Export/ExportMacros.hpp"
#include "Planar/Engine/Graphics/OpenGL/Core/Resource.hpp"

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

        void load(const std::filesystem::path& texture_path);
        void load(const unsigned char* buffer, std::size_t length);

    private:
        static void free_impl(GLuint id);
    };
}

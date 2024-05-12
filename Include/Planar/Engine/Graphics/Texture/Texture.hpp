#pragma once

#include "Planar/Engine/Export/ExportMacros.hpp"
#include "Planar/Engine/Core/Utils/Macros/TypeHelperMacros.hpp"

#include "ThirdParty/glad/gl.h"

#include <filesystem>

namespace Planar::Engine::Graphics::Texture
{
    class PLANAR_API Texture
    {
    public:
        Texture();
        Texture(const std::filesystem::path& texture_path);
        ~Texture();

        PLANAR_DELETE_COPY_FUNCTIONS(Texture)

        void load(const std::filesystem::path& texture_path);
        void free();

        GLuint get_texture() const;

    private:
        GLuint texture;
    };
}

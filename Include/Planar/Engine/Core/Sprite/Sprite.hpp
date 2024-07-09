#pragma once

#include "Planar/Engine/Export/ExportMacros.hpp"
#include "Planar/Engine/Core/Sprite/SpriteAsset.hpp"
#include "Planar/Engine/Graphics/OpenGL/Texture/Texture2D.hpp"

#include <string>
#include <filesystem>

namespace Planar::Engine::Core::Sprite
{
    class PLANAR_API Sprite
    {
    public:
        Sprite();

        void create(const std::filesystem::path& texture_path);

        void save() const;

        std::string get_guid() const;
        Graphics::OpenGL::Texture::Texture2D& get_texture();

    private:
        std::string guid;
        SpriteAsset asset;
        Graphics::OpenGL::Texture::Texture2D texture;
    };
}
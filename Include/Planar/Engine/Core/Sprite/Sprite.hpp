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

        void load(const std::filesystem::path& sprite_path);
        void create(const std::filesystem::path& texture_path);

        void save() const;

        std::string get_name() const;
        const std::string& get_guid() const;
        Graphics::OpenGL::Texture::Texture2D& get_texture();

    private:
        std::string name;
        std::string guid;
        SpriteAsset asset;
        Graphics::OpenGL::Texture::Texture2D texture;

        void load_texture(const std::filesystem::path& texture_path);
    };
}

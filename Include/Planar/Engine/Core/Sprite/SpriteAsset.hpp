#pragma once

#include "Planar/Engine/Export/ExportMacros.hpp"
#include "Planar/Engine/Asset/Asset.hpp"
#include "Planar/Engine/Core/Utils/Macros/DeclarationMacros.hpp"

#include <filesystem>

PLANAR_ENGINE_FORWARD_DECLARE_CLASS(Core::Sprite, Sprite)

namespace Planar::Engine::Core::Sprite
{
    class PLANAR_API SpriteAsset : public Asset::Asset
    {
    public:
        SpriteAsset();

        virtual void load(const std::filesystem::path& sprite_path)
            override;
        void create(Sprite& sprite,
            const std::filesystem::path& texture_path);

        void save() const;

    private:
        std::filesystem::path path;
    };
}

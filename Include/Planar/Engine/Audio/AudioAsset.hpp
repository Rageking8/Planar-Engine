#pragma once

#include "Planar/Engine/Export/ExportMacros.hpp"
#include "Planar/Engine/Asset/Asset.hpp"
#include "Planar/Engine/Core/Utils/Macros/DeclarationMacros.hpp"

#include <filesystem>

PLANAR_ENGINE_FORWARD_DECLARE_CLASS(Audio, Audio)

namespace Planar::Engine::Audio
{
    class PLANAR_API AudioAsset : public Asset::Asset
    {
    public:
        AudioAsset();

        virtual void load(const std::filesystem::path& audio_path)
            override;
        void create(Audio& audio,
            const std::filesystem::path& audio_path);

        void save() const;

    private:
        std::filesystem::path path;
    };
}

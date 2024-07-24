#pragma once

#include "Planar/Engine/Export/ExportMacros.hpp"
#include "Planar/Engine/Audio/AudioAsset.hpp"
#include "Planar/Engine/Core/Utils/Macros/DeclarationMacros.hpp"

#include <string>
#include <memory>
#include <filesystem>

PLANAR_FORWARD_DECLARE_CLASS(SoLoud, Wav)

namespace Planar::Engine::Audio
{
    class PLANAR_API Audio
    {
    public:
        Audio();
        ~Audio();

        void load(std::filesystem::path audio_path);
        void create(const std::filesystem::path& audio_path);

        void save() const;

        std::string get_name() const;
        const std::string& get_guid() const;

    private:
        std::string name;
        std::string guid;
        AudioAsset asset;
        std::unique_ptr<SoLoud::Wav> sound;

        void load_audio(const std::filesystem::path& audio_path);
    };
}

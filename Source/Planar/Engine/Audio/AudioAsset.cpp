#include "Planar/Engine/Audio/AudioAsset.hpp"
#include "Planar/Engine/Audio/Audio.hpp"
#include "Planar/Engine/Core/Constants/Version.hpp"

namespace Planar::Engine::Audio
{
    AudioAsset::AudioAsset()
    {

    }

    void AudioAsset::load(const std::filesystem::path& audio_path)
    {
        Asset::load(audio_path);
        path = audio_path;
    }

    void AudioAsset::create(Audio& audio,
        const std::filesystem::path& audio_path)
    {
        clear();
        set_value("Version", Core::Constants::VERSION);
        set_value("GUID", audio.get_guid());

        path = audio_path;
        path.replace_extension("planaraudio");
    }

    void AudioAsset::save() const
    {
        write(path);
    }
}

#include "Planar/Engine/Audio/Audio.hpp"
#include "Planar/Engine/Core/GUID/GUID.hpp"

#include "ThirdParty/SoLoud/soloud_wav.h"

namespace Planar::Engine::Audio
{
    Audio::Audio() :
        sound(std::make_unique<SoLoud::Wav>())
    {

    }

    Audio::~Audio()
    {
        sound->mSoloud = nullptr;
    }

    void Audio::load(std::filesystem::path audio_path)
    {
        asset.load(audio_path);

        name = audio_path.stem().string();
        guid = asset.get_guid();

        load_audio(audio_path.replace_extension("mp3"));
    }

    void Audio::create(const std::filesystem::path& audio_path)
    {
        name = audio_path.stem().string();
        guid = Core::GUID::generate_guid(
            Core::GUID::Representation::DEFAULT_COMPACT);

        asset.create(*this, audio_path);
        load_audio(audio_path);
    }

    void Audio::save() const
    {
        asset.save();
    }

    std::string Audio::get_name() const
    {
        return name;
    }

    const std::string& Audio::get_guid() const
    {
        return guid;
    }

    SoLoud::Wav& Audio::get_sound() const
    {
        return *sound;
    }

    void Audio::load_audio(const std::filesystem::path& audio_path)
    {
        sound->load(audio_path.string().c_str());
    }
}

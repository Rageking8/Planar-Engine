#include "Planar/Engine/Asset/Component/AudioSourceAsset.hpp"
#include "Planar/Engine/Asset/Component/Core/ComponentAssetMacros.hpp"
#include "Planar/Engine/Component/AudioSource.hpp"

namespace Planar::Engine::Asset::Component
{
    AudioSourceAsset::AudioSourceAsset()
    {

    }

    PLANAR_DEFINE_COMPONENT_ASSET_GET_SET_VALUE(AudioSource,
        std::string, audio, Audio)
    PLANAR_DEFINE_COMPONENT_ASSET_GET_SET_VALUE(AudioSource,
        bool, loop, Loop)

    void AudioSourceAsset::load_impl(
        Engine::Component::AudioSource& audio_source)
    {
        set_audio(audio_source.get_audio());
        set_loop(audio_source.get_loop());
    }
}

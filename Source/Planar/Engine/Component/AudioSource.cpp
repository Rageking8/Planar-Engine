#include "Planar/Engine/Component/AudioSource.hpp"

namespace Planar::Engine::Component
{
    AudioSource::AudioSource(GameObject::GameObject* parent,
        bool generate_guid) : Component(parent, generate_guid), loop{}
    {

    }

    PLANAR_DEFINE_COMPONENT_GET_SET(AudioSource, std::string, audio)
    PLANAR_DEFINE_COMPONENT_GET_SET(AudioSource, bool, loop)

    void AudioSource::load_impl()
    {
        set_audio(asset.get_audio());
        set_loop(asset.get_loop());
    }
}

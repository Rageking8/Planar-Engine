#include "Planar/Engine/Component/AudioSource.hpp"

namespace Planar::Engine::Component
{
    AudioSource::AudioSource(GameObject::GameObject* parent,
        bool generate_guid) : Component(parent, generate_guid)
    {

    }

    void AudioSource::load_impl()
    {

    }
}

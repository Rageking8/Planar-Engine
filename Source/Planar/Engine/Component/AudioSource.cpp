#include "Planar/Engine/Component/AudioSource.hpp"
#include "Planar/Engine/Core/Application.hpp"
#include "Planar/Engine/Audio/Audio.hpp"

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

    void AudioSource::update_impl()
    {
        if (!handle.empty())
        {
            return;
        }

        Engine::Core::Application* application = get_parent()->
            get_scene()->get_application();

        handle = application->get_audio_manager().play(*application->
            get_asset_database()->get_owning_asset<Audio::Audio>(audio));
    }

    void AudioSource::application_quit_impl()
    {
        if (handle.empty())
        {
            return;
        }

        handle.stop();
        handle.clear();
    }
}

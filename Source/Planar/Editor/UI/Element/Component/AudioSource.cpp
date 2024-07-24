#include "Planar/Editor/UI/Element/Component/AudioSource.hpp"
#include "Planar/Editor/Core/Editor.hpp"
#include "Planar/Engine/Audio/Audio.hpp"
#include "Planar/Engine/Core/Utils/Macros/FunctionalMacros.hpp"

namespace Planar::Editor::UI::Element::Component
{
    AudioSource::AudioSource() : audio("Audio", "AudioAsset",
        PLANAR_CAPTURE_THIS_PARAM1(update_audio_text)), loop("Loop")
    {

    }

    bool AudioSource::get_modified(bool reset)
    {
        return modified_helper(reset, active_checkbox, audio, loop);
    }

    void AudioSource::render_content()
    {
        render_helper(audio, loop);
    }

    void AudioSource::set_values_impl(ComponentType* audio_source)
    {
        active_checkbox.set_value(audio_source->get_active());
        audio.set_asset(audio_source->get_audio(), false, true);
        loop.set_value(audio_source->get_loop());
    }

    void AudioSource::write_values_impl(ComponentType* audio_source)
    {
        audio_source->set_active(active_checkbox.get_value());
        audio_source->set_audio(audio.get_asset());
        audio_source->set_loop(loop.get_value());
    }

    void AudioSource::update_audio_text(std::string new_audio)
    {
        audio.set_text(editor->get_asset_database()->
            get_owning_asset<Engine::Audio::Audio>(new_audio)->
            get_name() + ".planaraudio");
    }
}

#include "Planar/Editor/UI/Element/Component/AudioSource.hpp"

namespace Planar::Editor::UI::Element::Component
{
    AudioSource::AudioSource()
    {

    }

    bool AudioSource::get_modified(bool reset)
    {
        return modified_helper(reset, active_checkbox);
    }

    void AudioSource::render_content()
    {

    }

    void AudioSource::set_values_impl(ComponentType* audio_source)
    {
        active_checkbox.set_value(audio_source->get_active());
    }

    void AudioSource::write_values_impl(ComponentType* audio_source)
    {
        audio_source->set_active(active_checkbox.get_value());
    }
}

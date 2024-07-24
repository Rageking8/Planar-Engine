#pragma once

#include "Planar/Editor/UI/Element/Component/Core/Component.hpp"
#include "Planar/Engine/Component/AudioSource.hpp"

namespace Planar::Editor::UI::Element::Component
{
    class AudioSource :
        public Core::Component<Engine::Component::AudioSource>
    {
    public:
        AudioSource();

        virtual bool get_modified(bool reset = true) override;

    private:
        virtual void render_content() override;

        virtual void set_values_impl(ComponentType* audio_source)
            override;
        virtual void write_values_impl(ComponentType* audio_source)
            override;
    };
}

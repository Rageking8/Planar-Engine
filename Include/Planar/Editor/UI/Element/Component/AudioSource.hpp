#pragma once

#include "Planar/Editor/UI/Element/Component/Core/Component.hpp"
#include "Planar/Editor/UI/Element/AssetReference.hpp"
#include "Planar/Engine/UI/ImGui/Element/Checkbox.hpp"
#include "Planar/Engine/Component/AudioSource.hpp"

#include <string>

namespace Planar::Editor::UI::Element::Component
{
    class AudioSource :
        public Core::Component<Engine::Component::AudioSource>
    {
    public:
        AudioSource();

        virtual bool get_modified(bool reset = true) override;

    private:
        AssetReference audio;
        Engine::UI::ImGui::Element::Checkbox loop;

        virtual void render_content() override;

        virtual void set_values_impl(ComponentType* audio_source)
            override;
        virtual void write_values_impl(ComponentType* audio_source)
            override;

        void update_audio_text(std::string new_audio);
    };
}

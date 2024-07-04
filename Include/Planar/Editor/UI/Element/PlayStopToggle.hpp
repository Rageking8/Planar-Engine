#pragma once

#include "Planar/Engine/UI/ImGui/Element/Button/ToggleButton.hpp"
#include "Planar/Engine/Graphics/OpenGL/Texture/Texture2D.hpp"

namespace Planar::Editor::UI::Element
{
    class PlayStopToggle :
        public Engine::UI::ImGui::Element::Button::ToggleButton
    {
    public:
        enum class State
        {
            PLAY,

            STOP,
        };

        PlayStopToggle();

        State get() const;

    private:
        Engine::Graphics::OpenGL::Texture::Texture2D play_texture;
        Engine::Graphics::OpenGL::Texture::Texture2D stop_texture;
    };
}

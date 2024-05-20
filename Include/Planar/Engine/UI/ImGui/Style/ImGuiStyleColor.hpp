#pragma once

#include "Planar/Engine/Export/ExportMacros.hpp"
#include "Planar/Engine/Graphics/Color.hpp"
#include "Planar/Engine/UI/ImGui/Wrapper/PushPopWrapper.hpp"

namespace Planar::Engine::UI::ImGui::Style
{
    class PLANAR_API ImGuiStyleColor : public Wrapper::PushPopWrapper
    {
    public:
        ~ImGuiStyleColor();

        void set_button_background_color(
            Planar::Engine::Graphics::Color color);
        void set_button_hover_background_color(
            Planar::Engine::Graphics::Color color);
        void set_button_active_background_color(
            Planar::Engine::Graphics::Color color);

        virtual void pop() override;
    };
}

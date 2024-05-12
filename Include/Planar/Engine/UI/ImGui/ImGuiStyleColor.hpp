#pragma once

#include "Planar/Engine/Export/ExportMacros.hpp"
#include "Planar/Engine/Graphics/Color.hpp"

namespace Planar::Engine::UI::ImGui
{
    class PLANAR_API ImGuiStyleColor
    {
    public:
        ImGuiStyleColor();
        ~ImGuiStyleColor();

        void set_button_background_color(
            Planar::Engine::Graphics::Color color);
        void set_button_hover_background_color(
            Planar::Engine::Graphics::Color color);
        void set_button_active_background_color(
            Planar::Engine::Graphics::Color color);

        void pop();

    private:
        unsigned push_count;
    };
}

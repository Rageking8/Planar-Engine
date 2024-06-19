#pragma once

#include "Planar/Engine/Export/ExportMacros.hpp"
#include "Planar/Engine/Graphics/Color.hpp"
#include "Planar/Engine/UI/ImGui/Wrapper/PushPopWrapper.hpp"

namespace Planar::Engine::UI::ImGui::Style
{
    class PLANAR_API StyleColor : public Wrapper::PushPopWrapper
    {
    public:
        ~StyleColor();

        void set_frame_bg_color(Graphics::Color color);
        void set_plot_histogram_color(Graphics::Color color);

        void set_button_background_color(Graphics::Color color);
        void set_button_hover_background_color(
            Graphics::Color color);
        void set_button_active_background_color(
            Graphics::Color color);

        void set_resize_grip_color(Graphics::Color color);
        void set_resize_grip_hover_color(Graphics::Color color);
        void set_resize_grip_active_color(Graphics::Color color);
        void set_resize_grip_all_color(Graphics::Color color);

        virtual void pop() override;

    private:
        void push_style_color(int type, Graphics::Color color);
    };
}

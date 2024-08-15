#pragma once

#include "Planar/Engine/Export/ExportMacros.hpp"
#include "Planar/Engine/UI/ImGui/Wrapper/PushPopWrapper.hpp"
#include "Planar/Engine/Math/Size2D.hpp"

namespace Planar::Engine::UI::ImGui::Style
{
    class PLANAR_API StyleVar : public Wrapper::PushPopWrapper
    {
    public:
        ~StyleVar();

        void set_indent_spacing(float indent_spacing);
        void set_item_spacing(Math::Size2Df item_spacing);
        void set_frame_padding(Math::Size2Df padding);
        void set_window_padding(Math::Size2Df padding);
        void set_min_window_size(Math::Size2Df min_window_size);
        void set_tab_bar_overline_size(float overline_size);

        virtual void pop() override;

    private:
        void push_style_var(int type, float value);
        void push_style_var(int type, Math::Size2Df value);
    };
}

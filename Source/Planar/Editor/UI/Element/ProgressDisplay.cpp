#include "Planar/Editor/UI/Element/ProgressDisplay.hpp"
#include "Planar/Engine/UI/ImGui/ImGui.hpp"
#include "Planar/Engine/UI/ImGui/Core/Cursor/Cursor.hpp"

namespace Planar::Editor::UI::Element
{
    ProgressDisplay::ProgressDisplay(LayoutMode layout_mode) :
        layout_mode{ layout_mode }, y_offset{}
    {

    }

    void ProgressDisplay::render()
    {
        using namespace Planar::Engine::UI;

        const float text_y_pos_delta = y_offset - 40.f -
            progress_bar.get_height();
        const float progress_bar_y_pos_delta = y_offset -
            progress_bar.get_height();

        const auto set_and_render_progress_bar = [&]
            {
                ImGui::Core::Cursor::set_x(0.f);
                progress_bar.set_width(ImGui::get_window_size().
                    width);
                progress_bar.render();
            };

        switch (layout_mode)
        {
        case LayoutMode::VIEWPORT:
            ImGui::Core::Cursor::set_y_bottom_viewport(
                text_y_pos_delta);
            text_renderer.render_center_viewport(text);

            ImGui::Core::Cursor::set_y_bottom_viewport(
                progress_bar_y_pos_delta);
            set_and_render_progress_bar();
            break;

        case LayoutMode::WINDOW:
            ImGui::Core::Cursor::set_y_bottom_window(
                text_y_pos_delta);
            text_renderer.render_center_window(text);

            ImGui::Core::Cursor::set_y_bottom_window(
                progress_bar_y_pos_delta);
            set_and_render_progress_bar();
            break;
        }
    }

    void ProgressDisplay::set(unsigned delta, const std::string& text)
    {
        increment(delta);

        if (delta == 0)
        {
            set_text(text);
        }
    }

    void ProgressDisplay::set_layout_mode(
        LayoutMode new_layout_mode)
    {
        layout_mode = new_layout_mode;
    }

    void ProgressDisplay::set_text(const std::string& new_text)
    {
        text = new_text;
    }

    void ProgressDisplay::set_y_offset(float new_y_offset)
    {
        y_offset = new_y_offset;
    }

    void ProgressDisplay::increment(unsigned delta)
    {
        progress_bar.increment(delta);
    }

    void ProgressDisplay::reset(unsigned max)
    {
        progress_bar.set_value(0);
        progress_bar.set_max(max);
        text.clear();
    }
}

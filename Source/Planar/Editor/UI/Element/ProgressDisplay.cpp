#include "Planar/Editor/UI/Element/ProgressDisplay.hpp"
#include "Planar/Engine/UI/ImGui/ImGui.hpp"
#include "Planar/Engine/UI/ImGui/Core/Cursor/Cursor.hpp"

namespace Planar::Editor::UI::Element
{
    ProgressDisplay::ProgressDisplay()
    {

    }

    void ProgressDisplay::render()
    {
        using namespace Planar::Engine::UI;

        ImGui::Core::Cursor::set_y_bottom_viewport(
            -progress_bar.get_height() - 40.f);
        text_renderer.render_center_viewport(text);

        ImGui::Core::Cursor::set_x(0.f);
        ImGui::Core::Cursor::set_y_bottom_viewport(
            -progress_bar.get_height());
        progress_bar.set_width(ImGui::get_window_size().width);
        progress_bar.render();
    }

    void ProgressDisplay::set_text(const std::string& new_text)
    {
        text = new_text;
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

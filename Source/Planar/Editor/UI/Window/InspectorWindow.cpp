#include "Planar/Editor/UI/Window/InspectorWindow.hpp"

#include <functional>

namespace Planar::Editor::UI::Window
{
    InspectorWindow::InspectorWindow() : EditorWindow("Inspector"),
        name_input("Name",
        { Engine::UI::ImGui::Core::Size::Width::WidthMode::FILL })
    {

    }

    void InspectorWindow::init()
    {
        if (editor)
        {
            editor->get_select_handler().set_content_callback(
                std::bind(&InspectorWindow::select_content, this,
                std::placeholders::_1));
        }
    }

    void InspectorWindow::render_window()
    {
        using namespace Planar::Engine::UI;

        std::unique_ptr<Window::Scope> result = render();

        if (!result)
        {
            return;
        }

        name_input.render();
    }

    void InspectorWindow::select_content(const std::string& name)
    {
        name_input.set_text(name);
    }
}

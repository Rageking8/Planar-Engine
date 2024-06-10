#include "Planar/Editor/UI/Window/InspectorWindow.hpp"

namespace Planar::Editor::UI::Window
{
    InspectorWindow::InspectorWindow() : EditorWindow("Inspector"),
        name_input("Name",
        { Engine::UI::ImGui::Core::Size::Width::WidthMode::FILL })
    {

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

    void InspectorWindow::select_callback(const std::string& name)
    {
        name_input.set_text(name);
    }
}

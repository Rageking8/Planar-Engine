#include "Planar/Editor/UI/Window/InspectorWindow.hpp"
#include "Planar/Editor/Core/Editor.hpp"
#include "Planar/Engine/Core/Utils/Macros/FunctionalMacros.hpp"

namespace Planar::Editor::UI::Window
{
    InspectorWindow::InspectorWindow(Core::Editor* editor) :
        EditorWindow("Inspector", editor), name_input("Name",
        { Engine::UI::ImGui::Core::Size::Width::WidthMode::FILL,
        0.f, 20.f, 20.f })
    {
        set_padding({ { 0.f, 20.f } });
    }

    void InspectorWindow::init()
    {
        editor->get_select_handler().set_content_callback(
            PLANAR_CAPTURE_THIS_PARAM1(select_content));
        editor->get_select_handler().set_game_object_callback(
            PLANAR_CAPTURE_THIS_PARAM1(select_game_object));
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

    void InspectorWindow::select_game_object(
        const Engine::GameObject::GameObject& game_object)
    {
        name_input.set_text(game_object.get_name());
    }
}

#include "Planar/Editor/UI/Window/InspectorWindow.hpp"
#include "Planar/Editor/Core/Editor.hpp"
#include "Planar/Editor/Core/Select/SelectHandler.hpp"
#include "Planar/Editor/Core/Select/SelectType.hpp"
#include "Planar/Engine/GameObject/GameObject.hpp"
#include "Planar/Engine/UI/ImGui/Core/Cursor/Cursor.hpp"

namespace Planar::Editor::UI::Window
{
    InspectorWindow::InspectorWindow(Core::Editor* editor) :
        EditorWindow("Inspector", editor), name_input("Name",
        { Engine::UI::ImGui::Core::Size::Width::WidthMode::FILL,
        0.f, 20.f, 20.f })
    {
        set_padding({ { 0.f, 20.f } });
    }

    void InspectorWindow::update()
    {
        Core::Select::SelectHandler& select_handler =
            editor->get_select_handler();

        switch (select_handler.get_select_type())
        {
        case Core::Select::SelectType::NONE:
            break;

        case Core::Select::SelectType::CONTENT:
            name_input.set_text(select_handler.get_name());
            break;

        case Core::Select::SelectType::GAME_OBJECT:
            name_input.set_text(select_handler.get_game_object()->
                get_name());
            break;
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

        const Core::Select::SelectType select_type =
            editor->get_select_handler().get_select_type();

        if (select_type != Core::Select::SelectType::NONE)
        {
            name_input.render();
        }

        if (select_type == Core::Select::SelectType::GAME_OBJECT)
        {
            ImGui::Core::Cursor::move_y(8.f);
            transform2d.set_text("Transform2D");
            transform2d.render();
        }
    }
}

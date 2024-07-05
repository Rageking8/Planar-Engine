#include "Planar/Editor/UI/Window/InspectorWindow.hpp"
#include "Planar/Editor/Core/Editor.hpp"
#include "Planar/Editor/Core/EditorGameMode.hpp"
#include "Planar/Editor/Core/Select/SelectHandler.hpp"
#include "Planar/Editor/Core/Select/SelectType.hpp"
#include "Planar/Engine/GameObject/GameObject.hpp"
#include "Planar/Engine/UI/ImGui/Core/Cursor/Cursor.hpp"
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
        editor->get_select_handler().set_select_callback(
            PLANAR_CAPTURE_THIS_PARAM1(handle_select));
    }

    void InspectorWindow::update()
    {
        const Core::Select::SelectHandler& select_handler =
            editor->get_select_handler();
        const Core::Select::SelectType select_type =
            select_handler.get_select_type();
        const bool editor_game_playing = editor->
            get_editor_game_mode() == Core::EditorGameMode::PLAYING;

        if (name_input.get_modified())
        {
            switch (select_type)
            {
            case Core::Select::SelectType::NONE:
                break;

            case Core::Select::SelectType::CONTENT:
                break;

            case Core::Select::SelectType::GAME_OBJECT:
                select_handler.get_game_object()->set_name(
                    name_input.get_text());
                editor->set_dirty();
                break;
            }
        }

        if (select_type == Core::Select::SelectType::GAME_OBJECT)
        {
            std::shared_ptr<Engine::GameObject::GameObject>
                game_object = select_handler.get_game_object();

            if (component_store.write_components(*game_object))
            {
                editor->set_dirty();
            }

            if (editor_game_playing)
            {
                component_store.update_items(*game_object);
            }
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

        const Core::Select::SelectHandler& select_handler =
            editor->get_select_handler();
        const Core::Select::SelectType select_type =
            select_handler.get_select_type();

        if (select_type != Core::Select::SelectType::NONE)
        {
            name_input.render();
        }

        if (select_type == Core::Select::SelectType::GAME_OBJECT)
        {
            ImGui::Core::Cursor::move_y(8.f);

            component_renderer.render(component_store,
                *select_handler.get_game_object());
        }
    }

    void InspectorWindow::add_component(
        Engine::Component::ComponentType type)
    {
        const Core::Select::SelectHandler& select_handler =
            editor->get_select_handler();
        const Core::Select::SelectType select_type =
            select_handler.get_select_type();

        if (select_type != Core::Select::SelectType::GAME_OBJECT)
        {
            return;
        }

        std::shared_ptr<Engine::GameObject::GameObject>
            game_object = select_handler.get_game_object();

        game_object->add_component(type);
        component_store.update_items(*game_object);
        editor->set_dirty();
    }

    void InspectorWindow::handle_select(
        Core::Select::SelectType select_type)
    {
        const Core::Select::SelectHandler& select_handler =
            editor->get_select_handler();

        switch (select_type)
        {
        case Core::Select::SelectType::NONE:
            name_input.clear_text();
            break;

        case Core::Select::SelectType::CONTENT:
            name_input.set_text(select_handler.get_name());
            break;

        case Core::Select::SelectType::GAME_OBJECT:
            std::shared_ptr<Engine::GameObject::GameObject> game_object =
                select_handler.get_game_object();
            name_input.set_text(game_object->get_name());
            component_store.update_items(*game_object);
            break;
        }
    }
}

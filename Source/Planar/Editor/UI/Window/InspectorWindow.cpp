#include "Planar/Editor/UI/Window/InspectorWindow.hpp"
#include "Planar/Editor/Core/Editor.hpp"
#include "Planar/Editor/Core/EditorGameMode.hpp"
#include "Planar/Editor/Core/Select/SelectHandler.hpp"
#include "Planar/Editor/Core/Select/SelectType.hpp"
#include "Planar/Engine/GameObject/GameObject.hpp"
#include "Planar/Engine/UI/ImGui/ImGui.hpp"
#include "Planar/Engine/UI/ImGui/Core/Size/Width.hpp"
#include "Planar/Engine/UI/ImGui/Core/Cursor/Cursor.hpp"
#include "Planar/Engine/UI/ImGui/Core/Cursor/MoveMode.hpp"
#include "Planar/Engine/Core/Utils/Macros/FunctionalMacros.hpp"

namespace Planar::Editor::UI::Window
{
    InspectorWindow::InspectorWindow(Editor::Core::Editor* editor) :
        EditorWindow("Inspector", editor),
        active_checkbox("", true), name_input("Name", "",
        { Engine::UI::ImGui::Core::Size::Width::WidthMode::FILL,
        0.f, -4.f, 20.f }), component_store(editor),
        component_renderer(editor)
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
        Editor::Core::Select::SelectHandler& select_handler =
            editor->get_select_handler();
        const Editor::Core::Select::SelectType select_type =
            select_handler.get_select_type();
        const bool select_type_game_object = select_type ==
            Editor::Core::Select::SelectType::GAME_OBJECT;
        const bool editor_game_playing = editor->
            get_editor_game_mode() == Editor::Core::EditorGameMode::PLAYING;

        if (active_checkbox.get_modified() && select_type_game_object)
        {
            std::shared_ptr<Engine::GameObject::GameObject>
                game_object = select_handler.get_game_object();

            if (game_object)
            {
                game_object->set_active(active_checkbox.get_value());
                editor->set_dirty();
            }
        }

        if (name_input.get_modified() && select_type_game_object)
        {
            std::shared_ptr<Engine::GameObject::GameObject>
                game_object = select_handler.get_game_object();

            if (game_object)
            {
                game_object->set_name(name_input.get_text());
                editor->set_dirty();
            }
        }

        if (select_type_game_object)
        {
            std::shared_ptr<Engine::GameObject::GameObject>
                game_object = select_handler.get_game_object();

            if (game_object && component_store.write_components(
                *game_object))
            {
                editor->set_dirty();
            }

            if (game_object && editor_game_playing)
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

        Editor::Core::Select::SelectHandler& select_handler =
            editor->get_select_handler();
        const Editor::Core::Select::SelectType select_type =
            select_handler.get_select_type();
        const bool select_type_game_object = select_type ==
            Editor::Core::Select::SelectType::GAME_OBJECT;

        if (select_type_game_object)
        {
            ImGui::Core::Cursor::move_x(
                ImGui::Core::Cursor::MoveMode::DUMMY, -4.f);
            active_checkbox.render();
            ImGui::same_line();
            ImGui::Core::Cursor::move_x(
                ImGui::Core::Cursor::MoveMode::DUMMY, -56.f);
        }

        if (select_type != Editor::Core::Select::SelectType::NONE)
        {
            name_input.render();
        }

        if (select_type_game_object)
        {
            ImGui::Core::Cursor::move_y(
                ImGui::Core::Cursor::MoveMode::SET_CURSOR, 8.f, false);

            std::shared_ptr<Engine::GameObject::GameObject>
                game_object = select_handler.get_game_object();

            if (game_object)
            {
                component_renderer.render(&component_store,
                    game_object, &context_menu);
            }
        }
    }

    void InspectorWindow::handle_select(
        Editor::Core::Select::SelectType select_type)
    {
        Editor::Core::Select::SelectHandler& select_handler =
            editor->get_select_handler();

        switch (select_type)
        {
        case Editor::Core::Select::SelectType::NONE:
            name_input.clear_text();
            break;

        case Editor::Core::Select::SelectType::CONTENT:
            name_input.set_text(select_handler.get_name());
            break;

        case Editor::Core::Select::SelectType::GAME_OBJECT:
            std::shared_ptr<Engine::GameObject::GameObject>
                game_object = select_handler.get_game_object();

            if (game_object)
            {
                active_checkbox.set_value(game_object->active_self());
                name_input.set_text(game_object->get_name());
                component_store.update_items(*game_object);
            }
            break;
        }
    }
}

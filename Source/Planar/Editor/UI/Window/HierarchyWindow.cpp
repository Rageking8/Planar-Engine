#include "Planar/Editor/UI/Window/HierarchyWindow.hpp"
#include "Planar/Editor/Core/Editor.hpp"
#include "Planar/Engine/Scene/Scene.hpp"
#include "Planar/Engine/UI/ImGui/Menu/Menu.hpp"
#include "Planar/Engine/GameObject/GameObject.hpp"
#include "Planar/Engine/Core/Utils/Macros/FunctionalMacros.hpp"

namespace Planar::Editor::UI::Window
{
    HierarchyWindow::HierarchyWindow(Editor::Core::Editor* editor) :
        EditorWindow("Hierarchy", editor), context_menu_active{}
    {
        set_padding({ { 0.f, 15.f } });
    }

    void HierarchyWindow::render_window()
    {
        using namespace Engine::UI;

        std::unique_ptr<Window::Scope> result = render();

        if (!result)
        {
            return;
        }

        if (context_menu_active)
        {
            context_menu_active = context_menu.render({}, { false });
        }

        if (editor->get_current_scene())
        {
            std::unique_ptr<Engine::Scene::Scene>& current_scene =
                editor->get_current_scene();

            hierarchy_tree.set_text(current_scene->get_name());
            hierarchy_tree.set_id(current_scene->get_asset().
                get_guid());
            render_scene_game_object(current_scene->get_root());
        }
    }

    void HierarchyWindow::render_scene_game_object(
        std::shared_ptr<Engine::GameObject::GameObject> game_object)
    {
        hierarchy_tree.clear_drag_source();

        if (!game_object->is_empty())
        {
            hierarchy_tree.set_text(game_object->get_name());
            hierarchy_tree.set_id(game_object->get_guid());
            hierarchy_tree.set_drag_source("GameObject",
                &game_object->get_guid());
        }

        hierarchy_tree.render(
            PLANAR_CAPTURE_REF_ARG1(handle_select, game_object),
            PLANAR_CAPTURE_REF_ARG1(render_context_menu, game_object),
            PLANAR_CAPTURE_REF_ARG1(render_scene_children, game_object)
        );
    }

    void HierarchyWindow::render_scene_children(
        std::shared_ptr<Engine::GameObject::GameObject> game_object)
    {
        for (auto& i : game_object->get_children())
        {
            if (i->is_leaf())
            {
                hierarchy_tree.set_is_leaf(true);
            }

            render_scene_game_object(i);

            hierarchy_tree.set_is_leaf(false);
        }
    }

    void HierarchyWindow::render_context_menu(
        std::shared_ptr<Engine::GameObject::GameObject> game_object)
    {
        using namespace Engine::UI;

        if (context_menu_active)
        {
            return;
        }

        context_menu.set_content([=]
            {
                if (ImGui::Menu::menu_item("Create GameObject"))
                {
                    game_object->add_child();

                    editor->set_dirty();

                    return true;
                }

                context_menu.add_separator();

                if (game_object->is_empty())
                {
                    if (ImGui::Menu::menu_item("Close Scene"))
                    {
                        editor->close_current_scene();

                        return true;
                    }
                }
                else
                {
                    if (ImGui::Menu::menu_item("Remove"))
                    {
                        if (game_object->is_root())
                        {
                            editor->get_current_scene()->get_root()->
                                remove_child(game_object->get_guid());
                        }
                        else
                        {
                            game_object->get_parent()->remove_child(
                                game_object->get_guid());
                        }

                        editor->set_dirty();

                        return true;
                    }
                }

                return false;
            });

        if (context_menu.render({}, { true }))
        {
            context_menu_active = true;
        }
    }

    void HierarchyWindow::handle_select(
        std::shared_ptr<Engine::GameObject::GameObject> game_object)
    {
        if (game_object->is_empty())
        {
            return;
        }

        editor->get_select_handler().select_game_object(game_object,
            game_object->get_guid());
    }
}

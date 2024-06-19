#include "Planar/Editor/UI/Window/HierarchyWindow.hpp"
#include "Planar/Engine/UI/ImGui/ImGui.hpp"

#include <functional>

namespace Planar::Editor::UI::Window
{
    HierarchyWindow::HierarchyWindow() : EditorWindow("Hierarchy"),
        context_menu_active{}
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
            context_menu_active = context_menu.render();
        }

        if (editor && editor->get_current_scene())
        {
            std::unique_ptr<Engine::Scene::Scene>& current_scene =
                editor->get_current_scene();

            hierarchy_tree.set_label(current_scene->get_asset().
                get_name() + "##" + current_scene->get_asset().
                get_guid());
            render_scene_node(current_scene->get_root());
        }
    }

    void HierarchyWindow::render_scene_node(
        Engine::Scene::SceneNode& scene_node)
    {
        Engine::Core::GameObject* current_game_object = nullptr;
        bool has_game_object = !scene_node.is_root_node();

        if (has_game_object)
        {
            current_game_object = &scene_node.get_game_object();
            hierarchy_tree.set_label(current_game_object->get_name() +
                "##" + current_game_object->get_guid());
        }

        hierarchy_tree.render(
            std::bind(&HierarchyWindow::render_context_menu, this,
            scene_node),

            std::bind(&HierarchyWindow::handle_select, this,
            current_game_object),

            std::bind(&HierarchyWindow::render_scene_node_children,
            this, scene_node)
        );
    }

    void HierarchyWindow::render_scene_node_children(
        Engine::Scene::SceneNode& scene_node)
    {
        for (auto& i : *scene_node.get_children())
        {
            if (i.is_leaf_node())
            {
                hierarchy_tree.set_is_leaf(true);
            }

            render_scene_node(i);

            hierarchy_tree.set_is_leaf(false);
        }
    }

    void HierarchyWindow::render_context_menu(
        Engine::Scene::SceneNode& scene_node)
    {
        using namespace Engine::UI;

        if (context_menu_active)
        {
            return;
        }

        context_menu.set_content([&]
            {
                if (ImGui::menu_item("Create GameObject"))
                {
                    scene_node.add_child();

                    if (editor)
                    {
                        editor->set_dirty();
                    }

                    return true;
                }

                return false;
            });

        if (context_menu.render())
        {
            context_menu_active = true;
        }
    }

    void HierarchyWindow::handle_select(
        Engine::Core::GameObject* current_game_object)
    {
        if (current_game_object && editor)
        {
            editor->get_select_handler().select_game_object(
                *current_game_object);
        }
    }
}

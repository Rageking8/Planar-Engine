#include "Planar/Editor/Scene/EditorScene.hpp"
#include "Planar/Engine/UI/ImGui/ImGui.hpp"

namespace Planar::Editor::Scene
{
    EditorScene::EditorScene()
    {

    }

    void EditorScene::init()
    {
        using namespace Planar::Engine::UI;

        hierarchy_window.set_name("Hierarchy");
        scene_window.set_name("Scene");
        game_window.set_name("Game");
        inspector_window.set_name("Inspector");
        settings_window.set_name("Settings");
        content_window.set_name("Content");
        console_window.set_name("Console");
    }

    void EditorScene::render()
    {
        using namespace Planar::Engine::UI;

        ImGui::dock_space_over_viewport();

        {
            auto hierarchy_window_scope = hierarchy_window.render();
        }

        {
            auto scene_window_scope = scene_window.render();
        }

        {
            auto game_window_scope = game_window.render();
        }

        {
            auto inspector_window_scope = inspector_window.render();
        }

        {
            auto settings_window_scope = settings_window.render();
        }

        {
            auto content_window_scope = content_window.render();
        }

        {
            auto console_window_scope = console_window.render();
        }
    }
}

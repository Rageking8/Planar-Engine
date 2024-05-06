#include "Planar/Editor/Scene/EditorScene.hpp"
#include "Planar/Engine/UI/ImGui/ImGui.hpp"
#include "Planar/Engine/UI/ImGui/ImGuiMainMenuBar.hpp"
#include "Planar/Engine/Asset/LoadAssetMacros.hpp"

PLANAR_LOAD_STD_STRING_ASSET(Editor, DefaultLayout)

namespace Planar::Editor::Scene
{
    EditorScene::EditorScene() :
        pending_restore_default_layout{}
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

        restore_default_layout();
    }

    void EditorScene::update()
    {
        if (pending_restore_default_layout)
        {
            restore_default_layout();

            pending_restore_default_layout = false;
        }
    }

    void EditorScene::render()
    {
        using namespace Planar::Engine::UI;

        ImGui::dock_space_over_viewport();

        render_main_menu_bar();

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

            if (ImGui::button("Restore Default Layout"))
            {
                pending_restore_default_layout = true;
            }
        }

        {
            auto content_window_scope = content_window.render();
        }

        {
            auto console_window_scope = console_window.render();
        }
    }

    void EditorScene::restore_default_layout() const
    {
        Planar::Engine::UI::ImGui::load_ini_from_string(
            Planar::Asset::Editor::DefaultLayout);
    }

    void EditorScene::render_main_menu_bar() const
    {
        using namespace Planar::Engine::UI;

        ImGui::ImGuiMainMenuBar main_menu_bar;
        if (main_menu_bar.start())
        {
            main_menu_bar.add_menu("File",
                [&]()
                {
                    main_menu_bar.add_menu_item("New Project");
                    main_menu_bar.add_menu_item("Open Project");
                    
                    main_menu_bar.add_menu_separator();

                    main_menu_bar.add_menu_item("Save", "Ctrl + S");
                    main_menu_bar.add_menu_item("Save As",
                        "Ctrl + Shift + S");

                    main_menu_bar.add_menu_separator();

                    main_menu_bar.add_menu_item("Exit");
                });

            main_menu_bar.add_menu("Build",
                [&]()
                {
                    main_menu_bar.add_menu_item("Build Project");
                });

            main_menu_bar.add_menu("Help",
                [&]()
                {
                    main_menu_bar.add_menu_item("Website");
                });
        }
    }
}

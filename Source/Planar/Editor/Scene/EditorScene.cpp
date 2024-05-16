#include "Planar/Editor/Scene/EditorScene.hpp"
#include "Planar/Engine/UI/ImGui/ImGui.hpp"
#include "Planar/Engine/UI/ImGui/ImGuiMainMenuBar.hpp"
#include "Planar/Engine/Asset/LoadAssetMacros.hpp"
#include "Planar/Engine/Core/Shell/Shell.hpp"

PLANAR_LOAD_STD_STRING_ASSET(Editor, DefaultLayout)

namespace Planar::Editor::Scene
{
    EditorScene::EditorScene()
    {

    }

    void EditorScene::init()
    {
        using namespace Planar::Engine::UI;

        content_window.set_folder_texture(folder_texture);
        content_window.set_file_texture(file_texture);

        game_window.set_name("Game");
        scene_window.set_name("Scene");

        restore_default_layout();

        folder_texture.load("folder.png");
        file_texture.load("file.png");
    }

    void EditorScene::update()
    {
        if (settings_window.get_pending_restore_default_layout())
        {
            restore_default_layout();
        }
    }

    void EditorScene::render()
    {
        using namespace Planar::Engine::UI;

        ImGui::dock_space_over_viewport();

        render_main_menu_bar();

        hierarchy_window.render_window();
        inspector_window.render_window();
        settings_window.render_window();
        content_window.render_window();
        console_window.render_window();

        render_game_window();
        render_scene_window();
    }

    void EditorScene::restore_default_layout() const
    {
        Planar::Engine::UI::ImGui::load_ini_from_string(
            Planar::Asset::Editor::DefaultLayout);
    }

    void EditorScene::render_game_window()
    {
        auto game_window_scope = game_window.render();

        if (!game_window_scope)
        {
            return;
        }
    }

    void EditorScene::render_scene_window()
    {
        auto scene_window_scope = scene_window.render();

        if (!scene_window_scope)
        {
            return;
        }
    }

    void EditorScene::render_main_menu_bar()
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

            auto make_active_on_menu_item = [&](const std::string& name,
                ImGui::ImGuiWindow& window)
                {
                    if (main_menu_bar.add_menu_item(name))
                    {
                        window.set_active(true);
                    }
                };

            main_menu_bar.add_menu("Window",
                [&]()
                {
                    make_active_on_menu_item("hierarchy",
                        hierarchy_window);

                    main_menu_bar.add_menu_separator();

                    make_active_on_menu_item("Scene",
                        scene_window);
                    make_active_on_menu_item("Game",
                        game_window);

                    main_menu_bar.add_menu_separator();

                    make_active_on_menu_item("Inspector",
                        inspector_window);
                    make_active_on_menu_item("Settings",
                        settings_window);

                    main_menu_bar.add_menu_separator();

                    make_active_on_menu_item("Content",
                        content_window);
                    make_active_on_menu_item("Console",
                        console_window);
                });

            main_menu_bar.add_menu("Help",
                [&]()
                {
                    if (main_menu_bar.add_menu_item("Website"))
                    {
                        Planar::Engine::Core::Shell::open_planar_website();
                    }
                });
        }
    }
}

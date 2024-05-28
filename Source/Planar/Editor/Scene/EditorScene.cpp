#include "Planar/Editor/Scene/EditorScene.hpp"
#include "Planar/Editor/Asset/LoadAssetMacros.hpp"
#include "Planar/Engine/UI/ImGui/ImGui.hpp"
#include "Planar/Engine/UI/ImGui/Window/Window.hpp"
#include "Planar/Engine/UI/ImGui/Menu/MainMenuBar.hpp"
#include "Planar/Engine/Asset/LoadAssetMacros.hpp"
#include "Planar/Engine/Core/Shell/Shell.hpp"

#include <filesystem>

PLANAR_LOAD_STD_STRING_ASSET(Editor, DefaultLayout)
PLANAR_LOAD_EDITOR_ICON(FileIcon)
PLANAR_LOAD_EDITOR_ICON(FolderIcon)
PLANAR_LOAD_EDITOR_ICON(LeftArrowIcon)

namespace Planar::Editor::Scene
{
    EditorScene::EditorScene() : project{}
    {

    }

    void EditorScene::init()
    {
        load_icons();

        if (project)
        {
            std::filesystem::path project_root_path =
                project->get_root_path();
            content_window.set_root_path(project_root_path);
            build_window.set_root_path(project_root_path);
        }

        content_window.set_file_texture(file_texture);
        content_window.set_folder_texture(folder_texture);
        content_window.set_left_arrow_texture(left_arrow_texture);
        content_window.init();

        game_window.init();

        build_window.init();

        restore_default_layout();
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
        game_window.render_window();
        scene_window.render_window();
        build_window.render_window();
    }

    void EditorScene::set_project(Planar::Editor::Project::Project* new_project)
    {
        project = new_project;
    }

    void EditorScene::restore_default_layout() const
    {
        Planar::Engine::UI::ImGui::load_ini_from_string(
            Planar::Asset::Editor::DefaultLayout);
    }

    void EditorScene::load_icons()
    {
        PLANAR_LOAD_EDITOR_ICON_TEXTURE(file_texture, FileIcon)
        PLANAR_LOAD_EDITOR_ICON_TEXTURE(folder_texture, FolderIcon)
        PLANAR_LOAD_EDITOR_ICON_TEXTURE(left_arrow_texture,
            LeftArrowIcon)
    }

    void EditorScene::render_main_menu_bar()
    {
        using namespace Planar::Engine::UI;

        ImGui::Menu::MainMenuBar main_menu_bar;
        if (main_menu_bar.start())
        {
            auto make_active_on_menu_item = [&](const std::string& name,
                ImGui::Window::Window& window,
                bool reset_first_render = false)
                {
                    if (main_menu_bar.add_menu_item(name))
                    {
                        window.set_active(true);

                        if (reset_first_render)
                        {
                            window.reset_first_render();
                        }
                    }
                };

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
                    make_active_on_menu_item("Build Project",
                        build_window, true);
                });

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

#include "Planar/Editor/Scene/EditorScene.hpp"
#include "Planar/Editor/Core/Editor.hpp"
#include "Planar/Editor/Asset/LoadAssetMacros.hpp"
#include "Planar/Editor/UI/Window/HierarchyWindow.hpp"
#include "Planar/Editor/UI/Window/InspectorWindow.hpp"
#include "Planar/Editor/UI/Window/SettingsWindow.hpp"
#include "Planar/Editor/UI/Window/ContentWindow.hpp"
#include "Planar/Editor/UI/Window/ConsoleWindow.hpp"
#include "Planar/Editor/UI/Window/GameWindow.hpp"
#include "Planar/Editor/UI/Window/SceneWindow.hpp"
#include "Planar/Editor/UI/Window/BuildWindow.hpp"
#include "Planar/Editor/UI/Window/AssetImportWindow.hpp"
#include "Planar/Engine/UI/ImGui/ImGui.hpp"
#include "Planar/Engine/UI/ImGui/Window/Window.hpp"
#include "Planar/Engine/UI/ImGui/Menu/Menu.hpp"
#include "Planar/Engine/UI/ImGui/Menu/MainMenuBar.hpp"
#include "Planar/Engine/UI/ImGui/Core/Docking/Docking.hpp"
#include "Planar/Engine/Asset/LoadAssetMacros.hpp"
#include "Planar/Engine/Core/Shell/Shell.hpp"
#include "Planar/Engine/Component/Transform2D.hpp"
#include "Planar/Engine/Component/Camera2D.hpp"
#include "Planar/Engine/Component/CameraController2D.hpp"
#include "Planar/Engine/Component/SpriteRenderer.hpp"

#include <string>
#include <memory>

PLANAR_LOAD_STD_STRING_ASSET(Editor::Layout, DefaultLayout)
PLANAR_LOAD_EDITOR_ICON(FileIcon)
PLANAR_LOAD_EDITOR_ICON(FolderIcon)
PLANAR_LOAD_EDITOR_ICON(LeftArrowIcon)

#define PLANAR_CREATE_WINDOW(type)                         \
    window_manager.create<UI::Window::type##Window>(#type) \

#define PLANAR_GET_WINDOW(type)                         \
    window_manager.get<UI::Window::type##Window>(#type) \

namespace Planar::Editor::Scene
{
    EditorScene::EditorScene(Core::Editor* editor) :
        Scene(editor), window_manager(editor)
    {
        PLANAR_CREATE_WINDOW(Hierarchy);
        PLANAR_CREATE_WINDOW(Inspector);
        PLANAR_CREATE_WINDOW(Settings);
        PLANAR_CREATE_WINDOW(Content);
        PLANAR_CREATE_WINDOW(Console);
        PLANAR_CREATE_WINDOW(Game);
        PLANAR_CREATE_WINDOW(Scene);
        PLANAR_CREATE_WINDOW(Build);
        PLANAR_CREATE_WINDOW(AssetImport);
    }

    void EditorScene::init()
    {
        load_icons();

        std::shared_ptr<UI::Window::ContentWindow>
            content_window = PLANAR_GET_WINDOW(Content);

        content_window->set_file_texture(file_texture);
        content_window->set_folder_texture(folder_texture);
        content_window->set_left_arrow_texture(left_arrow_texture);

        window_manager.init();

        restore_default_layout();
    }

    void EditorScene::update()
    {
        if (PLANAR_GET_WINDOW(Settings)->
            get_pending_restore_default_layout())
        {
            restore_default_layout();
        }

        if (play_stop_toggle.get_modified())
        {
            editor->set_editor_game_mode(play_stop_toggle.get() ==
                UI::Element::PlayStopToggle::State::PLAY ?
                Core::EditorGameMode::PLAYING :
                Core::EditorGameMode::STOPPED);
        }

        window_manager.update();
    }

    void EditorScene::render()
    {
        using namespace Engine::UI;

        ImGui::Core::Docking::dock_space_over_viewport();

        render_main_menu_bar();

        window_manager.render();
    }

    void EditorScene::restore_default_layout() const
    {
        Engine::UI::ImGui::load_ini_from_string(
            Planar::Asset::Editor::Layout::DefaultLayout);
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
        using namespace Engine::UI;

        ImGui::Menu::MainMenuBar main_menu_bar;
        if (main_menu_bar.start())
        {
            auto make_active_on_menu_item = [](const std::string& name,
                std::shared_ptr<UI::Window::Core::EditorWindow> window,
                bool reset_first_render = false)
                {
                    if (ImGui::Menu::menu_item(name))
                    {
                        window->set_active(true);

                        if (reset_first_render)
                        {
                            window->reset_first_render();
                        }
                    }
                };

            main_menu_bar.add_menu("File",
                [&]()
                {
                    ImGui::Menu::menu_item("New Project");
                    ImGui::Menu::menu_item("Open Project");
                    
                    ImGui::separator();

                    if (ImGui::Menu::menu_item("Save", "Ctrl + S"))
                    {
                        editor->save_all();
                    }
                    ImGui::Menu::menu_item("Save As",
                        "Ctrl + Shift + S");

                    ImGui::separator();

                    ImGui::Menu::menu_item("Exit");
                });

            main_menu_bar.add_menu("Build",
                [&]()
                {
                    make_active_on_menu_item("Build Project",
                        PLANAR_GET_WINDOW(Build), true);
                });

            main_menu_bar.add_menu("Component",
                [&]()
                {
                    using namespace Engine::Component;

                    add_component_menu_item<Transform2D>();
                    add_component_menu_item<Camera2D>();
                    add_component_menu_item<CameraController2D>();
                    add_component_menu_item<SpriteRenderer>();
                });

            main_menu_bar.add_menu("Asset",
                [&]()
                {
                    make_active_on_menu_item("Asset Import",
                        PLANAR_GET_WINDOW(AssetImport), true);
                });

            main_menu_bar.add_menu("Window",
                [&]()
                {
                    make_active_on_menu_item("Hierarchy",
                        PLANAR_GET_WINDOW(Hierarchy));

                    ImGui::separator();

                    make_active_on_menu_item("Scene",
                        PLANAR_GET_WINDOW(Scene));
                    make_active_on_menu_item("Game",
                        PLANAR_GET_WINDOW(Game));

                    ImGui::separator();

                    make_active_on_menu_item("Inspector",
                        PLANAR_GET_WINDOW(Inspector));
                    make_active_on_menu_item("Settings",
                        PLANAR_GET_WINDOW(Settings));

                    ImGui::separator();

                    make_active_on_menu_item("Content",
                        PLANAR_GET_WINDOW(Content));
                    make_active_on_menu_item("Console",
                        PLANAR_GET_WINDOW(Console));
                });

            main_menu_bar.add_menu("Help",
                []()
                {
                    if (ImGui::Menu::menu_item("Website"))
                    {
                        Engine::Core::Shell::open_planar_website();
                    }
                });

            play_stop_toggle.render();
        }
    }

    template <typename ComponentT>
    void EditorScene::add_component_menu_item()
    {
        const std::string label_prefix = "Add ";

        if (Engine::UI::ImGui::Menu::menu_item(label_prefix +
            ComponentT::NAME))
        {
            PLANAR_GET_WINDOW(Inspector)->add_component<ComponentT>();
        }
    }
}

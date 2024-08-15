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
#include "Planar/Editor/UI/Window/CreateScriptWindow.hpp"
#include "Planar/Engine/UI/ImGui/Core/Docking/Docking.hpp"
#include "Planar/Engine/Asset/LoadAssetMacros.hpp"

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
        Scene(editor, "EditorScene"), window_manager(editor),
        menu_bar(editor, window_manager)
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
        PLANAR_CREATE_WINDOW(CreateScript);
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

        window_manager.get("Console")->set_active(false);
        window_manager.get("Scene")->set_active(false);

        restore_default_layout();
    }

    void EditorScene::update()
    {
        if (PLANAR_GET_WINDOW(Settings)->
            get_pending_restore_default_layout())
        {
            restore_default_layout();
        }

        UI::Element::PlayStopToggle& play_stop_toggle =
            menu_bar.get_play_stop_toggle();
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

        menu_bar.render();

        window_manager.render();
    }

    void EditorScene::open_build_window() const
    {
        std::shared_ptr<UI::Window::Core::EditorWindow>
            build_window = window_manager.get("Build");

        build_window->set_active(true);
        build_window->reset_first_render();
    }

    void EditorScene::restore_default_layout() const
    {
        Engine::UI::ImGui::load_ini_from_string(
            Asset::Editor::Layout::DefaultLayout);
    }

    void EditorScene::load_icons()
    {
        PLANAR_LOAD_EDITOR_ICON_TEXTURE(file_texture, FileIcon)
        PLANAR_LOAD_EDITOR_ICON_TEXTURE(folder_texture, FolderIcon)
        PLANAR_LOAD_EDITOR_ICON_TEXTURE(left_arrow_texture,
            LeftArrowIcon)
    }
}

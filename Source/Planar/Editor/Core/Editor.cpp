#include "Planar/Editor/Core/Editor.hpp"
#include "Planar/Editor/Core/Select/SelectType.hpp"
#include "Planar/Editor/Scene/SelectProjectScene.hpp"
#include "Planar/Editor/Scene/EditorScene.hpp"
#include "Planar/Editor/UI/Init/Init.hpp"
#include "Planar/Engine/Core/Utils/Macros/FunctionalMacros.hpp"

namespace Planar::Editor::Core
{
    Editor::Editor() :
        Application("Planar Editor", { 1280, 720 }, true),
        editor_game_mode{ EditorGameMode::STOPPED }
    {

    }

    bool Editor::init()
    {
        if (!Base::init())
        {
            return false;
        }

        UI::Init::init();

        std::unique_ptr<Scene::SelectProjectScene> scene =
            std::make_unique<Scene::SelectProjectScene>(this);

        load_scene(std::move(scene));

        return true;
    }

    void Editor::enter_editor()
    {
        std::unique_ptr<Scene::EditorScene> scene =
            std::make_unique<Scene::EditorScene>(this);

        load_scene(std::move(scene));

        update_window_name(project.get_project_name());
    }

    void Editor::change_scene(
        std::unique_ptr<Engine::Scene::Scene> new_scene)
    {
        current_scene = std::move(new_scene);
    }

    void Editor::update_window_name(const std::string& scene_name,
        bool show_asterisk)
    {
        std::string name;

        if (!scene_name.empty())
        {
            name += " - " + scene_name;
        }

        if (show_asterisk)
        {
            name += "*";
        }

        set_window_name("Planar Editor" + name);
    }

    void Editor::set_window_asterisk(bool show)
    {
        update_window_name(project.get_project_name(), show);
    }

    Project::Project& Editor::get_project()
    {
        return project;
    }

    std::unique_ptr<Engine::Scene::Scene>& Editor::get_current_scene()
    {
        return current_scene;
    }

    void Editor::new_current_scene(const std::string& scene_asset,
        const std::string& scene_name,
        const std::filesystem::path& asset_path)
    {
        current_scene = std::make_unique<Engine::Scene::Scene>(
            this, scene_asset, scene_name, asset_path);

        save_handler.add_save_callback("current_scene",
            PLANAR_CAPTURE_REF(current_scene->save));
    }

    void Editor::close_current_scene()
    {
        save_handler.remove_save_callback("current_scene");
        current_scene.reset();

        select_handler.select_none(Select::SelectType::GAME_OBJECT);
    }

    void Editor::add_save_callback(const std::string& name,
        const std::function<void()>& save_callback)
    {
        save_handler.add_save_callback(name, save_callback);
    }

    void Editor::set_dirty(bool skip_if_editor_game_playing)
    {
        if (skip_if_editor_game_playing &&
            editor_game_mode == EditorGameMode::PLAYING)
        {
            return;
        }

        save_handler.set_dirty();

        set_window_asterisk(save_handler.get_dirty());
    }

    void Editor::save_all(bool skip_if_editor_game_playing)
    {
        if (skip_if_editor_game_playing &&
            editor_game_mode == EditorGameMode::PLAYING)
        {
            return;
        }

        save_handler.save_all();

        set_window_asterisk(save_handler.get_dirty());
    }

    Select::SelectHandler& Editor::get_select_handler()
    {
        return select_handler;
    }

    EditorGameMode Editor::get_editor_game_mode() const
    {
        return editor_game_mode;
    }

    void Editor::set_editor_game_mode(
        EditorGameMode new_editor_game_mode)
    {
        editor_game_mode = new_editor_game_mode;
    }
}

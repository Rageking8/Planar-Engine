#include "Planar/Editor/Core/Editor.hpp"
#include "Planar/Editor/Scene/SelectProjectScene.hpp"
#include "Planar/Editor/Scene/EditorScene.hpp"
#include "Planar/Editor/UI/Init/Init.hpp"

namespace Planar::Editor::Core
{
    Editor::Editor() :
        Application("Planar Editor", { 1280, 720 }, true)
    {

    }

    bool Editor::init()
    {
        if (!Base::init())
        {
            return false;
        }

        UI::Init::load_default_font();
        UI::Init::set_scale();

        std::unique_ptr<Scene::SelectProjectScene> scene =
            std::make_unique<Scene::SelectProjectScene>();
        scene->set_editor(this);

        load_scene(std::move(scene));

        return true;
    }

    void Editor::enter_editor()
    {
        std::unique_ptr<Scene::EditorScene> scene =
            std::make_unique<Scene::EditorScene>();
        scene->set_editor(this);

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

    void Editor::add_save_callback(const std::string& name,
        const std::function<void()>& save_callback)
    {
        save_handler.add_save_callback(name, save_callback);
    }

    void Editor::set_dirty()
    {
        save_handler.set_dirty();

        set_window_asterisk(save_handler.get_dirty());
    }

    void Editor::save_all()
    {
        save_handler.save_all();

        set_window_asterisk(save_handler.get_dirty());
    }

    Select::SelectHandler& Editor::get_select_handler()
    {
        return select_handler;
    }
}

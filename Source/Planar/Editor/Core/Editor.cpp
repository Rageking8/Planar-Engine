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

        set_window_name("Planar Editor - " + project.get_project_name());
    }

    void Editor::change_scene(
        std::unique_ptr<Engine::Scene::Scene> new_scene)
    {
        current_scene = std::move(new_scene);
    }

    Project::Project& Editor::get_project()
    {
        return project;
    }

    std::unique_ptr<Engine::Scene::Scene>& Editor::get_current_scene()
    {
        return current_scene;
    }
}

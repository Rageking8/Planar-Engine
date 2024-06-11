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
        scene->set_project(&project);

        load_scene(std::move(scene));

        return true;
    }

    void Editor::enter_editor()
    {
        std::unique_ptr<Scene::EditorScene> scene =
            std::make_unique<Scene::EditorScene>();
        scene->set_project(&project);
        load_scene(std::move(scene));

        set_window_name("Planar Editor - " + project.get_project_name());
    }
}

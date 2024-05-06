#include "Planar/Editor/Core/Editor.hpp"
#include "Planar/Editor/Scene/SelectProjectScene.hpp"
#include "Planar/Editor/Scene/EditorScene.hpp"

#include <memory>
#include <functional>

namespace Planar::Editor::Core
{
    Editor::Editor() :
        Application("Planar Editor", { 1280, 720 }, true)
    {

    }

    bool Editor::init()
    {
        if (!Application::init())
        {
            return false;
        }

        std::unique_ptr<Planar::Editor::Scene::SelectProjectScene> scene =
            std::make_unique<Planar::Editor::Scene::SelectProjectScene>();
        scene->set_editor_enter_callback(
            std::bind(&Editor::enter_editor, this));

        load_scene(std::move(scene));

        return true;
    }

    void Editor::enter_editor()
    {
        load_scene(std::make_unique<Planar::Editor::Scene::EditorScene>());
    }
}

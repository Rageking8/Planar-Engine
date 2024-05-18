#include "Planar/Editor/Core/Editor.hpp"
#include "Planar/Editor/Scene/SelectProjectScene.hpp"
#include "Planar/Editor/Scene/EditorScene.hpp"
#include "Planar/Editor/Script/Init/Init.hpp"

#include <memory>
#include <filesystem>
#include <functional>

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

        std::unique_ptr<Planar::Editor::Scene::SelectProjectScene> scene =
            std::make_unique<Planar::Editor::Scene::SelectProjectScene>();
        scene->set_editor_enter_callback(
            std::bind(&Editor::enter_editor, this));
        scene->set_project(&project);

        load_scene(std::move(scene));

        return true;
    }

    void Editor::enter_editor()
    {
        load_scene(std::make_unique<Planar::Editor::Scene::EditorScene>());
        set_window_name("Planar Editor - " + project.get_project_name());

        load_scripting();
    }

    void Editor::load_scripting()
    {
        if (!std::filesystem::exists("Cache/dotnet_sdk.zip"))
        {
            Planar::Editor::Script::Init::write_dotnet_sdk_zip(
                "Cache/dotnet_sdk.zip");
        }
    }
}

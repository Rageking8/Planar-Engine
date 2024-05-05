#include "Planar/Editor/Core/Editor.hpp"
#include "Planar/Editor/Scene/SelectProjectScene.hpp"

#include <memory>

namespace Planar::Editor::Core
{
    Editor::Editor() : Application("Planar Editor")
    {

    }

    bool Editor::init()
    {
        if (!Application::init())
        {
            return false;
        }

        load_scene(
            std::make_unique<Planar::Editor::Scene::SelectProjectScene>());

        return true;
    }
}

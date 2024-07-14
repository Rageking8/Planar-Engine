#include "Planar/Editor/Scene/Scene.hpp"
#include "Planar/Editor/Core/Editor.hpp"

namespace Planar::Editor::Scene
{
    Scene::Scene(Core::Editor* editor, const std::string& name) :
        Engine::Scene::Scene(editor), editor{ editor }, name{ name }
    {

    }

    Scene::~Scene()
    {

    }

    std::string Scene::get_name() const
    {
        return name;
    }
}

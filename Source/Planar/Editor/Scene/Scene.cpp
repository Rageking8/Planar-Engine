#include "Planar/Editor/Scene/Scene.hpp"

namespace Planar::Editor::Scene
{
    Scene::Scene() : editor{}
    {

    }

    Scene::~Scene()
    {

    }

    void Scene::set_editor(Core::Editor* new_editor)
    {
        editor = new_editor;
    }
}

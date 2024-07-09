#include "Planar/Editor/Scene/Scene.hpp"
#include "Planar/Editor/Core/Editor.hpp"

namespace Planar::Editor::Scene
{
    Scene::Scene(Core::Editor* editor) :
        Engine::Scene::Scene(editor), editor{ editor }
    {

    }

    Scene::~Scene()
    {

    }
}

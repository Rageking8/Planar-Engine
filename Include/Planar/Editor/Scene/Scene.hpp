#pragma once

#include "Planar/Engine/Scene/Scene.hpp"
#include "Planar/Editor/Core/Editor.hpp"

namespace Planar::Editor::Scene
{
    class Scene : public Engine::Scene::Scene
    {
    public:
        Scene(Core::Editor* editor);
        virtual ~Scene() = 0;

    protected:
        Core::Editor* editor;
    };
}

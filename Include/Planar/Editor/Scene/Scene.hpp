#pragma once

#include "Planar/Engine/Scene/Scene.hpp"
#include "Planar/Editor/Core/Editor.hpp"

namespace Planar::Editor::Scene
{
    class Scene : public Engine::Scene::Scene
    {
    public:
        Scene();
        virtual ~Scene() = 0;

        void set_editor(Core::Editor* new_editor);

    protected:
        Core::Editor* editor;
    };
}

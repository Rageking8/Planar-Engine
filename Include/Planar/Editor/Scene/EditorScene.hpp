#pragma once

#include "Planar/Engine/Scene/Scene.hpp"

namespace Planar::Editor::Scene
{
    class EditorScene :
        public Planar::Engine::Scene::Scene
    {
    public:
        EditorScene();

        virtual void render() override;
    };
}

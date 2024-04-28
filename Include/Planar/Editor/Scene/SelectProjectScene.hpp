#pragma once

#include "Planar/Engine/Scene/Scene.hpp"

namespace Planar::Editor::Scene
{
    class SelectProjectScene :
        public Planar::Engine::Scene::Scene
    {
    public:
        virtual void render() override;
    };
}

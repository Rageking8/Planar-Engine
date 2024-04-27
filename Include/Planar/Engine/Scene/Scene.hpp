#pragma once

#include "Planar/Engine/Core/ExportMacros.hpp"

namespace Planar::Engine::Scene
{
    class PLANAR_API Scene
    {
    public:
        Scene();
        virtual ~Scene() = 0;

        virtual void init();
        virtual void start();

        virtual void update();
        virtual void render();
    };
}

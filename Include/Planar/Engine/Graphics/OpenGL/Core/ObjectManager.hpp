#pragma once

#include "Planar/Engine/Export/ExportMacros.hpp"
#include "Planar/Engine/Graphics/OpenGL/Render/Quad.hpp"

namespace Planar::Engine::Graphics::OpenGL::Core
{
    class PLANAR_API ObjectManager
    {
    public:
        ObjectManager();

        void init();

        Render::Quad& get_quad();

    private:
        Render::Quad quad;
    };
}

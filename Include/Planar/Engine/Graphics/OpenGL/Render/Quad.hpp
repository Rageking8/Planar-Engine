#pragma once

#include "Planar/Engine/Export/ExportMacros.hpp"
#include "Planar/Engine/Graphics/OpenGL/Buffer/Buffer.hpp"
#include "Planar/Engine/Graphics/OpenGL/Core/VertexArrayObject.hpp"

namespace Planar::Engine::Graphics::OpenGL::Render
{
    class PLANAR_API Quad
    {
    public:
        Quad();

        void init();
        void bind() const;

    private:
        Core::VertexArrayObject vertex_array_object;
        Buffer::Pos2DTexArrayBuffer buffer;
    };
}

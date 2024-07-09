#include "Planar/Engine/Graphics/OpenGL/Render/Quad.hpp"
#include "Planar/Engine/Graphics/OpenGL/Buffer/BufferUsage.hpp"

namespace Planar::Engine::Graphics::OpenGL::Render
{
    Quad::Quad()
    {

    }

    void Quad::init()
    {
        buffer.create({
            { 0.5f, 0.5f, 1.f, 1.f },
            { -0.5f, 0.5f, 0.f, 1.f },
            { 0.5f, -0.5f, 1.f, 0.f },
            { -0.5f, -0.5f, 0.f, 0.f } },
            Buffer::BufferUsage::STATIC_DRAW);
        vertex_array_object.create(buffer);
    }

    void Quad::bind() const
    {
        vertex_array_object.bind();
    }
}

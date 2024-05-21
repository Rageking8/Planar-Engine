#include "Planar/Engine/Graphics/OpenGL/Core/VertexArrayObject.hpp"

namespace Planar::Engine::Graphics::OpenGL::Core
{
    VertexArrayObject::VertexArrayObject() : id{}
    {

    }

    VertexArrayObject::~VertexArrayObject()
    {
        free();
    }

    void VertexArrayObject::free()
    {
        glDeleteVertexArrays(1, &id);
        id = 0;
    }

    void VertexArrayObject::bind() const
    {
        glBindVertexArray(id);
    }
}

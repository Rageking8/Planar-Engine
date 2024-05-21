#include "Planar/Engine/Graphics/OpenGL/Core/VertexArrayObject.hpp"

namespace Planar::Engine::Graphics::OpenGL::Core
{
    VertexArrayObject::VertexArrayObject() : Resource(free_impl)
    {

    }

    VertexArrayObject::~VertexArrayObject()
    {

    }

    void VertexArrayObject::bind() const
    {
        glBindVertexArray(id);
    }

    void VertexArrayObject::free_impl(GLuint id)
    {
        glDeleteVertexArrays(1, &id);
    }
}

#include "Planar/Engine/Graphics/OpenGL/Core/VertexArrayObject.hpp"
#include "Planar/Engine/Graphics/OpenGL/Core/Vertex/Pos2DTex.hpp"
#include "Planar/Engine/Graphics/OpenGL/Vector3.hpp"

#include <cstddef>

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

    void VertexArrayObject::create_vertex_array(
        ObjectHandlingMode object_handling_mode)
    {
        switch (object_handling_mode)
        {
        case ObjectHandlingMode::BIND:
            glGenVertexArrays(1, &id);
            break;

        case ObjectHandlingMode::DSA:
            glCreateVertexArrays(1, &id);
            break;
        }
    }

    void VertexArrayObject::vertex_attrib_vector3() const
    {
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE,
            sizeof(Vector3), nullptr);
        glEnableVertexAttribArray(0);
    }

    void VertexArrayObject::vertex_attrib_pos_2d_tex() const
    {
        glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE,
            sizeof(Vertex::Pos2DTex), nullptr);
        glEnableVertexAttribArray(0);
        glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE,
            sizeof(Vertex::Pos2DTex),
            (void*)offsetof(Vertex::Pos2DTex, u));
        glEnableVertexAttribArray(1);
    }

    void VertexArrayObject::free_impl(GLuint id)
    {
        glDeleteVertexArrays(1, &id);
    }
}

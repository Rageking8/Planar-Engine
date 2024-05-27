#include "Planar/Engine/Graphics/OpenGL/Function/Buffer/BufferFunction.hpp"

namespace Planar::Engine::Graphics::OpenGL::Function::Buffer
{
    GLuint gen_buffer()
    {
        GLuint id = 0;
        glGenBuffers(1, &id);

        return id;
    }

    void bind_buffer(OpenGL::Buffer::BufferType buffer_type, GLuint id)
    {
        glBindBuffer((GLenum)buffer_type, id);
    }

    void buffer_data(OpenGL::Buffer::BufferType buffer_type,
        GLsizeiptr size, const void* data,
        OpenGL::Buffer::BufferUsage buffer_usage)
    {
        glBufferData((GLenum)buffer_type, size, data,
            (GLenum)buffer_usage);
    }

    void delete_buffer(GLuint id)
    {
        glDeleteBuffers(1, &id);
    }
}

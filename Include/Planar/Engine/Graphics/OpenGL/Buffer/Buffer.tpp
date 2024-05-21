#include "Planar/Engine/Graphics/OpenGL/Buffer/Buffer.hpp"

namespace Planar::Engine::Graphics::OpenGL::Buffer
{
    template <typename T, BufferType BufferT>
    inline Buffer<T, BufferT>::Buffer() : Resource(free_impl)
    {

    }

    template <typename T, BufferType BufferT>
    inline Buffer<T, BufferT>::~Buffer()
    {

    }

    template <typename T, BufferType BufferT>
    inline void Buffer<T, BufferT>::create(
        const std::vector<T>& buffer, BufferUsage usage)
    {
        free();

        glGenBuffers(1, &id);
        bind();
        glBufferData((GLenum)BufferT, (buffer.size() * sizeof(T)),
            buffer.data(), (GLenum)usage);
    }

    template <typename T, BufferType BufferT>
    inline void Buffer<T, BufferT>::bind() const
    {
        glBindBuffer((GLenum)BufferT, id);
    }

    template <typename T, BufferType BufferT>
    inline void Buffer<T, BufferT>::free_impl(GLuint id)
    {
        glDeleteBuffers(1, &id);
    }
}

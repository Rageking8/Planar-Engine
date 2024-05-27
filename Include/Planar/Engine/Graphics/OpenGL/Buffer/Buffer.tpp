#include "Planar/Engine/Graphics/OpenGL/Buffer/Buffer.hpp"
#include "Planar/Engine/Graphics/OpenGL/Function/Buffer/Buffer.hpp"

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

        id = Function::Buffer::gen_buffer();
        bind();
        Function::Buffer::buffer_data(BufferT,
            (buffer.size() * sizeof(T)), buffer.data(), usage);
    }

    template <typename T, BufferType BufferT>
    inline void Buffer<T, BufferT>::bind() const
    {
        Function::Buffer::bind_buffer(BufferT, id);
    }

    template <typename T, BufferType BufferT>
    inline void Buffer<T, BufferT>::free_impl(GLuint id)
    {
        Function::Buffer::delete_buffer(id);
    }
}

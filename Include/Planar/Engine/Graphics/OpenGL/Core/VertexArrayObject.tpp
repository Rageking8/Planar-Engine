#include "Planar/Engine/Graphics/OpenGL/Core/VertexArrayObject.hpp"
#include "Planar/Engine/Graphics/OpenGL/Vector3.hpp"

#include <type_traits>

namespace Planar::Engine::Graphics::OpenGL::Core
{
    template <typename T, Buffer::BufferType bufferT>
    inline void VertexArrayObject::create(
        const Buffer::Buffer<T, bufferT>& vertex_buffer)
    {
        free();

        glCreateVertexArrays(1, &id);
        glBindVertexArray(id);

        vertex_buffer.bind();

        if constexpr (std::is_same_v<T, Vector3>)
        {
            glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE,
                sizeof(Vector3), nullptr);
            glEnableVertexAttribArray(0);
        }
    }
}

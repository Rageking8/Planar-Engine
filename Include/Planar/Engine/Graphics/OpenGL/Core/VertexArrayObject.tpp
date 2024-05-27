#include "Planar/Engine/Graphics/OpenGL/Core/VertexArrayObject.hpp"
#include "Planar/Engine/Graphics/OpenGL/Vector3.hpp"

#include <type_traits>

namespace Planar::Engine::Graphics::OpenGL::Core
{
    template <typename T, Buffer::BufferType bufferT>
    inline void VertexArrayObject::create(
        const Buffer::Buffer<T, bufferT>& vertex_buffer,
        ObjectHandlingMode object_handling_mode)
    {
        free();

        create_vertex_array(object_handling_mode);

        bind();
        vertex_buffer.bind();

        if constexpr (std::is_same_v<T, Vector3>)
        {
            vertex_attrib_vector3();
        }
    }
}

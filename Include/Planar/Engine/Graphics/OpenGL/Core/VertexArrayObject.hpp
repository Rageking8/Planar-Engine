#pragma once

#include "Planar/Engine/Export/ExportMacros.hpp"
#include "Planar/Engine/Graphics/OpenGL/Core/Resource.hpp"
#include "Planar/Engine/Graphics/OpenGL/Buffer/Buffer.hpp"
#include "Planar/Engine/Graphics/OpenGL/Buffer/BufferType.hpp"
#include "Planar/Engine/Graphics/OpenGL/Core/ObjectHandlingMode.hpp"

#include "ThirdParty/glad/gl.h"

namespace Planar::Engine::Graphics::OpenGL::Core
{
    class PLANAR_API VertexArrayObject : public Resource
    {
    public:
        VertexArrayObject();
        ~VertexArrayObject();

        template <typename T, Buffer::BufferType bufferT>
        void create(const Buffer::Buffer<T, bufferT>& vertex_buffer,
            ObjectHandlingMode object_handling_mode =
            ObjectHandlingMode::DSA);

        void bind() const;

    private:
        void create_vertex_array(
            ObjectHandlingMode object_handling_mode);

        void vertex_attrib_vector3() const;

        static void free_impl(GLuint id);
    };
}

#include "Planar/Engine/Graphics/OpenGL/Core/VertexArrayObject.tpp"

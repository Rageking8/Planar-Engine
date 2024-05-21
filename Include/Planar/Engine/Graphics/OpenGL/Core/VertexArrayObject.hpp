#pragma once

#include "Planar/Engine/Core/Utils/Macros/TypeHelperMacros.hpp"
#include "Planar/Engine/Graphics/OpenGL/Buffer/Buffer.hpp"
#include "Planar/Engine/Graphics/OpenGL/Buffer/BufferType.hpp"

#include "ThirdParty/glad/gl.h"

namespace Planar::Engine::Graphics::OpenGL::Core
{
    class VertexArrayObject
    {
    public:
        VertexArrayObject();
        ~VertexArrayObject();

        PLANAR_DELETE_COPY_FUNCTIONS(VertexArrayObject)

        template <typename T, Buffer::BufferType bufferT>
        void create(const Buffer::Buffer<T, bufferT>& vertex_buffer);
        void free();

        void bind() const;

    private:
        GLuint id;
    };
}

#include "Planar/Engine/Graphics/OpenGL/Core/VertexArrayObject.tpp"

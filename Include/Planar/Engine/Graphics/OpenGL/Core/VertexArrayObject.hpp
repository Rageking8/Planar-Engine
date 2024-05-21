#pragma once

#include "Planar/Engine/Graphics/OpenGL/Core/Resource.hpp"
#include "Planar/Engine/Graphics/OpenGL/Buffer/Buffer.hpp"
#include "Planar/Engine/Graphics/OpenGL/Buffer/BufferType.hpp"

#include "ThirdParty/glad/gl.h"

namespace Planar::Engine::Graphics::OpenGL::Core
{
    class VertexArrayObject : public Resource
    {
    public:
        VertexArrayObject();
        ~VertexArrayObject();

        template <typename T, Buffer::BufferType bufferT>
        void create(const Buffer::Buffer<T, bufferT>& vertex_buffer);

        void bind() const;

    private:
        static void free_impl(GLuint id);
    };
}

#include "Planar/Engine/Graphics/OpenGL/Core/VertexArrayObject.tpp"

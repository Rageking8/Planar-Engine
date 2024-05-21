#pragma once

#include "Planar/Engine/Graphics/OpenGL/Core/Resource.hpp"
#include "Planar/Engine/Graphics/OpenGL/Buffer/BufferType.hpp"
#include "Planar/Engine/Graphics/OpenGL/Buffer/BufferUsage.hpp"
#include "Planar/Engine/Graphics/OpenGL/Vector3.hpp"

#include "ThirdParty/glad/gl.h"

#include <vector>

namespace Planar::Engine::Graphics::OpenGL::Buffer
{
    template <typename T, BufferType BufferT>
    class Buffer : public Core::Resource
    {
    public:
        Buffer();
        ~Buffer();

        void create(const std::vector<T>& buffer, BufferUsage usage);

        void bind() const;

    private:
        static void free_impl(GLuint id);
    };

    using Vector3ArrayBuffer = Buffer<Vector3, BufferType::ARRAY>;
    using ElementArrayBuffer = Buffer<GLuint, BufferType::ELEMENT_ARRAY>;
}

#include "Planar/Engine/Graphics/OpenGL/Buffer/Buffer.tpp"

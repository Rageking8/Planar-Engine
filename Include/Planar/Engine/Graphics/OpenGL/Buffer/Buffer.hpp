#pragma once

#include "Planar/Engine/Core/Utils/Macros/TypeHelperMacros.hpp"
#include "Planar/Engine/Graphics/OpenGL/Buffer/BufferType.hpp"
#include "Planar/Engine/Graphics/OpenGL/Buffer/BufferUsage.hpp"
#include "Planar/Engine/Graphics/OpenGL/Vector3.hpp"

#include "ThirdParty/glad/gl.h"

#include <vector>

namespace Planar::Engine::Graphics::OpenGL::Buffer
{
    template <typename T, BufferType BufferT>
    class Buffer
    {
    public:
        Buffer();
        ~Buffer();

        PLANAR_DELETE_COPY_FUNCTIONS(Buffer)

        void create(const std::vector<T>& buffer, BufferUsage usage);
        void free();

        void bind() const;

    private:
        GLuint id;
    };

    using Vector3ArrayBuffer = Buffer<Vector3, BufferType::ARRAY>;
    using ElementArrayBuffer = Buffer<GLuint, BufferType::ELEMENT_ARRAY>;
}

#include "Planar/Engine/Graphics/OpenGL/Buffer/Buffer.tpp"

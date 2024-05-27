#pragma once

#include "Planar/Engine/Export/ExportMacros.hpp"
#include "Planar/Engine/Graphics/OpenGL/Buffer/BufferType.hpp"
#include "Planar/Engine/Graphics/OpenGL/Buffer/BufferUsage.hpp"

#include "ThirdParty/glad/gl.h"

namespace Planar::Engine::Graphics::OpenGL::Function::Buffer
{
    PLANAR_API GLuint gen_buffer();

    PLANAR_API void bind_buffer(
        OpenGL::Buffer::BufferType buffer_type, GLuint id);

    PLANAR_API void buffer_data(
        OpenGL::Buffer::BufferType buffer_type, GLsizeiptr size,
        const void* data, OpenGL::Buffer::BufferUsage buffer_usage);

    PLANAR_API void delete_buffer(GLuint id);
}

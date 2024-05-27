#pragma once

#include "Planar/Engine/Export/ExportMacros.hpp"
#include "Planar/Engine/Graphics/OpenGL/Render/Primitive.hpp"

#include "ThirdParty/glad/gl.h"

namespace Planar::Engine::Graphics::OpenGL::Function::Render
{
    PLANAR_API void draw_arrays(OpenGL::Render::Primitive primitive,
        GLint first, GLsizei count);
}

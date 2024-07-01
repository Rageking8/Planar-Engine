#pragma once

#include "Planar/Engine/Export/ExportMacros.hpp"
#include "Planar/Engine/Graphics/Color.hpp"
#include "Planar/Engine/Graphics/OpenGL/Render/Primitive.hpp"

#include "ThirdParty/glad/gl.h"

namespace Planar::Engine::Graphics::OpenGL::Render
{
    PLANAR_API void color_clear(Color color);

    PLANAR_API void draw_arrays(Primitive primitive, GLint first,
        GLsizei count);
}

#pragma once

#include "Planar/Engine/Export/ExportMacros.hpp"

#include "ThirdParty/glad/gl.h"

namespace Planar::Engine::Graphics::OpenGL::Core
{
    class PLANAR_API ViewportScope
    {
    public:
        ViewportScope(GLint x, GLint y,
            GLsizei width, GLsizei height);
        ~ViewportScope();

    private:
        GLint previous_x;
        GLint previous_y;
        GLsizei previous_width;
        GLsizei previous_height;
    };
}

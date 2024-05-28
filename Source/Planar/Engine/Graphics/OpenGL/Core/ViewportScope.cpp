#include "Planar/Engine/Graphics/OpenGL/Core/ViewportScope.hpp"

namespace Planar::Engine::Graphics::OpenGL::Core
{
    ViewportScope::ViewportScope(GLint x, GLint y,
        GLsizei width, GLsizei height)
    {
        GLint previous_viewport[4]{};
        glGetIntegerv(GL_VIEWPORT, previous_viewport);
        previous_x = previous_viewport[0];
        previous_y = previous_viewport[1];
        previous_width = previous_viewport[2];
        previous_height = previous_viewport[3];

        glViewport(x, y, width, height);
    }

    ViewportScope::~ViewportScope()
    {
        glViewport(previous_x, previous_y,
            previous_width, previous_height);
    }
}

#include "Planar/Engine/Graphics/OpenGL/Render/Render.hpp"

namespace Planar::Engine::Graphics::OpenGL::Render
{
    void color_clear(Color color)
    {
        glClearColor(color.r, color.g, color.b, color.a);
        glClear(GL_COLOR_BUFFER_BIT);
    }

    void draw_arrays(Primitive primitive, GLint first, GLsizei count)
    {
        glDrawArrays((GLenum)primitive, first, count);
    }
}

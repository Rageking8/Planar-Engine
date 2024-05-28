#include "Planar/Engine/Graphics/OpenGL/Function/Render/RenderFunction.hpp"

namespace Planar::Engine::Graphics::OpenGL::Function::Render
{
    void color_clear(Graphics::Color color)
    {
        glClearColor(color.r, color.g, color.b, color.a);
        glClear(GL_COLOR_BUFFER_BIT);
    }

    void draw_arrays(OpenGL::Render::Primitive primitive,
        GLint first, GLsizei count)
    {
        glDrawArrays((GLenum)primitive, first, count);
    }
}

#include "Planar/Engine/Graphics/OpenGL/Function/Render/RenderFunction.hpp"

namespace Planar::Engine::Graphics::OpenGL::Function::Render
{
    void draw_arrays(OpenGL::Render::Primitive primitive,
        GLint first, GLsizei count)
    {
        glDrawArrays((GLenum)primitive, first, count);
    }
}

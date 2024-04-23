#include "Planar/Engine/Core/GLFWContext.hpp"

#include "ThirdParty/GLFW/glfw3.h"

namespace Planar::Engine::Core
{
    GLFWContext::GLFWContext() : has_init{}
    {

    }

    GLFWContext::~GLFWContext()
    {
        terminate();
    }

    bool GLFWContext::init()
    {
        has_init = glfwInit();

        return has_init;
    }

    void GLFWContext::terminate()
    {
        if (!has_init)
        {
            return;
        }

        glfwTerminate();
        has_init = false;
    }
}

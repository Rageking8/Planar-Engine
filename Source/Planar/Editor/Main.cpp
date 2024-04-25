#include "Planar/Engine/Core/GLFWContext.hpp"

#include <iostream>

int main()
{
    Planar::Engine::Core::GLFWContext glfw_context;
    if (!glfw_context.init())
    {
        std::cerr << "GLFW init failed\n";

        return -1;
    }

    glfw_context.run();
}

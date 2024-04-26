#include "Planar/Engine/Core/GLFWContext.hpp"

#include "ThirdParty/GLFW/glfw3.h"

#include <iostream>

namespace Planar::Engine::Core
{
    GLFWContext::GLFWContext() : has_init{}, main_window{}
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

        glfwDestroyWindow(main_window);
        glfwTerminate();

        has_init = false;
    }

    GLFWwindow* GLFWContext::get_main_window() const
    {
        return main_window;
    }

    bool GLFWContext::create_window(
        Planar::Engine::Graphics::SupportedGraphicsAPI graphics_api,
        Planar::Engine::Math::Size2Di size,
        const std::string& name)
    {
        if (!has_init || main_window)
        {
            return false;
        }

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, graphics_api.
            get_major_version());
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, graphics_api.
            get_minor_version());
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        GLFWwindow* window = glfwCreateWindow(size.width, size.height,
            name.c_str(), nullptr, nullptr);

        if (window)
        {
            main_window = window;
            window_graphics_api = graphics_api;

            glfwMakeContextCurrent(window);
        }

        return window;
    }
}

#include "Planar/Engine/Core/GLFW/GLFWContext.hpp"
#include "Planar/Engine/Core/Log/TerminalLogger.hpp"

#include "ThirdParty/GLFW/glfw3.h"

namespace Planar::Engine::Core::GLFW
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
        has_init = (glfwInit() == GLFW_TRUE);

        if (has_init)
        {
            Log::TerminalLogger::get("Engine")->success(
                "GLFW init successful");
        }
        else
        {
            Log::TerminalLogger::get("Engine")->error(
                "GLFW init failed");
        }

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

    Graphics::SupportedGraphicsAPI
        GLFWContext::get_window_graphics_api() const
    {
        return window_graphics_api;
    }

    bool GLFWContext::create_window(
        Graphics::SupportedGraphicsAPI graphics_api, Math::Size2Di size,
        const std::string& name, bool maximize)
    {
        if (!has_init || main_window)
        {
            return false;
        }

        glfwWindowHint(GLFW_MAXIMIZED, maximize);
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

            Log::TerminalLogger::get("Engine")->success(
                "Window init successful");
        }
        else
        {
            Log::TerminalLogger::get("Engine")->error(
                "Window init failed");
        }

        return window;
    }

    Math::Size2Di GLFWContext::get_framebuffer_size() const
    {
        Math::Size2Di framebuffer_size{};
        glfwGetFramebufferSize(main_window, &framebuffer_size.width,
            &framebuffer_size.height);

        return framebuffer_size;
    }

    void GLFWContext::maximize_window() const
    {
        glfwMaximizeWindow(main_window);
    }

    void GLFWContext::set_main_window_name(
        const std::string& new_main_window_name)
    {
        glfwSetWindowTitle(main_window, new_main_window_name.c_str());
    }

    void GLFWContext::set_main_window_framebuffer_size_callback(
        void(*callback)(GLFWwindow*, int, int))
    {
        glfwSetFramebufferSizeCallback(main_window, callback);
    }

    void GLFWContext::set_main_window_key_callback(
        void(*callback)(GLFWwindow*, int, int, int, int))
    {
        glfwSetKeyCallback(main_window, callback);
    }

    void GLFWContext::close_main_window() const
    {
        glfwSetWindowShouldClose(main_window, GLFW_TRUE);
    }

    bool GLFWContext::main_window_should_close() const
    {
        return glfwWindowShouldClose(main_window) == GLFW_TRUE;
    }

    void GLFWContext::main_window_swap_buffers() const
    {
        glfwSwapBuffers(main_window);
    }

    void GLFWContext::poll_events() const
    {
        glfwPollEvents();
    }
}

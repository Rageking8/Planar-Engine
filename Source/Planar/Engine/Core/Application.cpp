#include "Planar/Engine/Core/Application.hpp"
#include "Planar/Engine/Core/Version.hpp"

#include "ThirdParty/glad/gl.h"
#include "ThirdParty/GLFW/glfw3.h"

namespace Planar::Engine::Core
{
    Application::Application(const std::string& window_name,
        Planar::Engine::Math::Size2Di window_size, bool maximize,
        Planar::Engine::Graphics::SupportedGraphicsAPI graphics_api) :
        window_name{ window_name }, window_size{ window_size },
        maximize{ maximize }, graphics_api{ graphics_api }
    {
        logger.log("Planar Engine " + VERSION);
    }

    Application::~Application()
    {

    }

    bool Application::init()
    {
        bool result = init_glfw() && create_window() &&
            init_glad() && init_imgui();

        if (result)
        {
            glfw_context.set_main_window_framebuffer_size_callback(
                [](GLFWwindow* window, int width, int height)
                {

                });
        }

        return result;
    }

    void Application::run()
    {
        glfwSwapInterval(1);
        
        if (main_scene)
        {
            main_scene->start();
        }

        while (!glfw_context.main_window_should_close())
        {
            if (main_scene)
            {
                main_scene->update();
            }

            imgui_context.new_frame();
            
            glClearColor(0.071f, 0.071f, 0.071f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

            if (main_scene)
            {
                main_scene->render();
            }

            imgui_context.render();

            glfw_context.main_window_swap_buffers();
            glfw_context.poll_events();
        }
    }

    void Application::load_scene(
        std::unique_ptr<Planar::Engine::Scene::Scene> scene)
    {
        main_scene = std::move(scene);
        main_scene->init();
    }

    void Application::maximize_window() const
    {
        glfw_context.maximize_window();
    }

    void Application::set_window_name(const std::string& new_window_name)
    {
        window_name = new_window_name;
        glfw_context.set_main_window_name(new_window_name);
    }

    bool Application::init_glfw()
    {
        return glfw_context.init(&logger);
    }

    bool Application::init_glad()
    {
        const int version = gladLoadGL(glfwGetProcAddress);
        if (version == 0)
        {
            logger.error("OpenGL init failed");

            return false;
        }

        logger.success("OpenGL init successful");

        return true;
    }

    bool Application::init_imgui()
    {
        return imgui_context.init(glfw_context, &logger);
    }

    bool Application::create_window()
    {
        return glfw_context.create_window(graphics_api,
            window_size, window_name, maximize, &logger);
    }
}

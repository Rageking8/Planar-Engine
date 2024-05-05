#include "Planar/Engine/Core/Application.hpp"
#include "Planar/Engine/Core/Version.hpp"

#include "ThirdParty/glad/gl.h"
#include "ThirdParty/GLFW/glfw3.h"

namespace Planar::Engine::Core
{
    Application::Application()
    {
        logger.log("Planar Engine " + VERSION);
    }

    Application::~Application()
    {

    }

    bool Application::init()
    {
        if (!glfw_context.init(&logger))
        {
            return false;
        }

        if (!glfw_context.create_window(
            Planar::Engine::Graphics::SupportedGraphicsAPI::OPENGL_4_6,
            { 1280, 720 }, "Hello Window", &logger))
        {
            return false;
        }

        const int version = gladLoadGL(glfwGetProcAddress);
        if (version == 0)
        {
            logger.error("OpenGL init failed");

            return false;
        }
        else
        {
            logger.success("OpenGL init successful");
        }

        if (!imgui_context.init(glfw_context, &logger))
        {
            return false;
        }

        return true;
    }

    void Application::run()
    {
        glfwSwapInterval(1);
        
        GLFWwindow* main_window = glfw_context.get_main_window();

        if (main_scene)
        {
            main_scene->start();
        }

        while (!glfwWindowShouldClose(main_window))
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
            
            glfwSwapBuffers(main_window);
            glfwPollEvents();
        }
    }

    void Application::load_scene(
        std::unique_ptr<Planar::Engine::Scene::Scene> scene)
    {
        main_scene = std::move(scene);
        main_scene->init();
    }
}

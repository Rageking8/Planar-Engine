#include "Planar/Engine/Core/Application.hpp"

#include "ThirdParty/glad/gl.h"
#include "ThirdParty/GLFW/glfw3.h"
#include "ThirdParty/ImGui/imgui.h"
#include "ThirdParty/ImGui/imgui_impl_glfw.h"
#include "ThirdParty/ImGui/imgui_impl_opengl3.h"

#include <iostream>

namespace Planar::Engine::Core
{
    Application::Application()
    {

    }

    Application::~Application()
    {

    }

    bool Application::init()
    {
        if (!glfw_context.init())
        {
            std::cerr << "GLFW init failed\n";

            return false;
        }

        if (!glfw_context.create_window(
            Planar::Engine::Graphics::SupportedGraphicsAPI::OPENGL_4_6,
            { 1280, 720 }, "Hello Window"))
        {
            std::cerr << "window init failed\n";

            return false;
        }

        const int version = gladLoadGL(glfwGetProcAddress);
        if (version == 0)
        {
            std::cerr << "OpenGL init failed\n";

            return false;
        }

        if (!imgui_context.init(glfw_context))
        {
            std::cerr << "ImGui init failed\n";

            return false;
        }

        return true;
    }

    void Application::run()
    {
        glfwSwapInterval(1);
        
        bool hello_window = true;
        GLFWwindow* main_window = glfw_context.get_main_window();

        while (!glfwWindowShouldClose(main_window))
        {
            imgui_context.new_frame();
            
            if (hello_window)
            {
                bool open = ImGui::Begin("Hello ImGui!", &hello_window);
                if (open)
                {
                    ImGui::Text("I am a window!");
                }
                ImGui::End();
            }

            glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

            imgui_context.render();
            
            glfwSwapBuffers(main_window);
            glfwPollEvents();
        }
    }
}

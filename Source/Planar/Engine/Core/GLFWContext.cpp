#include "Planar/Engine/Core/GLFWContext.hpp"

#include "ThirdParty/glad/gl.h"
#include "ThirdParty/GLFW/glfw3.h"
#include "ThirdParty/ImGui/imgui.h"
#include "ThirdParty/ImGui/imgui_impl_glfw.h"
#include "ThirdParty/ImGui/imgui_impl_opengl3.h"

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

    void GLFWContext::run()
    {
        const int version = gladLoadGL(glfwGetProcAddress);
        if (version == 0)
        {
            std::cerr << "OpenGL init failed\n";
        }

        glfwSwapInterval(1);

        IMGUI_CHECKVERSION();
        ImGui::CreateContext();
        ImGuiIO& io = ImGui::GetIO();
        io.IniFilename = nullptr;
        io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
        io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;

        ImGui::StyleColorsDark();

        ImGui_ImplGlfw_InitForOpenGL(main_window, true);
        ImGui_ImplOpenGL3_Init("#version 460");

        bool hello_window = true;

        while (!glfwWindowShouldClose(main_window))
        {
            ImGui_ImplOpenGL3_NewFrame();
            ImGui_ImplGlfw_NewFrame();
            ImGui::NewFrame();

            if (hello_window)
            {
                bool open = ImGui::Begin("Hello ImGui!", &hello_window);
                if (open)
                {
                    ImGui::Text("I am a window!");
                }
                ImGui::End();
            }

            ImGui::Render();
            int display_w, display_h;
            glfwGetFramebufferSize(main_window, &display_w, &display_h);
            glViewport(0, 0, display_w, display_h);
            glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
            ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

            glfwSwapBuffers(main_window);
            glfwPollEvents();
        }

        ImGui_ImplOpenGL3_Shutdown();
        ImGui_ImplGlfw_Shutdown();
        ImGui::DestroyContext();
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

            glfwMakeContextCurrent(window);
        }

        return window;
    }
}

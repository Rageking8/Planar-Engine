#include "Planar/Engine/Core/GLFWContext.hpp"
#include "Planar/Engine/Core/ImGuiContext.hpp"
#include "Planar/Engine/Graphics/SupportedGraphicsAPI.hpp"

#include <iostream>

int main()
{
    Planar::Engine::Core::GLFWContext glfw_context;
    if (!glfw_context.init())
    {
        std::cerr << "GLFW init failed\n";

        return -1;
    }

    if (!glfw_context.create_window(
        Planar::Engine::Graphics::SupportedGraphicsAPI::OPENGL_4_6,
        { 1280, 720 }, "Hello Window"))
    {
        std::cerr << "window init failed\n";

        return -1;
    }

    Planar::Engine::Core::ImGuiContext imgui_context;
    if (!imgui_context.init(glfw_context))
    {
        std::cerr << "ImGui init failed\n";

        return -1;
    }

    glfw_context.run();
}

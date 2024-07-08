#pragma once

#include "Planar/Engine/Export/ExportMacros.hpp"
#include "Planar/Engine/Core/Utils/Macros/DeclarationMacros.hpp"

struct GLFWwindow;

PLANAR_ENGINE_FORWARD_DECLARE_CLASS(Core::GLFW, GLFWContext)

namespace Planar::Engine::UI::ImGui
{
    class PLANAR_API ImGuiContext
    {
    public:
        ImGuiContext();
        ~ImGuiContext();

        bool init(
            const Engine::Core::GLFW::GLFWContext& glfw_context,
            bool defer_install_callback = true);
        void install_callback() const;
        void terminate();

        void new_frame() const;
        void render() const;

    private:
        bool has_init;

        GLFWwindow* defer_install_callback_window;
    };
}

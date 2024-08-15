#include "Planar/Engine/UI/ImGui/ImGuiContext.hpp"
#include "Planar/Engine/UI/ImGui/ImGui.hpp"
#include "Planar/Engine/Core/Log/TerminalLogger.hpp"
#include "Planar/Engine/Core/GLFW/GLFWContext.hpp"

#include "ThirdParty/ImGui/imgui.h"
#include "ThirdParty/ImGui/imgui_impl_glfw.h"
#include "ThirdParty/ImGui/imgui_impl_opengl3.h"

namespace Planar::Engine::UI::ImGui
{
    ImGuiContext::ImGuiContext() : has_init{},
        defer_install_callback_window{}
    {

    }

    ImGuiContext::~ImGuiContext()
    {
        terminate();
    }

    bool ImGuiContext::init(
        const Engine::Core::GLFW::GLFWContext& glfw_context,
        bool defer_install_callback)
    {
        ::IMGUI_CHECKVERSION();
        ::ImGui::CreateContext();

        set_ini_filename();
        set_config_flags(ImGuiConfigFlags_NavEnableKeyboard |
            ImGuiConfigFlags_NavEnableGamepad |
            ImGuiConfigFlags_DockingEnable);

        ::ImGui::StyleColorsDark();

        ::ImGui_ImplGlfw_InitForOpenGL(glfw_context.get_main_window(),
            !defer_install_callback);
        ::ImGui_ImplOpenGL3_Init(glfw_context.get_window_graphics_api().
            get_version_string());

        has_init = true;

        if (defer_install_callback)
        {
            defer_install_callback_window = glfw_context.
                get_main_window();
        }

        Core::Log::TerminalLogger::get("Engine")->success(
            "ImGui init successful");

        return true;
    }

    void ImGuiContext::install_callback() const
    {
        ::ImGui_ImplGlfw_InstallCallbacks(
            defer_install_callback_window);
    }

    void ImGuiContext::terminate()
    {
        if (!has_init)
        {
            return;
        }

        ::ImGui_ImplOpenGL3_Shutdown();
        ::ImGui_ImplGlfw_Shutdown();
        ::ImGui::DestroyContext();

        has_init = false;
    }

    void ImGuiContext::new_frame() const
    {
        if (!has_init)
        {
            return;
        }

        ::ImGui_ImplOpenGL3_NewFrame();
        ::ImGui_ImplGlfw_NewFrame();
        ::ImGui::NewFrame();
    }

    void ImGuiContext::render() const
    {
        if (!has_init)
        {
            return;
        }

        ::ImGui::Render();
        ::ImGui_ImplOpenGL3_RenderDrawData(::ImGui::GetDrawData());
    }
}

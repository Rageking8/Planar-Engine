#include "Planar/Engine/UI/ImGui/ImGuiContext.hpp"
#include "Planar/Engine/UI/ImGui/ImGui.hpp"
#include "Planar/Engine/Core/Log/TerminalLogger.hpp"

#include "ThirdParty/ImGui/imgui.h"
#include "ThirdParty/ImGui/imgui_impl_glfw.h"
#include "ThirdParty/ImGui/imgui_impl_opengl3.h"

namespace Planar::Engine::UI::ImGui
{
    ImGuiContext::ImGuiContext() : has_init{}
    {

    }

    ImGuiContext::~ImGuiContext()
    {
        terminate();
    }

    bool ImGuiContext::init(
        const Planar::Engine::Core::GLFWContext& glfw_context)
    {
        ::IMGUI_CHECKVERSION();
        ::ImGui::CreateContext();

        Planar::Engine::UI::ImGui::set_ini_filename();
        Planar::Engine::UI::ImGui::set_config_flags(
            ImGuiConfigFlags_NavEnableKeyboard |
            ImGuiConfigFlags_NavEnableGamepad |
            ImGuiConfigFlags_DockingEnable);

        ::ImGui::StyleColorsDark();

        ::ImGui_ImplGlfw_InitForOpenGL(glfw_context.get_main_window(),
            true);
        ::ImGui_ImplOpenGL3_Init(glfw_context.get_window_graphics_api().
            get_version_string());

        has_init = true;

        Core::Log::TerminalLogger::get("Engine")->success(
            "ImGui init successful");

        return true;
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

#include "Planar/Engine/Core/ImGuiContext.hpp"

#include "ThirdParty/ImGui/imgui.h"
#include "ThirdParty/ImGui/imgui_impl_glfw.h"
#include "ThirdParty/ImGui/imgui_impl_opengl3.h"

namespace Planar::Engine::Core
{
    ImGuiContext::ImGuiContext() : has_init{}
    {

    }

    ImGuiContext::~ImGuiContext()
    {
        terminate();
    }

    bool ImGuiContext::init(const GLFWContext& glfw_context,
        Utils::Log::LoggerBase* logger)
    {
        IMGUI_CHECKVERSION();
        ImGui::CreateContext();
        ImGuiIO& io = ImGui::GetIO();
        io.IniFilename = nullptr;
        io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
        io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;

        ImGui::StyleColorsDark();

        ImGui_ImplGlfw_InitForOpenGL(glfw_context.main_window,
            true);
        ImGui_ImplOpenGL3_Init(glfw_context.window_graphics_api.
            get_version_string());

        has_init = true;

        if (logger)
        {
            logger->success("ImGui init successful");
        }

        return true;
    }

    void ImGuiContext::terminate()
    {
        if (!has_init)
        {
            return;
        }

        ImGui_ImplOpenGL3_Shutdown();
        ImGui_ImplGlfw_Shutdown();
        ImGui::DestroyContext();

        has_init = false;
    }

    void ImGuiContext::new_frame() const
    {
        if (!has_init)
        {
            return;
        }

        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();
    }

    void ImGuiContext::render() const
    {
        if (!has_init)
        {
            return;
        }

        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    }
}

#pragma once

#include "Planar/Engine/Scene/Scene.hpp"
#include "Planar/Engine/Math/Size2D.hpp"
#include "Planar/Engine/Core/GLFW/GLFWContext.hpp"
#include "Planar/Engine/Core/Input/InputController.hpp"
#include "Planar/Engine/Core/Utils/Macros/TypeHelperMacros.hpp"
#include "Planar/Engine/Export/ExportMacros.hpp"
#include "Planar/Engine/UI/ImGui/ImGuiContext.hpp"
#include "Planar/Engine/Graphics/SupportedGraphicsAPI.hpp"

#include <string>
#include <memory>
#include <functional>

namespace Planar::Engine::Core
{
    class PLANAR_API Application
    {
    public:
        Application(const std::string& window_name = "Application",
            Math::Size2Di window_size = { 1280, 720 },
            bool maximize = false,
            Graphics::SupportedGraphicsAPI graphics_api =
            Graphics::SupportedGraphicsAPI::OPENGL_4_6);
        virtual ~Application();

        virtual bool init();
        virtual void run();

        void render_single_frame(const std::function<void()>& render);
        void render_main_scene_single_frame();

        void load_scene(std::unique_ptr<Scene::Scene> scene);

        void maximize_window() const;
        void set_window_name(const std::string& new_window_name);

        Input::InputController& get_input_controller();

    protected:
        virtual bool init_glfw();
        virtual bool init_glad();
        virtual bool init_imgui();

        virtual bool create_window();

        std::string window_name;
        Math::Size2Di window_size;
        bool maximize;
        Graphics::SupportedGraphicsAPI graphics_api;

        Input::InputController input_controller;

        PLANAR_ADD_BASE_USING(Application)

    private:
        GLFW::GLFWContext glfw_context;
        UI::ImGui::ImGuiContext imgui_context;

        std::unique_ptr<Scene::Scene> main_scene;
    };
}

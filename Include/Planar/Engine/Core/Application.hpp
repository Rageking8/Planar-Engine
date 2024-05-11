#pragma once

#include "Planar/Engine/Scene/Scene.hpp"
#include "Planar/Engine/Math/Size2D.hpp"
#include "Planar/Engine/Core/GLFWContext.hpp"
#include "Planar/Engine/Core/Log/Logger.hpp"
#include "Planar/Engine/Export/ExportMacros.hpp"
#include "Planar/Engine/UI/ImGui/ImGuiContext.hpp"
#include "Planar/Engine/Graphics/SupportedGraphicsAPI.hpp"

#include <string>
#include <memory>

namespace Planar::Engine::Core
{
    class PLANAR_API Application
    {
    public:
        Application(const std::string& window_name = "Application",
            Planar::Engine::Math::Size2Di window_size = { 1280, 720 },
            bool maximize = false,
            Planar::Engine::Graphics::SupportedGraphicsAPI graphics_api =
            Planar::Engine::Graphics::SupportedGraphicsAPI::OPENGL_4_6);
        virtual ~Application();

        virtual bool init();
        virtual void run();

        void load_scene(
            std::unique_ptr<Planar::Engine::Scene::Scene> scene);

        void maximize_window() const;
        void set_window_name(const std::string& new_window_name);

    protected:
        virtual bool init_glfw();
        virtual bool init_glad();
        virtual bool init_imgui();

        virtual bool create_window();

        std::string window_name;
        Planar::Engine::Math::Size2Di window_size;
        bool maximize;
        Planar::Engine::Graphics::SupportedGraphicsAPI graphics_api;

    private:
        GLFWContext glfw_context;
        Planar::Engine::UI::ImGui::ImGuiContext imgui_context;

        Log::Logger logger;

        std::unique_ptr<Planar::Engine::Scene::Scene> main_scene;
    };
}

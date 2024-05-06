#pragma once

#include "Planar/Engine/Scene/Scene.hpp"
#include "Planar/Engine/Math/Size2D.hpp"
#include "Planar/Engine/Core/GLFWContext.hpp"
#include "Planar/Engine/Core/ImGuiContext.hpp"
#include "Planar/Engine/Core/ExportMacros.hpp"
#include "Planar/Engine/Core/Utils/Log/Logger.hpp"
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
        virtual ~Application() = 0;

        virtual bool init();
        virtual void run();

        void load_scene(
            std::unique_ptr<Planar::Engine::Scene::Scene> scene);

        void maximize_window() const;

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
        ImGuiContext imgui_context;

        Utils::Log::Logger logger;

        std::unique_ptr<Planar::Engine::Scene::Scene> main_scene;
    };
}

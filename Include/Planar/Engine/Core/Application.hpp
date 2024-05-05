#pragma once

#include "Planar/Engine/Scene/Scene.hpp"
#include "Planar/Engine/Core/GLFWContext.hpp"
#include "Planar/Engine/Core/ImGuiContext.hpp"
#include "Planar/Engine/Core/Utils/Log/Logger.hpp"
#include "Planar/Engine/Core/ExportMacros.hpp"

#include <memory>

namespace Planar::Engine::Core
{
    class PLANAR_API Application
    {
    public:
        Application();
        virtual ~Application();

        virtual bool init(const std::string& window_name);
        virtual void run();

        void load_scene(
            std::unique_ptr<Planar::Engine::Scene::Scene> scene);

    private:
        GLFWContext glfw_context;
        ImGuiContext imgui_context;

        Utils::Log::Logger logger;

        std::unique_ptr<Planar::Engine::Scene::Scene> main_scene;
    };
}

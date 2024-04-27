#pragma once

#include "Planar/Engine/Core/GLFWContext.hpp"
#include "Planar/Engine/Core/ImGuiContext.hpp"
#include "Planar/Engine/Core/Utils/Log/Logger.hpp"
#include "Planar/Engine/Core/ExportMacros.hpp"

namespace Planar::Engine::Core
{
    class PLANAR_API Application
    {
    public:
        Application();
        ~Application();

        bool init();
        void run();

    private:
        GLFWContext glfw_context;
        ImGuiContext imgui_context;

        Utils::Log::Logger logger;
    };
}

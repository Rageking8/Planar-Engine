#pragma once

#include "Planar/Engine/Math/Size2D.hpp"
#include "Planar/Engine/Core/Utils/Log/Logger.hpp"
#include "Planar/Engine/Core/ExportMacros.hpp"
#include "Planar/Engine/Graphics/SupportedGraphicsAPI.hpp"

#include <string>

struct GLFWwindow;

namespace Planar::Engine::Core
{
    class PLANAR_API GLFWContext
    {
        friend class ImGuiContext;

    public:
        GLFWContext();
        ~GLFWContext();

        bool init(Utils::Log::Logger* logger = nullptr);
        void terminate();

        GLFWwindow* get_main_window() const;
        bool create_window(
            Planar::Engine::Graphics::SupportedGraphicsAPI graphics_api,
            Planar::Engine::Math::Size2Di size,
            const std::string& name,
            Utils::Log::Logger* logger = nullptr);

    private:
        bool has_init;

        GLFWwindow* main_window;
        Planar::Engine::Graphics::SupportedGraphicsAPI window_graphics_api;
    };
}

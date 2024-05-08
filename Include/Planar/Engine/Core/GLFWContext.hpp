#pragma once

#include "Planar/Engine/Math/Size2D.hpp"
#include "Planar/Engine/Core/Log/LoggerBase.hpp"
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

        bool init(Log::LoggerBase* logger = nullptr);
        void terminate();

        GLFWwindow* get_main_window() const;
        bool create_window(
            Planar::Engine::Graphics::SupportedGraphicsAPI graphics_api,
            Planar::Engine::Math::Size2Di size,
            const std::string& name,
            bool maximize = false,
            Log::LoggerBase* logger = nullptr);

        void maximize_window() const;

    private:
        bool has_init;

        GLFWwindow* main_window;
        Planar::Engine::Graphics::SupportedGraphicsAPI window_graphics_api;
    };
}

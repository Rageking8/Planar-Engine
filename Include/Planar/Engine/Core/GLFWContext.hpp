#pragma once

#include "Planar/Engine/Math/Size2D.hpp"
#include "Planar/Engine/Core/Log/LoggerBase.hpp"
#include "Planar/Engine/Export/ExportMacros.hpp"
#include "Planar/Engine/Graphics/SupportedGraphicsAPI.hpp"

#include <string>

struct GLFWwindow;

namespace Planar::Engine::Core
{
    class PLANAR_API GLFWContext
    {
    public:
        GLFWContext();
        ~GLFWContext();

        bool init(Log::LoggerBase* logger = nullptr);
        void terminate();

        GLFWwindow* get_main_window() const;
        Planar::Engine::Graphics::SupportedGraphicsAPI
            get_window_graphics_api() const;

        bool create_window(
            Planar::Engine::Graphics::SupportedGraphicsAPI graphics_api,
            Planar::Engine::Math::Size2Di size,
            const std::string& name,
            bool maximize = false,
            Log::LoggerBase* logger = nullptr);

        void maximize_window() const;
        void set_main_window_name(const std::string& new_main_window_name);
        void set_main_window_framebuffer_size_callback(
            void(*callback)(GLFWwindow*, int, int));

    private:
        bool has_init;

        GLFWwindow* main_window;
        Planar::Engine::Graphics::SupportedGraphicsAPI window_graphics_api;
    };
}

#pragma once

#include "Planar/Engine/Math/Size2D.hpp"
#include "Planar/Engine/Export/ExportMacros.hpp"
#include "Planar/Engine/Graphics/SupportedGraphicsAPI.hpp"

#include <string>

struct GLFWwindow;

namespace Planar::Engine::Core::GLFW
{
    class PLANAR_API GLFWContext
    {
    public:
        GLFWContext();
        ~GLFWContext();

        bool init();
        void terminate();

        GLFWwindow* get_main_window() const;
        Graphics::SupportedGraphicsAPI get_window_graphics_api() const;

        bool create_window(Graphics::SupportedGraphicsAPI graphics_api,
            Math::Size2Di size, const std::string& name,
            bool maximize = false);

        Math::Size2Di get_framebuffer_size() const;

        void maximize_window() const;
        void set_main_window_name(const std::string& new_main_window_name);
        void set_main_window_framebuffer_size_callback(
            void(*callback)(GLFWwindow*, int, int));
        void set_main_window_key_callback(
            void(*callback)(GLFWwindow*, int, int, int, int));

        bool main_window_should_close() const;
        void main_window_swap_buffers() const;

        void poll_events() const;

    private:
        bool has_init;

        GLFWwindow* main_window;
        Graphics::SupportedGraphicsAPI window_graphics_api;
    };
}

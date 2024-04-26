#pragma once

#include "Planar/Engine/Math/Size2D.hpp"
#include "Planar/Engine/Core/ExportMacros.hpp"
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

        bool init();
        void terminate();

        void run();
        bool create_window(
            Planar::Engine::Graphics::SupportedGraphicsAPI graphics_api,
            Planar::Engine::Math::Size2Di size,
            const std::string& name);

    private:
        bool has_init;

        GLFWwindow* main_window;
    };
}

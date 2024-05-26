#pragma once

#include "Planar/Engine/Export/ExportMacros.hpp"
#include "Planar/Engine/Core/GLFWContext.hpp"

namespace Planar::Engine::UI::ImGui
{
    class PLANAR_API ImGuiContext
    {
    public:
        ImGuiContext();
        ~ImGuiContext();

        bool init(
            const Planar::Engine::Core::GLFWContext& glfw_context);
        void terminate();

        void new_frame() const;
        void render() const;

    private:
        bool has_init;
    };
}

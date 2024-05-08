#pragma once

#include "Planar/Engine/Core/ExportMacros.hpp"
#include "Planar/Engine/Core/GLFWContext.hpp"
#include "Planar/Engine/Core/Log/LoggerBase.hpp"

namespace Planar::Engine::UI::ImGui
{
    class PLANAR_API ImGuiContext
    {
    public:
        ImGuiContext();
        ~ImGuiContext();

        bool init(
            const Planar::Engine::Core::GLFWContext& glfw_context,
            Planar::Engine::Core::Log::LoggerBase* logger = nullptr);
        void terminate();

        void new_frame() const;
        void render() const;

    private:
        bool has_init;
    };
}

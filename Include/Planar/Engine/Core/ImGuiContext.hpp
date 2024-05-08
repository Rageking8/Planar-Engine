#pragma once

#include "Planar/Engine/Core/ExportMacros.hpp"
#include "Planar/Engine/Core/GLFWContext.hpp"
#include "Planar/Engine/Core/Log/LoggerBase.hpp"

namespace Planar::Engine::Core
{
    class PLANAR_API ImGuiContext
    {
    public:
        ImGuiContext();
        ~ImGuiContext();

        bool init(const GLFWContext& glfw_context,
            Log::LoggerBase* logger = nullptr);
        void terminate();

        void new_frame() const;
        void render() const;

    private:
        bool has_init;
    };
}

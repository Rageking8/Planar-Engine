#pragma once

#include "Planar/Engine/Core/ExportMacros.hpp"
#include "Planar/Engine/UI/ImGui/ImGuiWindowFlags.hpp"

#include <string>

namespace Planar::Engine::UI::ImGui
{
    class PLANAR_API ImGuiWindow
    {
    public:
        ImGuiWindow(const std::string& name,
            ImGuiWindowFlags flags = ImGuiWindowFlags::NONE);
        ~ImGuiWindow();
    };
}

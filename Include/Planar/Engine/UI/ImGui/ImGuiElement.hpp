#pragma once

#include "Planar/Engine/Export/ExportMacros.hpp"

namespace Planar::Engine::UI::ImGui
{
    class PLANAR_API ImGuiElement
    {
    public:
        ImGuiElement();
        virtual ~ImGuiElement() = 0;

        virtual void render();
    };
}

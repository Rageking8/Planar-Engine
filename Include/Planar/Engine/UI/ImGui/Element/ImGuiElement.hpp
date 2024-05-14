#pragma once

#include "Planar/Engine/Export/ExportMacros.hpp"

namespace Planar::Engine::UI::ImGui::Element
{
    class PLANAR_API ImGuiElement
    {
    public:
        ImGuiElement();
        virtual ~ImGuiElement() = 0;

        virtual void render();
    };
}

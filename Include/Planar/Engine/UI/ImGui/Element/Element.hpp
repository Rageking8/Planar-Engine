#pragma once

#include "Planar/Engine/Export/ExportMacros.hpp"

namespace Planar::Engine::UI::ImGui::Element
{
    class PLANAR_API Element
    {
    public:
        Element();
        virtual ~Element() = 0;

        virtual void render();
    };
}

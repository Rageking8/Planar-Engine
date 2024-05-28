#pragma once

#include "Planar/Engine/Export/ExportMacros.hpp"

#include <string>

namespace Planar::Engine::UI::ImGui::Wrapper
{
    class PLANAR_API Child
    {
    public:
        Child(const std::string& name);
        ~Child();
    };
}

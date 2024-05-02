#include "Planar/Engine/UI/ImGui/ImGui.hpp"

#include "ThirdParty/ImGui/imgui.h"

namespace Planar::Engine::UI::ImGui
{
    void text(const std::string& text)
    {
        ::ImGui::Text(text.c_str());
    }

    bool button(const std::string& name,
        Planar::Engine::Math::Size2Df size)
    {
        return ::ImGui::Button(name.c_str(),
            { size.width, size.height });
    }

    void newline()
    {
        ::ImGui::NewLine();
    }
}

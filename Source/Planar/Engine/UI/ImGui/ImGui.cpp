#include "Planar/Engine/UI/ImGui/ImGui.hpp"
#include "Planar/Engine/Core/GUID/GUID.hpp"

#include "ThirdParty/ImGui/imgui.h"

namespace Planar::Engine::UI::ImGui
{
    void reset_style()
    {
        ::ImGui::GetStyle() = ImGuiStyle();
    }

    void scale_ui(int factor)
    {
        ::ImGui::GetStyle().ScaleAllSizes(
            static_cast<float>(factor));
    }

    std::string generate_unique_label()
    {
        return "##" + Planar::Engine::Core::GUID::generate_guid(
            Planar::Engine::Core::GUID::Representation::DEFAULT_COMPACT);
    }

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

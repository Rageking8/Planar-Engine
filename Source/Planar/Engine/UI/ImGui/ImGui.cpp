#include "Planar/Engine/UI/ImGui/ImGui.hpp"
#include "Planar/Engine/Core/GUID/GUID.hpp"

#include "ThirdParty/ImGui/imgui.h"
#include "ThirdParty/ImGui/imgui_stdlib.h"

namespace Planar::Engine::UI::ImGui
{
    void set_ini_filename(const std::string& ini_filename)
    {
        ::ImGui::GetIO().IniFilename =
            ini_filename.empty() ? nullptr : ini_filename.c_str();
    }

    void set_config_flags(int config_flags)
    {
        ::ImGui::GetIO().ConfigFlags = config_flags;
    }

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

    void input_text(const std::string& label, std::string& text)
    {
        ::ImGui::InputText(label.c_str(), &text);
    }

    void input_text(const std::string& label,
        const std::string& placeholder, std::string& text)
    {
        ::ImGui::InputTextWithHint(label.c_str(),
            placeholder.c_str(), &text);
    }

    void newline()
    {
        ::ImGui::NewLine();
    }

    void dock_space_over_viewport()
    {
        ::ImGui::DockSpaceOverViewport(::ImGui::GetMainViewport());
    }
}

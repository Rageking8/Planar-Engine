#include "Planar/Engine/UI/ImGui/ImGuiInputField.hpp"
#include "Planar/Engine/UI/ImGui/ImGui.hpp"

namespace Planar::Engine::UI::ImGui
{
    ImGuiInputField::ImGuiInputField(const std::string& placeholder) :
        label{ generate_unique_label() }, placeholder{ placeholder }
    {

    }

    void ImGuiInputField::render()
    {
        input_text(label, placeholder, text);
    }

    constexpr const std::string& ImGuiInputField::get_text() const
    {
        return text;
    }
}

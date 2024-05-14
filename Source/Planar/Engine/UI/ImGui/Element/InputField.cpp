#include "Planar/Engine/UI/ImGui/Element/InputField.hpp"
#include "Planar/Engine/UI/ImGui/ImGui.hpp"

namespace Planar::Engine::UI::ImGui::Element
{
    InputField::InputField(const std::string& placeholder) :
        label{ generate_unique_label() }, placeholder{ placeholder }
    {

    }

    void InputField::render()
    {
        input_text(label, placeholder, text);
    }

    constexpr const std::string& InputField::get_text() const
    {
        return text;
    }
}

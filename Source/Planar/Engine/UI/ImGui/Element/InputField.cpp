#include "Planar/Engine/UI/ImGui/Element/InputField.hpp"
#include "Planar/Engine/UI/ImGui/ImGui.hpp"

namespace Planar::Engine::UI::ImGui::Element
{
    InputField::InputField(const std::string& placeholder,
        Core::Size::Width width) : label{ generate_unique_label() },
        placeholder{ placeholder }, width{ width }
    {

    }

    void InputField::render()
    {
        width.set();
        input_text(label, placeholder, text);
    }

    const std::string& InputField::get_text() const
    {
        return text;
    }

    void InputField::set_text(const std::string& new_text)
    {
        text = new_text;
    }

    void InputField::clear_text()
    {
        text.clear();
    }
}

#include "Planar/Engine/UI/ImGui/Element/InputField.hpp"
#include "Planar/Engine/UI/ImGui/ImGui.hpp"

#include "ThirdParty/ImGui/imgui.h"

namespace Planar::Engine::UI::ImGui::Element
{
    InputField::InputField(const std::string& placeholder,
        bool read_only, Core::Size::Width width) :
        label{ generate_unique_label() }, placeholder{ placeholder },
        width{ width }, read_only{ read_only }
    {

    }

    void InputField::render()
    {
        width.set();

        update_modified(input_text(label, placeholder,
            text, generate_flags()));
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

    int InputField::generate_flags() const
    {
        ImGuiInputTextFlags flags{};

        if (read_only)
        {
            flags |= ImGuiInputTextFlags_ReadOnly;
        }

        return flags;
    }
}

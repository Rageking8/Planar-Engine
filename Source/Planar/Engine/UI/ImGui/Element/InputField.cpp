#include "Planar/Engine/UI/ImGui/Element/InputField.hpp"
#include "Planar/Engine/UI/ImGui/Core/Cursor/Cursor.hpp"
#include "Planar/Engine/UI/ImGui/ImGui.hpp"

#include "ThirdParty/ImGui/imgui.h"

namespace Planar::Engine::UI::ImGui::Element
{
    InputField::InputField(const std::string& placeholder,
        const std::string& display_text, Core::Size::Width width,
        float x_pos, bool read_only) :
        label{ generate_unique_label() }, placeholder{ placeholder },
        display_text{ display_text }, width{ width }, x_pos{ x_pos },
        read_only{ read_only }
    {

    }

    void InputField::render()
    {
        if (!display_text.empty())
        {
            ImGui::text(display_text, true);
            same_line();
            Core::Cursor::set_x(x_pos);
        }

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

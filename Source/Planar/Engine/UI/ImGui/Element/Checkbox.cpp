#include "Planar/Engine/UI/ImGui/Element/Checkbox.hpp"
#include "Planar/Engine/UI/ImGui/ImGui.hpp"

#include "ThirdParty/ImGui/imgui.h"

namespace Planar::Engine::UI::ImGui::Element
{
    Checkbox::Checkbox(const std::string& label, bool value) :
        value{ value }
    {
        this->label = label.empty() ? generate_unique_label() : label;
    }

    void Checkbox::render()
    {
        update_modified(::ImGui::Checkbox(label.c_str(), &value));
    }

    bool Checkbox::get_value() const
    {
        return value;
    }

    void Checkbox::set_value(bool new_value)
    {
        value = new_value;
    }
}

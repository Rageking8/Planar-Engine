#include "Planar/Engine/UI/ImGui/Element/Checkbox.hpp"

#include "ThirdParty/ImGui/imgui.h"

namespace Planar::Engine::UI::ImGui::Element
{
    Checkbox::Checkbox(const std::string& label, bool value) :
        label{ label }, value{ value }
    {

    }

    void Checkbox::render()
    {
        ::ImGui::Checkbox(label.c_str(), &value);
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

#include "Planar/Engine/UI/ImGui/Element/Drag/Drag.hpp"

#include "ThirdParty/ImGui/imgui.h"

namespace Planar::Engine::UI::ImGui::Element::Drag
{
    void drag_float(const std::string& label, float& value,
        float speed, float min, float max,
        const std::string& format, int flags)
    {
        ::ImGui::DragFloat(label.c_str(), &value, speed, min,
            max, format.c_str(), flags);
    }

    void drag_float_2(const std::string& label,
        std::array<float,2>& value, float speed, float min,
        float max, const std::string & format, int flags)
    {
        ::ImGui::DragFloat2(label.c_str(), value.data(), speed,
            min, max, format.c_str(), flags);
    }
}

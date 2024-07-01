#include "Planar/Engine/UI/ImGui/Element/Button/ButtonFunction.hpp"

#include "ThirdParty/ImGui/imgui.h"

namespace Planar::Engine::UI::ImGui::Element::Button
{
    bool button(const std::string& name, Math::Size2Df size)
    {
        return ::ImGui::Button(name.c_str(),
            { size.width, size.height });
    }

    bool button(const std::string& name, GLuint texture,
        Math::Size2Df size)
    {
        return ::ImGui::ImageButton(name.c_str(), (void*)texture,
            { size.width, size.height });
    }
}

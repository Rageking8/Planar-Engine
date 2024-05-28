#include "Planar/Engine/UI/ImGui/Wrapper/Child.hpp"

#include "ThirdParty/ImGui/imgui.h"

namespace Planar::Engine::UI::ImGui::Wrapper
{
    Child::Child(const std::string& name)
    {
        ::ImGui::BeginChild(name.c_str());
    }

    Child::~Child()
    {
        ::ImGui::EndChild();
    }
}

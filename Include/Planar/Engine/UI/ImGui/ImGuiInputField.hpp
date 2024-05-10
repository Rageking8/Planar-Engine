#pragma once

#include "Planar/Engine/Export/ExportMacros.hpp"
#include "Planar/Engine/UI/ImGui/ImGuiElement.hpp"

#include <string>

namespace Planar::Engine::UI::ImGui
{
    class PLANAR_API ImGuiInputField : public ImGuiElement
    {
    public:
        ImGuiInputField(const std::string& placeholder = "");

        virtual void render() override;

        constexpr const std::string& get_text() const;

    private:
        std::string label;
        std::string placeholder;
        std::string text;
    };
}

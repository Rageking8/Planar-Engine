#pragma once

#include "Planar/Engine/Export/ExportMacros.hpp"
#include "Planar/Engine/UI/ImGui/Element/Element.hpp"

#include <string>

namespace Planar::Engine::UI::ImGui::Element
{
    class PLANAR_API InputField : public Element
    {
    public:
        InputField(const std::string& placeholder = "");

        virtual void render() override;

        constexpr const std::string& get_text() const;
        void set_text(const std::string& new_text);

    private:
        std::string label;
        std::string placeholder;
        std::string text;
    };
}

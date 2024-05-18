#pragma once

#include "Planar/Engine/Export/ExportMacros.hpp"
#include "Planar/Engine/UI/ImGui/Element/Element.hpp"

#include <string>

namespace Planar::Engine::UI::ImGui::Element
{
    class PLANAR_API Checkbox : public Element
    {
    public:
        Checkbox(const std::string& label, bool value = false);

        virtual void render() override;

        bool get_value() const;

    private:
        bool value;
        std::string label;
    };
}

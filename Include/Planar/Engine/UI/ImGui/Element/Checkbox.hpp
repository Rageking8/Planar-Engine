#pragma once

#include "Planar/Engine/Export/ExportMacros.hpp"
#include "Planar/Engine/UI/ImGui/Element/Element.hpp"
#include "Planar/Engine/UI/ImGui/Core/State/ModifiedState.hpp"

#include <string>

namespace Planar::Engine::UI::ImGui::Element
{
    class PLANAR_API Checkbox : public Element,
        private Core::State::ModifiedState
    {
    public:
        Checkbox(const std::string& label, bool value = false);

        using ModifiedState::get_modified;

        virtual void render() override;

        bool get_value() const;
        void set_value(bool new_value);

    private:
        std::string label;
        bool value;
    };
}

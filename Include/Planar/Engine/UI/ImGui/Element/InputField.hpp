#pragma once

#include "Planar/Engine/Export/ExportMacros.hpp"
#include "Planar/Engine/UI/ImGui/Element/Element.hpp"
#include "Planar/Engine/UI/ImGui/Core/Size/Width.hpp"
#include "Planar/Engine/UI/ImGui/Core/State/ModifiedState.hpp"

#include <string>

namespace Planar::Engine::UI::ImGui::Element
{
    class PLANAR_API InputField : public Element,
        private Core::State::ModifiedState
    {
    public:
        InputField(const std::string& placeholder = "",
            Core::Size::Width width = {});

        using ModifiedState::get_modified;

        virtual void render() override;

        const std::string& get_text() const;
        void set_text(const std::string& new_text);
        void clear_text();

    private:
        std::string label;
        std::string placeholder;
        std::string text;
        Core::Size::Width width;
    };
}

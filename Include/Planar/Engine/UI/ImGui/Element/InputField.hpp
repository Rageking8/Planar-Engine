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
            const std::string& display_text = "",
            Core::Size::Width width = {}, float x_pos = 0.f,
            bool read_only = false);

        using ModifiedState::get_modified;

        virtual void render() override;

        bool empty() const;
        const std::string& get_text() const;
        void set_text(const std::string& new_text);
        void clear_text();

    protected:
        using ModifiedState::set_modified;

    private:
        std::string label;
        std::string placeholder;
        std::string text;
        std::string display_text;
        Core::Size::Width width;
        float x_pos;
        bool read_only;

        int generate_flags() const;
    };
}

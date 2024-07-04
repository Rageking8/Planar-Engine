#pragma once

#include "Planar/Engine/Export/ExportMacros.hpp"
#include "Planar/Engine/UI/ImGui/Element/Button/Button.hpp"
#include "Planar/Engine/UI/ImGui/Core/State/ModifiedState.hpp"

#include "ThirdParty/glad/gl.h"

#include <string>
#include <vector>
#include <optional>

namespace Planar::Engine::UI::ImGui::Element::Button
{
    class PLANAR_API ToggleButton : public Button,
        private Core::State::ModifiedState
    {
    public:
        struct ToggleState
        {
            std::string label;
            GLuint texture;
        };

        ToggleButton(Math::Size2Df size = {});

        using ModifiedState::get_modified;

        virtual void render() override;

        void add_state(const std::string& new_label,
            GLuint new_texture = 0);

        unsigned get_current() const;

    private:
        using Button::set;

        unsigned current;
        std::optional<std::vector<ToggleState>> states;

        void increment_current();
    };
}

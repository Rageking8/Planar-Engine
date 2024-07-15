#pragma once

#include "Planar/Engine/Export/ExportMacros.hpp"
#include "Planar/Engine/UI/ImGui/Element/Element.hpp"
#include "Planar/Engine/UI/ImGui/Core/Size/Width.hpp"
#include "Planar/Engine/UI/ImGui/Core/State/ModifiedState.hpp"

#include <string>
#include <vector>

#include "ThirdParty/ImGui/imgui.h"

namespace Planar::Engine::UI::ImGui::Element
{
    class PLANAR_API DropDown : public Element,
        private Core::State::ModifiedState
    {
    public:
        enum class Height
        {
            SMALL = ImGuiComboFlags_HeightSmall,

            REGULAR = ImGuiComboFlags_HeightRegular,

            LARGE = ImGuiComboFlags_HeightLarge,

            LARGEST = ImGuiComboFlags_HeightLargest,
        };

        DropDown(const std::string& label = "",
            Core::Size::Width width = {}, float x_pos = 0.f,
            const std::vector<std::string>& options = {});

        using ModifiedState::get_modified;

        virtual void render() override;

        unsigned get_selected_index() const;
        std::string get_selected_text() const;

        void set_selected_index(unsigned new_index,
            bool skip_modified = false);
        void set_selected_text(const std::string& new_text,
            bool skip_modified = false);

        void set_render_label(bool new_render_label);
        void set_options(const std::vector<std::string>& new_options);
        void set_height(Height new_height);

    private:
        unsigned index;
        std::string label;
        bool render_label;
        std::vector<std::string> options;
        Height height;
        Core::Size::Width width;
        float x_pos;
    };
}

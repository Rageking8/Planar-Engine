#pragma once

#include "Planar/Engine/Export/ExportMacros.hpp"
#include "Planar/Engine/UI/ImGui/Element/Element.hpp"

#include <string>
#include <vector>

#include "ThirdParty/ImGui/imgui.h"

namespace Planar::Engine::UI::ImGui::Element
{
    class PLANAR_API DropDown : public Element
    {
    public:
        enum class PLANAR_API Height
        {
            SMALL = ImGuiComboFlags_HeightSmall,

            REGULAR = ImGuiComboFlags_HeightRegular,

            LARGE = ImGuiComboFlags_HeightLarge,

            LARGEST = ImGuiComboFlags_HeightLargest,
        };

        DropDown(const std::string& label = "", float width = 0.f,
            const std::vector<std::string>& options = {});

        virtual void render() override;

        unsigned get_selected_index() const;
        std::string get_selected_text() const;

        void set_render_label(bool new_render_label);
        void set_options(const std::vector<std::string>& new_options);
        void set_height(Height new_height);
        void set_width(float new_width);

    private:
        unsigned index;
        std::string label;
        bool render_label;
        std::vector<std::string> options;
        Height height;
        float width;
    };
}

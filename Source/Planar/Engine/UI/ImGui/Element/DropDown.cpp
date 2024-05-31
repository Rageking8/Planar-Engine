#include "Planar/Engine/UI/ImGui/Element/DropDown.hpp"
#include "Planar/Engine/UI/ImGui/ImGui.hpp"
#include "Planar/Engine/Core/Utils/Checks/Assert.hpp"

#include <cstddef>

namespace Planar::Engine::UI::ImGui::Element
{
    DropDown::DropDown(const std::vector<std::string>& options,
        const std::string& label, float width) : index{},
        height{ Height::SMALL }
    {
        this->label = label.empty() ? generate_unique_label() :
            "##" + label;
        set_render_label(!label.empty());

        set_options(options);
        set_width(width);
    }

    void DropDown::render()
    {
        const char* preview = options[index].c_str();

        ::ImGuiComboFlags flags =
            static_cast<ImGuiComboFlags>(height);

        if (render_label)
        {
            ImGui::text(label.substr(2), true);
            ImGui::same_line();
        }

        if (width != 0.f)
        {
            ::ImGui::SetNextItemWidth(width);
        }

        if (::ImGui::BeginCombo(label.c_str(), preview, flags))
        {
            for (std::size_t i = 0; i < options.size(); ++i)
            {
                const bool selected =
                    i == static_cast<std::size_t>(index);
                if (::ImGui::Selectable(options[i].c_str(), selected))
                {
                    index = i;
                }

                if (selected)
                {
                    ::ImGui::SetItemDefaultFocus();
                }
            }

            ::ImGui::EndCombo();
        }
    }

    unsigned DropDown::get_selected_index() const
    {
        return index;
    }

    std::string DropDown::get_selected_text() const
    {
        return options[index];
    }

    void DropDown::set_render_label(bool new_render_label)
    {
        render_label = new_render_label;
    }

    void DropDown::set_options(
        const std::vector<std::string>& new_options)
    {
        PLANAR_ASSERT_NOT_EMPTY(new_options);

        options = new_options;
    }

    void DropDown::set_height(Height new_height)
    {
        height = new_height;
    }

    void DropDown::set_width(float new_width)
    {
        PLANAR_ASSERT(new_width >= 0.f,
            "`new_width` must be greater than or equal to 0");

        width = new_width;
    }
}

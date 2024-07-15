#include "Planar/Engine/UI/ImGui/Element/DropDown.hpp"
#include "Planar/Engine/UI/ImGui/ImGui.hpp"
#include "Planar/Engine/UI/ImGui/Style/StyleVar.hpp"
#include "Planar/Engine/UI/ImGui/Core/Cursor/Cursor.hpp"
#include "Planar/Engine/Core/Utils/Checks/Assert.hpp"

#include <cstddef>
#include <algorithm>

namespace Planar::Engine::UI::ImGui::Element
{
    DropDown::DropDown(const std::string& label,
        Core::Size::Width width, float x_pos,
        const std::vector<std::string>& options) : index{},
        height{ Height::SMALL }, width{ width }, x_pos{ x_pos }
    {
        this->label = label.empty() ? generate_unique_label() :
            "##" + label;
        set_render_label(!label.empty());

        set_options(options);
    }

    void DropDown::render()
    {
        const char* preview = options.empty() ? "" :
            options[index].c_str();

        ::ImGuiComboFlags flags =
            static_cast<ImGuiComboFlags>(height);

        if (render_label)
        {
            ImGui::text(label.substr(2), true);
            ImGui::same_line();
        }

        if (x_pos != 0.f)
        {
            Core::Cursor::set_x(x_pos);
        }

        width.set();

        Style::StyleVar style_var;
        style_var.set_window_padding({ 24.f, 6.f });
        style_var.set_frame_padding({ 12.f, 9.f });
        style_var.set_item_spacing({ 24.f, 14.f });

        if (::ImGui::BeginCombo(label.c_str(), preview, flags))
        {
            for (std::size_t i = 0; i < options.size(); ++i)
            {
                const bool selected =
                    i == static_cast<std::size_t>(index);
                if (::ImGui::Selectable(options[i].c_str(), selected))
                {
                    set_selected_index(i);
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

    void DropDown::set_selected_index(unsigned new_index,
        bool skip_modified)
    {
        PLANAR_ASSERT_RANGE(options, new_index);

        if (!skip_modified && new_index != index)
        {
            set_modified();
        }

        index = new_index;
    }

    void DropDown::set_selected_text(const std::string& new_text,
        bool skip_modified)
    {
        auto result = std::find(options.begin(), options.end(), new_text);

        PLANAR_ASSERT(result != options.end(),
            "`new_text` not found in `options`");

        set_selected_index(std::distance(options.begin(), result),
            skip_modified);
    }

    void DropDown::set_render_label(bool new_render_label)
    {
        render_label = new_render_label;
    }

    void DropDown::set_options(
        const std::vector<std::string>& new_options)
    {
        options = new_options;
        index = 0;
    }

    void DropDown::set_height(Height new_height)
    {
        height = new_height;
    }
}

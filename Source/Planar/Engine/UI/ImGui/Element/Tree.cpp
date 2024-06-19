#include "Planar/Engine/UI/ImGui/Element/Tree.hpp"
#include "Planar/Engine/UI/ImGui/Style/StyleVar.hpp"

#include "ThirdParty/ImGui/imgui.h"

namespace Planar::Engine::UI::ImGui::Element
{
    Tree::Tree(const std::string& label, Math::Size2Df padding,
        float indent_size, float vertical_spacing) :
        label{ label }, padding{ padding },
        indent_size{ indent_size },
        vertical_spacing{ vertical_spacing }, is_leaf{}
    {

    }

    void Tree::render()
    {
        render({}, {}, {});
    }

    void Tree::render(const std::function<void()>& post_callback,
        const std::function<void()>& click_callback,
        const std::function<void()>& content)
    {
        ImGuiTreeNodeFlags tree_flags =
            ImGuiTreeNodeFlags_SpanFullWidth |
            ImGuiTreeNodeFlags_OpenOnArrow |
            ImGuiTreeNodeFlags_OpenOnDoubleClick |
            ImGuiTreeNodeFlags_FramePadding;

        if (is_leaf)
        {
            tree_flags |= ImGuiTreeNodeFlags_Leaf;
            ::ImGui::Unindent();
        }

        Style::StyleVar style_var;
        style_var.set_frame_padding(padding);
        style_var.set_item_spacing({ 0.f, vertical_spacing });
        style_var.set_indent_spacing(indent_size);

        bool tree_open = ::ImGui::TreeNodeEx(label.c_str(), tree_flags);

        if (click_callback && ::ImGui::IsItemClicked())
        {
            click_callback();
        }

        if (post_callback)
        {
            post_callback();
        }

        if (is_leaf)
        {
            ::ImGui::Indent();
        }

        if (tree_open)
        {
            if (content)
            {
                content();
            }

            ::ImGui::TreePop();
        }
    }

    std::string Tree::get_label() const
    {
        return label;
    }

    Math::Size2Df Tree::get_padding() const
    {
        return padding;
    }

    float Tree::get_indent_size() const
    {
        return indent_size;
    }

    float Tree::get_vertical_spacing() const
    {
        return vertical_spacing;
    }

    bool Tree::get_is_leaf() const
    {
        return is_leaf;
    }

    void Tree::set_label(const std::string& new_label)
    {
        label = new_label;
    }

    void Tree::set_padding(Math::Size2Df new_padding)
    {
        padding = new_padding;
    }

    void Tree::set_indent_size(float new_indent_size)
    {
        indent_size = new_indent_size;
    }

    void Tree::set_vertical_spacing(float new_vertical_spacing)
    {
        vertical_spacing = new_vertical_spacing;
    }

    void Tree::set_is_leaf(bool new_is_leaf)
    {
        is_leaf = new_is_leaf;
    }
}

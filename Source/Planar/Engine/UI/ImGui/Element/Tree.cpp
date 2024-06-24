#include "Planar/Engine/UI/ImGui/Element/Tree.hpp"
#include "Planar/Engine/UI/ImGui/Style/StyleVar.hpp"
#include "Planar/Engine/UI/ImGui/Core/Cursor/Cursor.hpp"
#include "Planar/Engine/UI/ImGui/Core/Cursor/CursorScope.hpp"
#include "Planar/Engine/UI/ImGui/ImGui.hpp"
#include "Planar/Engine/Math/Pos2D.hpp"

#include "ThirdParty/ImGui/imgui.h"

namespace Planar::Engine::UI::ImGui::Element
{
    Tree::Tree(Math::Size2Df padding, float indent_size,
        float vertical_spacing, float pre_header_left_padding,
        float pre_header_right_padding, bool is_framed,
        bool default_open, const std::string& text,
        const std::string& id) : padding{ padding },
        indent_size{ indent_size }, vertical_spacing{ vertical_spacing },
        pre_header_left_padding{ pre_header_left_padding },
        pre_header_right_padding{ pre_header_right_padding },
        is_framed{ is_framed }, default_open{ default_open },
        text{ text }, id{ id }, is_leaf{}
    {

    }

    void Tree::render()
    {
        render({}, {}, {});
    }

    void Tree::render(const std::function<void()>& post_callback,
        const std::function<void()>& click_callback,
        const std::function<void()>& content,
        const std::function<void()>& pre_header)
    {
        ImGuiTreeNodeFlags tree_flags =
            ImGuiTreeNodeFlags_SpanFullWidth |
            ImGuiTreeNodeFlags_OpenOnArrow |
            ImGuiTreeNodeFlags_OpenOnDoubleClick |
            ImGuiTreeNodeFlags_AllowOverlap |
            ImGuiTreeNodeFlags_FramePadding;

        if (is_leaf)
        {
            tree_flags |= ImGuiTreeNodeFlags_Leaf;
            ::ImGui::Unindent();
        }

        tree_flags |= is_framed ? ImGuiTreeNodeFlags_Framed : 0;
        tree_flags |= default_open ? ImGuiTreeNodeFlags_DefaultOpen : 0;

        Style::StyleVar style_var;
        style_var.set_frame_padding(padding);
        style_var.set_item_spacing({ 0.f, vertical_spacing });
        style_var.set_indent_spacing(indent_size);

        Math::Pos2Df pre_header_end_pos{};

        if (pre_header)
        {
            Core::Cursor::CursorScope cursor_scope;

            Core::Cursor::move_x(pre_header_left_padding);

            pre_header();

            pre_header_end_pos = Core::Cursor::get();
            pre_header_end_pos.x += pre_header_right_padding;
        }

        bool tree_open = ::ImGui::TreeNodeEx(("##" + text + id).
            c_str(), tree_flags);
        bool clicked = ::ImGui::IsItemClicked();
        same_line();

        if (pre_header)
        {
            Core::Cursor::set(pre_header_end_pos);
        }

        ImGui::text(text);

        if (click_callback && clicked)
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

    std::string Tree::get_text() const
    {
        return text;
    }

    std::string Tree::get_id() const
    {
        return id;
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

    void Tree::set_text(const std::string& new_text)
    {
        text = new_text;
    }

    void Tree::set_id(const std::string& new_id)
    {
        id = new_id;
    }

    void Tree::set_padding(Math::Size2Df new_padding)
    {
        padding = new_padding;
    }

    void Tree::set_pre_header_left_padding(
        float new_pre_header_left_padding)
    {
        pre_header_left_padding = new_pre_header_left_padding;
    }

    void Tree::set_pre_header_right_padding(
        float new_pre_header_right_padding)
    {
        pre_header_right_padding = new_pre_header_right_padding;
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

    void Tree::set_is_framed(bool new_is_framed)
    {
        is_framed = new_is_framed;
    }

    void Tree::set_default_open(bool new_default_open)
    {
        default_open = new_default_open;
    }
}

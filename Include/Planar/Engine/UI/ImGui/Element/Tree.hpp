#pragma once

#include "Planar/Engine/Export/ExportMacros.hpp"
#include "Planar/Engine/UI/ImGui/Element/Element.hpp"
#include "Planar/Engine/Math/Size2D.hpp"
#include "Planar/Engine/Math/Pos2D.hpp"

#include <string>
#include <functional>

namespace Planar::Engine::UI::ImGui::Element
{
    class PLANAR_API Tree : public Element
    {
    public:
        Tree(Math::Size2Df padding = { 10.f, 0.f },
            float indent_size = 24.f, float vertical_spacing = 10.f,
            float pre_header_left_padding = 0.f,
            float pre_header_right_padding = 0.f, bool is_framed = false,
            bool default_open = false, const std::string& text = "",
            const std::string& id = "");

        virtual void render() override;
        void render(const std::function<void()>& left_click_callback,
            const std::function<void()>& right_click_callback,
            const std::function<void()>& content,
            const std::function<void()>& pre_header = {});

        std::string get_text() const;
        std::string get_id() const;
        Math::Size2Df get_padding() const;
        float get_indent_size() const;
        float get_vertical_spacing() const;
        bool get_is_leaf() const;

        void set_text(const std::string& new_text);
        void set_id(const std::string& new_id);
        void set_padding(Math::Size2Df new_padding);
        void set_pre_header_left_padding(
            float new_pre_header_left_padding);
        void set_pre_header_right_padding(
            float new_pre_header_right_padding);
        void set_indent_size(float new_indent_size);
        void set_vertical_spacing(float new_vertical_spacing);
        void set_is_leaf(bool new_is_leaf);
        void set_is_framed(bool new_is_framed);
        void set_default_open(bool new_default_open);
        void set_drag_source(const std::string& type,
            const std::string* value);
        void clear_drag_source();

    private:
        std::string text;
        std::string id;
        Math::Size2Df padding;
        float pre_header_left_padding;
        float pre_header_right_padding;
        float indent_size;
        float vertical_spacing;
        bool is_leaf;
        bool is_framed;
        bool default_open;
        std::string drag_source_type;
        const std::string* drag_source_value;

        int generate_flags() const;
        Math::Pos2Df handle_pre_header(
            const std::function<void()>& pre_header);
    };
}

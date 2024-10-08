#pragma once

#include "Planar/Engine/Export/ExportMacros.hpp"
#include "Planar/Engine/Math/Pos2D.hpp"
#include "Planar/Engine/Math/Size2D.hpp"

#include "ThirdParty/glad/gl.h"

#include <string>
#include <optional>

struct ImVec2;

namespace Planar::Engine::UI::ImGui
{
    PLANAR_API void set_ini_filename(
        const std::string& ini_filename = "");

    PLANAR_API void set_config_flags(int config_flags);

    PLANAR_API void set_drag_click_to_input(bool drag_click_to_input);

    PLANAR_API void save_ini();

    PLANAR_API void load_ini_from_string(
        const std::string& ini_file);

    PLANAR_API void reset_style();

    PLANAR_API void scale_ui(int factor);

    PLANAR_API float get_font_size();

    PLANAR_API void set_scrollbar_size(float new_scrollbar_size);

    PLANAR_API Math::Size2Df get_main_viewport_size();

    PLANAR_API Math::Size2Df get_window_size();

    PLANAR_API Math::Pos2Df get_window_position();

    PLANAR_API Math::Size2Df get_content_region_avail();

    PLANAR_API Math::Pos2Df get_cursor_screen_pos();

    PLANAR_API Math::Size2Df get_item_spacing();

    PLANAR_API Math::Pos2Df get_item_rect_max();

    PLANAR_API std::string generate_unique_label();

    PLANAR_API void dummy(Math::Size2Df size = {});

    PLANAR_API void text(const std::string& text,
        bool align_text_to_frame_padding = false);

    PLANAR_API void text_wrapped(const std::string& text,
        float wrap_width = -1.f);

    PLANAR_API bool input_text(const std::string& label,
        std::string& text, int flags = 0);
    PLANAR_API bool input_text(const std::string& label,
        const std::string& placeholder, std::string& text, int flags = 0);

    PLANAR_API void image(GLuint texture, Math::Size2Df size,
        bool flip_y = false);

    PLANAR_API void newline(unsigned count = 1);

    PLANAR_API void same_line();

    PLANAR_API void separator(float extra_height = -1.f);

    PLANAR_API bool is_item_hovered();

    PLANAR_API bool is_left_mouse_double_clicked();

    PLANAR_API ImVec2 calc_uv0(bool flip_y);

    PLANAR_API ImVec2 calc_uv1(bool flip_y);

    PLANAR_API Math::Pos2Df get_mouse_pos();

    PLANAR_API void drag_drop_source(const std::string& type,
        const std::string* value);

    PLANAR_API std::optional<std::string> drag_drop_target(
        const std::string& type);
}

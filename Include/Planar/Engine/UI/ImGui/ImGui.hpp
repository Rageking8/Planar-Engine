#pragma once

#include "Planar/Engine/Export/ExportMacros.hpp"
#include "Planar/Engine/Math/Pos2D.hpp"
#include "Planar/Engine/Math/Size2D.hpp"

#include "ThirdParty/glad/gl.h"

#include <string>

namespace Planar::Engine::UI::ImGui
{
    PLANAR_API void set_ini_filename(
        const std::string& ini_filename = "");

    PLANAR_API void set_config_flags(int config_flags);

    PLANAR_API void save_ini();

    PLANAR_API void load_ini_from_string(
        const std::string& ini_file);

    PLANAR_API void reset_style();

    PLANAR_API void scale_ui(int factor);

    PLANAR_API void set_scrollbar_size(float new_scrollbar_size);

    PLANAR_API Planar::Engine::Math::Pos2Df get_window_position();

    PLANAR_API Planar::Engine::Math::Size2Df
        get_window_content_region_max();

    PLANAR_API Planar::Engine::Math::Size2Df get_item_spacing();

    PLANAR_API Planar::Engine::Math::Pos2Df get_item_rect_max();

    PLANAR_API std::string generate_unique_label();

    PLANAR_API void text(const std::string& text);

    PLANAR_API void text_wrapped(const std::string& text,
        float wrap_width = -1.f);

    PLANAR_API bool button(const std::string& name,
        Planar::Engine::Math::Size2Df size = {});
    PLANAR_API bool button(const std::string& name, GLuint texture,
        Planar::Engine::Math::Size2Df size);

    PLANAR_API void input_text(const std::string& label,
        std::string& text);
    PLANAR_API void input_text(const std::string& label,
        const std::string& placeholder, std::string& text);

    PLANAR_API void image(GLuint texture,
        Planar::Engine::Math::Size2Df size);

    PLANAR_API void newline(unsigned count = 1);

    PLANAR_API void same_line();

    PLANAR_API void dock_space_over_viewport();

    PLANAR_API float get_cursor_x();

    PLANAR_API float get_cursor_y();

    PLANAR_API void move_cursor(Planar::Engine::Math::Size2Df delta);

    PLANAR_API void move_cursor_x(float delta);

    PLANAR_API void move_cursor_y(float delta);

    PLANAR_API bool is_item_hovered();

    PLANAR_API bool is_left_mouse_double_clicked();
}

#pragma once

#include "Planar/Engine/Export/ExportMacros.hpp"
#include "Planar/Engine/UI/ImGui//Core//Cursor/MoveMode.hpp"
#include "Planar/Engine/Math/Size2D.hpp"
#include "Planar/Engine/Math/Pos2D.hpp"

namespace Planar::Engine::UI::ImGui::Core::Cursor
{
    PLANAR_API void set_y_bottom_window(float y_offset = 0.f,
        bool add_dummy = true);

    PLANAR_API void set_y_bottom_viewport(float y_offset = 0.f,
        bool add_dummy = true);

    PLANAR_API void set_x(float new_x, bool add_dummy = true);

    PLANAR_API void set_y(float new_y, bool add_dummy = true);

    PLANAR_API void set(Math::Pos2Df new_pos, bool add_dummy = true);

    PLANAR_API float get_x();

    PLANAR_API float get_y();

    PLANAR_API Math::Pos2Df get();

    PLANAR_API void move(MoveMode mode, Math::Size2Df delta,
        bool same_line = true);

    PLANAR_API void move_x(MoveMode mode, float delta,
        bool same_line = true);

    PLANAR_API void move_y(MoveMode mode, float delta,
        bool same_line = true);
}

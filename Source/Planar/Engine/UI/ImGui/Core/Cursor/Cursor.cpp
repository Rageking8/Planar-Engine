#include "Planar/Engine/UI/ImGui/Core/Cursor/Cursor.hpp"

#include "ThirdParty/ImGui/imgui.h"

namespace Planar::Engine::UI::ImGui::Core::Cursor
{
    void set_y_bottom_window(float y_offset)
    {
        set_y(::ImGui::GetWindowHeight() -
            ::ImGui::GetFrameHeightWithSpacing() + y_offset);
    }

    void set_y_bottom_viewport(float y_offset)
    {
        set_y(::ImGui::GetMainViewport()->Size.y + y_offset);
    }

    void set_x(float new_x)
    {
        ::ImGui::SetCursorPosX(new_x);
    }

    void set_y(float new_y)
    {
        ::ImGui::SetCursorPosY(new_y);
    }

    float get_x()
    {
        return ::ImGui::GetCursorPosX();
    }

    float get_y()
    {
        return ::ImGui::GetCursorPosY();
    }

    void move(Math::Size2Df delta)
    {
        move_x(delta.width);
        move_y(delta.height);
    }

    void move_x(float delta)
    {
        set_x(get_x() + delta);
    }

    void move_y(float delta)
    {
        set_y(get_y() + delta);
    }
}

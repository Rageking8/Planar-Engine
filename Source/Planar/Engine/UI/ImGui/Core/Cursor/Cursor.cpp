#include "Planar/Engine/UI/ImGui/Core/Cursor/Cursor.hpp"
#include "Planar/Engine/UI/ImGui/ImGui.hpp"

#include "ThirdParty/ImGui/imgui.h"

namespace Planar::Engine::UI::ImGui::Core::Cursor
{
    void set_y_bottom_window(float y_offset, bool add_dummy)
    {
        set_y(::ImGui::GetWindowHeight() -
            ::ImGui::GetFrameHeightWithSpacing() + y_offset,
            add_dummy);
    }

    void set_y_bottom_viewport(float y_offset, bool add_dummy)
    {
        set_y(::ImGui::GetMainViewport()->Size.y + y_offset,
            add_dummy);
    }

    void set_x(float new_x, bool add_dummy)
    {
        ::ImGui::SetCursorPosX(new_x);

        if (add_dummy)
        {
            ImGui::dummy();
            ImGui::same_line();
        }
    }

    void set_y(float new_y, bool add_dummy)
    {
        ::ImGui::SetCursorPosY(new_y);

        if (add_dummy)
        {
            ImGui::dummy();
            ImGui::same_line();
        }
    }

    void set(Math::Pos2Df new_pos, bool add_dummy)
    {
        set_x(new_pos.x, add_dummy);
        set_y(new_pos.y, add_dummy);
    }

    float get_x()
    {
        return ::ImGui::GetCursorPosX();
    }

    float get_y()
    {
        return ::ImGui::GetCursorPosY();
    }

    Math::Pos2Df get()
    {
        return { get_x(), get_y() };
    }

    void move(MoveMode mode, Math::Size2Df delta, bool same_line)
    {
        switch (mode)
        {
        case MoveMode::DUMMY:
            ImGui::dummy(delta);
            break;

        case MoveMode::SET_CURSOR:
            set({ get_x() + delta.width, get_y() + delta.height },
                false);
            break;
        }

        if (same_line)
        {
            ImGui::same_line();
        }
    }

    void move_x(MoveMode mode, float delta, bool same_line)
    {
        move(mode, { delta, 0.f }, same_line);
    }

    void move_y(MoveMode mode, float delta, bool same_line)
    {
        move(mode, { 0.f, delta }, same_line);
    }
}

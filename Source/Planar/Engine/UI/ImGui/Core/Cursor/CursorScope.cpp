#include "Planar/Engine/UI/ImGui/Core/Cursor/CursorScope.hpp"
#include "Planar/Engine/UI/ImGui/Core/Cursor/Cursor.hpp"
#include "Planar/Engine/UI/ImGui/Core/Cursor/MoveMode.hpp"
#include "Planar/Engine/UI/ImGui/ImGui.hpp"

namespace Planar::Engine::UI::ImGui::Core::Cursor
{
    CursorScope::CursorScope(Mode mode, float x_delta,
        float y_delta) : mode{ mode }, restore_x{}, restore_y{}
    {
        switch (mode)
        {
        case Mode::ABSOLUTE:
            restore_x = get_x();
            restore_y = get_y();
            break;

        case Mode::RELATIVE:
            move(MoveMode::SET_CURSOR, { x_delta, y_delta },
                false);
            restore_x = -x_delta;
            restore_y = -y_delta;
            break;
        }
    }

    CursorScope::~CursorScope()
    {
        switch (mode)
        {
        case Mode::ABSOLUTE:
            set({ restore_x, restore_y });
            break;

        case Mode::RELATIVE:
            same_line();
            move(MoveMode::SET_CURSOR, { restore_x, restore_y },
                false);
            break;
        }
    }
}

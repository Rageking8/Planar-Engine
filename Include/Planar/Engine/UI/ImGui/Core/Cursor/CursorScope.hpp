#pragma once

#include "Planar/Engine/Export/ExportMacros.hpp"

namespace Planar::Engine::UI::ImGui::Core::Cursor
{
    // Scope class used to save or move cursor position in
    // the constructor and restore any changes in the destructor
    class PLANAR_API CursorScope
    {
    public:
        enum class Mode
        {
            // Save the absolute cursor position for restoration
            ABSOLUTE,

            // Move cursor by `x_delta` and `y_delta`, restored
            // by moving the cursor by the inverse
            RELATIVE,
        };

        CursorScope(Mode mode = Mode::ABSOLUTE,
            float x_delta = 0.f, float y_delta = 0.f);
        ~CursorScope();

    private:
        Mode mode;
        float restore_x;
        float restore_y;
    };
}

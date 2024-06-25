#pragma once

#include "Planar/Engine/Export/ExportMacros.hpp"

namespace Planar::Engine::UI::ImGui::Core::Size
{
    class PLANAR_API Width
    {
    public:
        enum class WidthMode
        {
            DEFAULT,

            FIXED,

            FILL,
        };

        Width(WidthMode mode = WidthMode::DEFAULT,
            float width = 0.f, float fill_offset_left = 0.f,
            float fill_offset_right = 0.f);

        void set() const;

        void set_mode(WidthMode new_mode);
        void set_width(float new_width);
        void set_fill_offset_left(float new_fill_offset_left);
        void set_fill_offset_right(float new_fill_offset_right);

    private:
        WidthMode mode;
        float width;
        float fill_offset_left;
        float fill_offset_right;
    };
}

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
            float width = 0.f, float fill_offset = 0.f);

        void set() const;

        void set_mode(WidthMode new_mode);
        void set_width(float new_width);
        void set_fill_offset(float new_fill_offset);

    private:
        WidthMode mode;
        float width;
        float fill_offset;
    };
}

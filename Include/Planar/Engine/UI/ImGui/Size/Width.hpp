#pragma once

#include "Planar/Engine/Export/ExportMacros.hpp"

namespace Planar::Engine::UI::ImGui::Size
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
            float width = 0.f);

        void set() const;

        void set_mode(WidthMode new_mode);
        void set_width(float new_width);

    private:
        WidthMode mode;
        float width;
    };
}

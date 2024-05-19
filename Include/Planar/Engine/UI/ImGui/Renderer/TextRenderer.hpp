#pragma once

#include "Planar/Engine/Export/ExportMacros.hpp"

#include <string>
#include <vector>
#include <utility>

namespace Planar::Engine::UI::ImGui::Renderer
{
    class PLANAR_API TextRenderer
    {
    public:
        TextRenderer();

        void render_center_truncate(const std::string& text,
            float width, float line_delta, unsigned lines,
            const std::string& truncate_text = "...");

    private:
        std::pair<std::vector<std::pair<std::string, float>>, bool>
            split_text(const std::string& text, float width,
            unsigned lines);
    };
}
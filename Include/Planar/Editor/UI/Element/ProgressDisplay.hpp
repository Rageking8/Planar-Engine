#pragma once

#include "Planar/Engine/UI/ImGui/Element/Element.hpp"
#include "Planar/Engine/UI/ImGui/Element/ProgressBar.hpp"
#include "Planar/Engine/UI/ImGui/Renderer/TextRenderer.hpp"

#include <string>

namespace Planar::Editor::UI::Element
{
    class ProgressDisplay :
        public Engine::UI::ImGui::Element::Element
    {
    public:
        enum class LayoutMode
        {
            VIEWPORT,

            WINDOW,
        };

        ProgressDisplay(LayoutMode layout_mode = LayoutMode::VIEWPORT);

        virtual void render() override;

        void set_layout_mode(LayoutMode new_layout_mode);
        void set_text(const std::string& new_text);
        void set_y_offset(float new_y_offset);
        void increment(unsigned delta = 1);
        void reset(unsigned max);

    private:
        LayoutMode layout_mode;

        Engine::UI::ImGui::Element::ProgressBar progress_bar;
        Engine::UI::ImGui::Renderer::TextRenderer text_renderer;

        std::string text;
        float y_offset;
    };
}

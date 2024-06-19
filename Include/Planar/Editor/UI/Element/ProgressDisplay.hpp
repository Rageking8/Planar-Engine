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
        ProgressDisplay();

        virtual void render() override;

        void set_text(const std::string& new_text);
        void increment(unsigned delta = 1);
        void reset(unsigned max);

    private:
        Engine::UI::ImGui::Element::ProgressBar progress_bar;
        Engine::UI::ImGui::Renderer::TextRenderer text_renderer;

        std::string text;
    };
}

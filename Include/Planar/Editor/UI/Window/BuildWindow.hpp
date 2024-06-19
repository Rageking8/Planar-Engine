#pragma once

#include "Planar/Editor/UI/Window/EditorWindow.hpp"
#include "Planar/Engine/UI/ImGui/Element/InputField.hpp"
#include "Planar/Engine/UI/ImGui/Element/Button.hpp"
#include "Planar/Engine/UI/ImGui/Element/DropDown.hpp"
#include "Planar/Engine/UI/ImGui/Element/Checkbox.hpp"
#include "Planar/Engine/UI/ImGui/Element/IntSlider.hpp"
#include "Planar/Editor/UI/Element/ProgressDisplay.hpp"

#include <string>

namespace Planar::Editor::UI::Window
{
    class BuildWindow : public EditorWindow
    {
    public:
        BuildWindow();

        void init();
        void update();

        virtual void render_window() override;

    private:
        Engine::UI::ImGui::Element::InputField build_directory_input;
        Engine::UI::ImGui::Element::Button browse_button;
        Engine::UI::ImGui::Element::DropDown target_drop_down;
        Engine::UI::ImGui::Element::Checkbox show_console_window_checkbox;
        Engine::UI::ImGui::Element::Checkbox use_compression_checkbox;
        Engine::UI::ImGui::Element::IntSlider compression_level_slider;
        Engine::UI::ImGui::Element::Button build_button;
        UI::Element::ProgressDisplay progress_display;

        bool pending_browse;
        bool pending_build;
        bool build_mode;

        void browse();
        void build();

        void enter_build_mode(unsigned max);
        void build_progress_callback(unsigned amount,
            const std::string& text);
    };
}

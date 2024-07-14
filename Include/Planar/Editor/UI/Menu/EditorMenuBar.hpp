#pragma once

#include "Planar/Editor/UI/Element/PlayStopToggle.hpp"
#include "Planar/Editor/Core/Utils/Macros/DeclarationMacros.hpp"

#include <string>

PLANAR_EDITOR_FORWARD_DECLARE_CLASS(Core, Editor)
PLANAR_EDITOR_FORWARD_DECLARE_CLASS(UI::Window::Core,
    EditorWindowManager)

namespace Planar::Editor::UI::Menu
{
    class EditorMenuBar
    {
    public:
        EditorMenuBar(Core::Editor* editor,
            Window::Core::EditorWindowManager& window_manager);

        void render();

        Element::PlayStopToggle& get_play_stop_toggle();

    private:
        Core::Editor* editor;
        Window::Core::EditorWindowManager& window_manager;
        Element::PlayStopToggle play_stop_toggle;

        void window_menu_item(const std::string& name,
            const std::string& label = "",
            bool reset_first_render = false);

        template <typename ComponentT>
        void add_component_menu_item();
    };
}

#pragma once

#include "Planar/Editor/UI/Window/EditorWindow.hpp"
#include "Planar/Editor/Core/Utils/Macros/DeclarationMacros.hpp"
#include "Planar/Engine/UI/ImGui/Element/Button.hpp"

PLANAR_EDITOR_FORWARD_DECLARE_CLASS(Core, Editor)

namespace Planar::Editor::UI::Window
{
    class SettingsWindow : public EditorWindow
    {
    public:
        SettingsWindow(Core::Editor* editor);

        virtual void render_window() override;

        bool get_pending_restore_default_layout(bool reset = true);

    private:
        bool pending_restore_default_layout;

        Planar::Engine::UI::ImGui::Element::Button
            restore_default_layout_button;
    };
}

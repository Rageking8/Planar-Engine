#pragma once

#include "Planar/Editor/UI/Window/EditorWindow.hpp"
#include "Planar/Engine/UI/ImGui/Element/InputField.hpp"
#include "Planar/Engine/UI/ImGui/Element/DropDown.hpp"
#include "Planar/Engine/UI/ImGui/Element/Button/Button.hpp"
#include "Planar/Editor/Core/Utils/Macros/DeclarationMacros.hpp"

#include <string>

PLANAR_EDITOR_FORWARD_DECLARE_CLASS(Core, Editor)

namespace Planar::Editor::UI::Window
{
    class AssetImportWindow : public EditorWindow
    {
    public:
        AssetImportWindow(Core::Editor* editor);

        void init();
        void update();

        virtual void render_window() override;

    private:
        Engine::UI::ImGui::Element::InputField asset_path_input;
        Engine::UI::ImGui::Element::Button::Button browse_button;
        Engine::UI::ImGui::Element::DropDown import_type_dropdown;
        Engine::UI::ImGui::Element::Button::Button import_button;

        bool pending_browse;
        bool pending_import;
        std::string asset_extension;

        void browse();
        void import();

        void update_import_options();
    };
}

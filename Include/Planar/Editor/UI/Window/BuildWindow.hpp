#pragma once

#include "Planar/Editor/UI/Window/EditorWindow.hpp"
#include "Planar/Engine/UI/ImGui/Element/InputField.hpp"
#include "Planar/Engine/UI/ImGui/Element/Button.hpp"

#include <filesystem>

namespace Planar::Editor::UI::Window
{
    class BuildWindow : public EditorWindow
    {
    public:
        BuildWindow();

        void init();
        void update();

        virtual void render_window() override;

        void set_root_path(const std::filesystem::path& new_root_path);

    private:
        std::filesystem::path root_path;

        Engine::UI::ImGui::Element::InputField build_directory_input;
        Engine::UI::ImGui::Element::Button browse_button;
        Engine::UI::ImGui::Element::Button build_button;

        bool pending_browse;
        bool pending_build;

        void browse();
        void build();
    };
}

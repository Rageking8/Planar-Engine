#pragma once

#include "Planar/Editor/UI/Window/EditorWindow.hpp"
#include "Planar/Engine/UI/ImGui/Element/Tree.hpp"

namespace Planar::Editor::UI::Window
{
    class HierarchyWindow : public EditorWindow
    {
    public:
        HierarchyWindow();

        virtual void render_window() override;

    private:
        Engine::UI::ImGui::Element::Tree current_scene_tree;
    };
}

#pragma once

#include "Planar/Engine/Scene/Scene.hpp"
#include "Planar/Engine/UI/ImGui/ImGuiWindow.hpp"

namespace Planar::Editor::Scene
{
    class EditorScene :
        public Planar::Engine::Scene::Scene
    {
    public:
        EditorScene();

        virtual void init() override;
        virtual void render() override;

    private:
        Planar::Engine::UI::ImGui::ImGuiWindow inspector_window;
    };
}

#include "Planar/Editor/Scene/SelectProjectScene.hpp"
#include "Planar/Engine/UI/ImGui/ImGui.hpp"
#include "Planar/Engine/UI/ImGui/ImGuiWindow.hpp"

namespace Planar::Editor::Scene
{
    void SelectProjectScene::render()
    {
        Planar::Engine::UI::ImGui::ImGuiWindow window("Select Project");
        Planar::Engine::UI::ImGui::text("Select Project");
    }
}

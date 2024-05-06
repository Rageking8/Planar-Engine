#include "Planar/Editor/Scene/EditorScene.hpp"
#include "Planar/Engine/UI/ImGui/ImGuiWindow.hpp"

namespace Planar::Editor::Scene
{
    EditorScene::EditorScene()
    {

    }

    void EditorScene::render()
    {
        using namespace Planar::Engine::UI;

        ImGui::ImGuiWindow inspector_window("Inspector");
    }
}

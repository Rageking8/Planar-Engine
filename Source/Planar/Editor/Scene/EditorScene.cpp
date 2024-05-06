#include "Planar/Editor/Scene/EditorScene.hpp"

namespace Planar::Editor::Scene
{
    EditorScene::EditorScene()
    {

    }

    void EditorScene::init()
    {
        using namespace Planar::Engine::UI;

        inspector_window.set_name("Inspector");
        inspector_window.set_size({ { 300.f, 550.f } });
    }

    void EditorScene::render()
    {
        using namespace Planar::Engine::UI;

        {
            auto inspector_window_scope = inspector_window.render();
        }
    }
}

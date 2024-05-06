#include "Planar/Editor/Scene/EditorScene.hpp"

namespace Planar::Editor::Scene
{
    EditorScene::EditorScene()
    {

    }

    void EditorScene::init()
    {
        using namespace Planar::Engine::UI;

        hierarchy_window.set_name("Hierarchy");
        hierarchy_window.set_size({ { 300.f, 550.f } });

        inspector_window.set_name("Inspector");
        inspector_window.set_size({ { 300.f, 550.f } });

        content_window.set_name("Content");
        content_window.set_size({ { 600.f, 300.f } });
    }

    void EditorScene::render()
    {
        using namespace Planar::Engine::UI;

        {
            auto hierarchy_window_scope = hierarchy_window.render();
        }

        {
            auto inspector_window_scope = inspector_window.render();
        }

        {
            auto content_window_scope = content_window.render();
        }
    }
}

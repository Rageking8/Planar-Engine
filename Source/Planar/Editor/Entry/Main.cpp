#include "Planar/Engine/Core/Application.hpp"
#include "Planar/Editor/Scene/SelectProjectScene.hpp"

#include <memory>

int main()
{
    Planar::Engine::Core::Application application;

    if (!application.init())
    {
        return -1;
    }

    application.load_scene(
        std::make_unique<Planar::Editor::Scene::SelectProjectScene>());
    application.run();
}

#include "Planar/Engine/Export/Planar/Engine/Scene/Scene.hpp"
#include "Planar/Engine/Core/Application.hpp"
#include "Planar/Engine/Scene/Scene.hpp"

PLANAR_EXPORT_FUNCTION_PROTOTYPE(Planar_Engine_Scene_Scene_construct,
    void*, void* application, const char* scene_name,
    const char* asset_string)
{
    return new Planar::Engine::Scene::Scene(
        static_cast<Planar::Engine::Core::Application*>(application),
        scene_name, asset_string);
}

PLANAR_EXPORT_DEFINE_DESTRUCT(Planar_Engine_Scene_Scene,
    Planar::Engine::Scene::Scene)

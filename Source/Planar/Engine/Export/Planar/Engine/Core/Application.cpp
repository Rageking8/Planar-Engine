#include "Planar/Engine/Export/Planar/Engine/Core/Application.hpp"
#include "Planar/Engine/Core/Application.hpp"
#include "Planar/Engine/Scene/Scene.hpp"

PLANAR_EXPORT_FUNCTION_PROTOTYPE(Planar_Engine_Core_Application_construct,
    void*, const char* window_name, Planar::Engine::Math::Size2Di window_size,
    bool maximize, Planar::Engine::Graphics::SupportedGraphicsAPI
    graphics_api)
{
    return new Planar::Engine::Core::Application(window_name, window_size,
        maximize, graphics_api);
}

PLANAR_EXPORT_DEFINE_DESTRUCT(Planar_Engine_Core_Application,
    Planar::Engine::Core::Application)

PLANAR_EXPORT_DEFINE_HANDLE_FUNCTION(Planar_Engine_Core_Application, init,
    bool, Planar::Engine::Core::Application)
PLANAR_EXPORT_DEFINE_HANDLE_FUNCTION(Planar_Engine_Core_Application, run,
    Planar::Engine::Core::Application)
PLANAR_EXPORT_DEFINE_HANDLE_FUNCTION(Planar_Engine_Core_Application,
    load_scene, void* scene, static_cast<Planar::Engine::Scene::Scene*>(
    scene), Planar::Engine::Core::Application)
PLANAR_EXPORT_DEFINE_HANDLE_FUNCTION(Planar_Engine_Core_Application,
    get_asset_database, void*, Planar::Engine::Core::Application)

#include "Planar/Engine/Graphics/OpenGL/Core/ObjectManager.hpp"

namespace Planar::Engine::Graphics::OpenGL::Core
{
    ObjectManager::ObjectManager()
    {

    }

    void ObjectManager::init()
    {
        quad.init();
    }

    Render::Quad& ObjectManager::get_quad()
    {
        return quad;
    }
}

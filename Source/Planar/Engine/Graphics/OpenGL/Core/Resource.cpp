#include "Planar/Engine/Graphics/OpenGL/Core/Resource.hpp"

namespace Planar::Engine::Graphics::OpenGL::Core
{
    Resource::Resource(FreeFunction free_function) : id{},
        free_function{ free_function }
    {

    }

    Resource::~Resource()
    {
        free_function(id);
    }

    void Resource::free()
    {
        free_function(id);

        id = 0;
    }

    GLuint Resource::get_id() const
    {
        return id;
    }
}

#include "Planar/Engine/Core/GLFW/GLFW.hpp"

namespace Planar::Engine::Core::GLFW
{
    template <typename T>
    T* get_callback_pointer(const std::string& name)
    {
        return static_cast<T*>(get_callback_pointer(name));
    }
}

#include "Planar/Engine/Core/GLFW/GLFW.hpp"

#include <unordered_map>

namespace Planar::Engine::Core::GLFW
{
    namespace
    {
        std::unordered_map<std::string, void*> callback_pointer_map;
    }

    void add_callback_pointer(const std::string& name, void* pointer)
    {
        callback_pointer_map[name] = pointer;
    }

    void* get_callback_pointer(const std::string& name)
    {
        return callback_pointer_map[name];
    }
}

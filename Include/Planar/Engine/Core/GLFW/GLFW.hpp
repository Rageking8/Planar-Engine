#pragma once

#include "Planar/Engine/Export/ExportMacros.hpp"

#include <string>

namespace Planar::Engine::Core::GLFW
{
    PLANAR_API void add_callback_pointer(const std::string& name,
        void* pointer);

    PLANAR_API void* get_callback_pointer(const std::string& name);

    template <typename T>
    T* get_callback_pointer(const std::string& name);
}

#include "Planar/Engine/Core/GLFW/GLFW.tpp"

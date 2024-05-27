#pragma once

namespace Planar::Engine::Graphics::OpenGL::Core
{
    // Mode used to create and modify OpenGL objects
    enum class ObjectHandlingMode
    {
        // Prefer using the older binding method to
        // perform creation and modifications
        BIND,

        // Prefer using the newer direct state access
        // method to perform creation and modifications
        DSA,
    };
}

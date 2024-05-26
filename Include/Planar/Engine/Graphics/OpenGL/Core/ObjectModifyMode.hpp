#pragma once

namespace Planar::Engine::Graphics::OpenGL::Core
{
    enum class ObjectModifyMode
    {
        // Bind object to OpenGL context
        // before performing modifications
        BIND,

        // Use new direct state access method
        // to perform modifications
        DSA,
    };
}

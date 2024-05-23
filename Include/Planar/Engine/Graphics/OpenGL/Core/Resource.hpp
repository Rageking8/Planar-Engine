#pragma once

#include "Planar/Engine/Export/ExportMacros.hpp"
#include "Planar/Engine/Core/Utils/Macros/TypeHelperMacros.hpp"

#include "ThirdParty/glad/gl.h"

namespace Planar::Engine::Graphics::OpenGL::Core
{
    class PLANAR_API Resource
    {
    public:
        using FreeFunction = void(*)(GLuint);

        Resource(FreeFunction free_function);
        virtual ~Resource() = 0;

        PLANAR_DELETE_COPY_FUNCTIONS(Resource)

        void free();

        GLuint get_id() const;

    protected:
        GLuint id;

    private:
        FreeFunction free_function;
    };
}

#pragma once

#include "Planar/Engine/Export/ExportMacros.hpp"
#include "Planar/Engine/Core/Utils/EnumClass/EnumClassBase.hpp"

namespace Planar::Engine::Graphics
{
    enum class SupportedGraphicsAPIBacking
    {
        OPENGL_4_6,
    };

    class PLANAR_API SupportedGraphicsAPI :
        public Core::Utils::EnumClass::EnumClassBase<
        SupportedGraphicsAPIBacking>
    {
    public:
        using enum SupportedGraphicsAPIBacking;

        using EnumClassBase::EnumClassBase;

        int get_major_version() const;
        int get_minor_version() const;

        const char* get_version_string() const;
    };
}

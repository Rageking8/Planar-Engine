#pragma once

#include "Planar/Engine/Core/Utils/EnumClass/EnumClassBase.hpp"

#include <string>

namespace Planar::Editor::Build
{
    enum class PlatformBacking
    {
        // Windows 64-bit
        WINDOWS_X64,
    };

    class Platform : public
        Engine::Core::Utils::EnumClass::EnumClassBase<
        PlatformBacking>
    {
    public:
        using enum PlatformBacking;

        using EnumClassBase::EnumClassBase;

        std::string get_runtime_identifier() const;
    };
}

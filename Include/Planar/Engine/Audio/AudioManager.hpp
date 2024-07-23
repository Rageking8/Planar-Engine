#pragma once

#include "Planar/Engine/Export/ExportMacros.hpp"
#include "Planar/Engine/Core/Utils/Macros/DeclarationMacros.hpp"

#include <memory>

PLANAR_FORWARD_DECLARE_CLASS(SoLoud, Soloud)

namespace Planar::Engine::Audio
{
    class PLANAR_API AudioManager
    {
    public:
        AudioManager();
        ~AudioManager();

    private:
        std::unique_ptr<SoLoud::Soloud> soloud;
    };
}

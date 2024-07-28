#pragma once

#include "Planar/Engine/Export/ExportMacros.hpp"
#include "Planar/Engine/Core/Utils/Macros/DeclarationMacros.hpp"

#include <memory>

PLANAR_FORWARD_DECLARE_CLASS(SoLoud, Soloud)
PLANAR_ENGINE_FORWARD_DECLARE_CLASS(Audio, Audio)
PLANAR_ENGINE_FORWARD_DECLARE_CLASS(Audio, AudioHandle)

namespace Planar::Engine::Audio
{
    class PLANAR_API AudioManager
    {
    public:
        AudioManager();
        ~AudioManager();

        AudioHandle play(Audio& audio) const;

    private:
        std::unique_ptr<SoLoud::Soloud> soloud;
    };
}

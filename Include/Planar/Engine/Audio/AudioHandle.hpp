#pragma once

#include "Planar/Engine/Export/ExportMacros.hpp"
#include "Planar/Engine/Core/Utils/Macros/DeclarationMacros.hpp"

PLANAR_FORWARD_DECLARE_CLASS(SoLoud, Soloud)
PLANAR_ENGINE_FORWARD_DECLARE_CLASS(Audio, Audio)

namespace Planar::Engine::Audio
{
    class PLANAR_API AudioHandle
    {
    public:
        AudioHandle(Audio* audio = nullptr, unsigned handle = 0);

        void clear();
        void stop() const;
        bool empty() const;

        void set_looping(bool new_looping) const;
        void set_volume(float new_volume) const;

    private:
        Audio* audio;
        unsigned handle;

        SoLoud::Soloud* get_soloud() const;
    };
}

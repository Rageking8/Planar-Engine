#include "Planar/Engine/Audio/AudioManager.hpp"
#include "Planar/Engine/Audio/AudioHandle.hpp"
#include "Planar/Engine/Audio/Audio.hpp"

#include "ThirdParty/SoLoud/soloud.h"
#include "ThirdParty/SoLoud/soloud_wav.h"

namespace Planar::Engine::Audio
{
    AudioManager::AudioManager() :
        soloud(std::make_unique<SoLoud::Soloud>())
    {
        soloud->init();
    }

    AudioManager::~AudioManager()
    {

    }

    AudioHandle AudioManager::play(Audio& audio) const
    {
        return { &audio, soloud->play(audio.get_sound()) };
    }
}

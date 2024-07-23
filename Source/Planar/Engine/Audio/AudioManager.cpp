#include "Planar/Engine/Audio/AudioManager.hpp"

#include "ThirdParty/SoLoud/soloud.h"

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
}

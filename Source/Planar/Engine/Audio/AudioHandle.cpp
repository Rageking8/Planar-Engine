#include "Planar/Engine/Audio/AudioHandle.hpp"
#include "Planar/Engine/Audio/Audio.hpp"

#include "ThirdParty/SoLoud/soloud.h"
#include "ThirdParty/SoLoud/soloud_wav.h"

namespace Planar::Engine::Audio
{
    AudioHandle::AudioHandle(Audio* audio, unsigned handle) :
        audio{ audio }, handle{ handle }
    {

    }

    void AudioHandle::clear()
    {
        audio = nullptr;
        handle = 0;
    }

    void AudioHandle::stop() const
    {
        get_soloud()->stop(handle);
    }

    bool AudioHandle::empty() const
    {
        return !audio;
    }

    void AudioHandle::set_looping(bool new_looping) const
    {
        get_soloud()->setLooping(handle, new_looping);
    }

    void AudioHandle::set_volume(float new_volume) const
    {
        get_soloud()->setVolume(handle, new_volume);
    }

    SoLoud::Soloud* AudioHandle::get_soloud() const
    {
        return audio->get_sound().mSoloud;
    }
}

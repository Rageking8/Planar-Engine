#pragma once

#include "Planar/Engine/Export/ExportMacros.hpp"
#include "Planar/Engine/Audio/AudioHandle.hpp"
#include "Planar/Engine/Component/Core/Component.hpp"
#include "Planar/Engine/Component/Core/ComponentMacros.hpp"
#include "Planar/Engine/Component/Mixin/Active.hpp"
#include "Planar/Engine/Asset/Component/AudioSourceAsset.hpp"
#include "Planar/Engine/Core/Utils/Macros/DeclarationMacros.hpp"

#include <string>

PLANAR_ENGINE_FORWARD_DECLARE_CLASS(GameObject, GameObject)

namespace Planar::Engine::Component
{
    class PLANAR_API AudioSource : public Core::Component<AudioSource,
        Asset::Component::AudioSourceAsset, Mixin::Active>
    {
    public:
        PLANAR_DEFINE_COMPONENT(AudioSource)

        AudioSource(GameObject::GameObject* parent,
            bool generate_guid = true);

        PLANAR_DECLARE_GET_SET(std::string, audio)
        PLANAR_DECLARE_GET_SET(bool, loop)

    private:
        std::string audio;
        bool loop;

        Audio::AudioHandle handle;

        virtual void load_impl() override;

        virtual void update_impl() override;
        virtual void application_quit_impl() override;
    };
}

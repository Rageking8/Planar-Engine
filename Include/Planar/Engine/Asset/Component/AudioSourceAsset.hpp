#pragma once

#include "Planar/Engine/Export/ExportMacros.hpp"
#include "Planar/Engine/Asset/Component/Core/ComponentAsset.hpp"
#include "Planar/Engine/Core/Utils/Macros/DeclarationMacros.hpp"
#include "Planar/Engine/Asset/Component/Mixin/Active.hpp"

PLANAR_ENGINE_FORWARD_DECLARE_CLASS(Component, AudioSource)

namespace Planar::Engine::Asset::Component
{
    class PLANAR_API AudioSourceAsset : public Core::ComponentAsset<
        Engine::Component::AudioSource, Mixin::Active>
    {
    public:
        AudioSourceAsset();

    private:
        virtual void load_impl(Engine::Component::AudioSource&
            audio_source) override;
    };
}

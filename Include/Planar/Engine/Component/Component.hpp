#pragma once

#include "Planar/Engine/Component/ComponentBase.hpp"
#include "Planar/Engine/Core/Utils/Macros/DeclarationMacros.hpp"

PLANAR_FORWARD_DECLARE_CLASS(YAML, Node)

namespace Planar::Engine::Component
{
    template <typename ComponentT, typename AssetT>
    class Component : public ComponentBase
    {
    public:
        using ComponentBase::ComponentBase;

        void load(YAML::Node node);

        virtual void load_asset() override;

        virtual const AssetT& get_asset() const override;

    protected:
        AssetT asset;

    private:
        virtual void load_impl(YAML::Node node) = 0;
    };
}

#include "Planar/Engine/Component/Component.tpp"

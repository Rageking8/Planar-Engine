#pragma once

#include "Planar/Engine/Component/ComponentBase.hpp"
#include "Planar/Engine/Core/Utils/Macros/DeclarationMacros.hpp"

PLANAR_FORWARD_DECLARE_CLASS(YAML, Node)
PLANAR_ENGINE_FORWARD_DECLARE_CLASS(GameObject, GameObject)

namespace Planar::Engine::Component
{
    template <typename ComponentT, typename AssetT,
        template <typename> typename... Mixins>
    class Component : public ComponentBase, public Mixins<AssetT>...
    {
    public:
        Component(GameObject::GameObject* parent,
            bool generate_guid = true);

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

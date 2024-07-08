#pragma once

#include "Planar/Engine/Component/Core/ComponentBase.hpp"
#include "Planar/Engine/Core/Utils/Macros/DeclarationMacros.hpp"

PLANAR_FORWARD_DECLARE_CLASS(YAML, Node)
PLANAR_ENGINE_FORWARD_DECLARE_CLASS(GameObject, GameObject)

namespace Planar::Engine::Component::Core
{
    template <typename ComponentT, typename AssetT,
        template <typename> typename... Mixins>
    class Component : public ComponentBase, public Mixins<AssetT>...
    {
    public:
        Component(GameObject::GameObject* parent,
            bool generate_guid = true);

        void load(YAML::Node node);

        virtual void update() override final;
        virtual void render() override final;

        virtual void load_asset() override;

        virtual const AssetT& get_asset() const override;

    protected:
        AssetT asset;

    private:
        virtual void load_impl() = 0;

        virtual void update_impl();
        virtual void render_impl();

        bool skip_callback() const;
    };
}

#include "Planar/Engine/Component/Core/Component.tpp"

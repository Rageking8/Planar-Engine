#pragma once

#include "Planar/Engine/Export/ExportMacros.hpp"
#include "Planar/Engine/Scene/SceneAsset.hpp"

namespace Planar::Engine::Scene
{
    class PLANAR_API Scene
    {
    public:
        Scene();
        virtual ~Scene();

        virtual void init();
        virtual void start();

        virtual void update();
        virtual void render();

        SceneAsset& get_asset();

    private:
        SceneAsset asset;
    };
}

#pragma once

#include "Planar/Engine/Export/ExportMacros.hpp"
#include "Planar/Engine/Scene/SceneAsset.hpp"
#include "Planar/Engine/Scene/SceneNode.hpp"

#include <string>

namespace Planar::Engine::Scene
{
    class PLANAR_API Scene
    {
    public:
        Scene();
        virtual ~Scene();

        void load(const std::string& scene_asset,
            const std::string& scene_name);

        virtual void init();
        virtual void start();

        virtual void update();
        virtual void render();

        SceneAsset& get_asset();
        SceneNode& get_root();

    private:
        SceneAsset asset;
        SceneNode root;
    };
}

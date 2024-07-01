#pragma once

#include "Planar/Engine/Export/ExportMacros.hpp"
#include "Planar/Engine/Component/ComponentType.hpp"
#include "Planar/Engine/Component/ComponentMacros.hpp"
#include "Planar/Engine/Core/Utils/Macros/DeclarationMacros.hpp"

#include <string>

PLANAR_ENGINE_FORWARD_DECLARE_CLASS(Asset, Asset)

namespace Planar::Engine::Component
{
    class PLANAR_API Component
    {
    public:
        PLANAR_DEFINE_COMPONENT_TYPE_AND_NAME(Component)

        Component(bool generate_guid = true);
        virtual ~Component();

        virtual ComponentType get_type() const = 0;

        virtual bool match(ComponentType other) const;

        bool get_active() const;
        void set_active(bool new_active);

        std::string get_guid() const;
        void set_guid(const std::string& new_guid);

        virtual Asset::Asset& get_asset() = 0;

    private:
        bool active;
        std::string guid;
    };
}

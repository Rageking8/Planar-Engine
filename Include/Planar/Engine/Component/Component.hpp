#pragma once

#include "Planar/Engine/Export/ExportMacros.hpp"
#include "Planar/Engine/Component/ComponentType.hpp"
#include "Planar/Engine/Component/ComponentMacros.hpp"

#include <string>

namespace Planar::Engine::Component
{
    class PLANAR_API Component
    {
    public:
        PLANAR_DEFINE_COMPONENT_TYPE_AND_NAME(Component)

        Component(bool generate_guid = true);
        virtual ~Component();

        virtual bool match(ComponentType other) const;

        bool get_active() const;
        void set_active(bool new_active);

        std::string get_guid() const;

    private:
        bool active;
        std::string guid;
    };
}

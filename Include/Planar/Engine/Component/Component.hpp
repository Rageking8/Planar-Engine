#pragma once

#include "Planar/Engine/Export/ExportMacros.hpp"
#include "Planar/Engine/Component/ComponentType.hpp"
#include "Planar/Engine/Component/ComponentMacros.hpp"

namespace Planar::Engine::Component
{
    class PLANAR_API Component
    {
    public:
        PLANAR_DEFINE_COMPONENT_TYPE_AND_NAME(Component)

        Component();
        virtual ~Component();

        virtual bool match(ComponentType other) const;

        bool get_active() const;
        void set_active(bool new_active);

    private:
        bool active;
    };
}

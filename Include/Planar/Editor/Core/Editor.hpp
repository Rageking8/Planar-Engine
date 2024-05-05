#pragma once

#include "Planar/Engine/Core/Application.hpp"

namespace Planar::Editor::Core
{
    class Editor : public Planar::Engine::Core::Application
    {
    public:
        Editor();

        virtual bool init() override;
    };
}

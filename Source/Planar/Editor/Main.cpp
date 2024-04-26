#include "Planar/Engine/Core/Application.hpp"
#include "Planar/Engine/Graphics/SupportedGraphicsAPI.hpp"

int main()
{
    Planar::Engine::Core::Application application;

    if (!application.init())
    {
        return -1;
    }

    application.run();
}

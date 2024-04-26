#include "Planar/Engine/Graphics/SupportedGraphicsAPI.hpp"

namespace Planar::Engine::Graphics
{
    int SupportedGraphicsAPI::get_major_version() const
    {
        switch (value)
        {
        case OPENGL_4_6:
            return 4;
        }

        return -1;
    }

    int SupportedGraphicsAPI::get_minor_version() const
    {
        switch (value)
        {
        case OPENGL_4_6:
            return 6;
        }

        return -1;
    }
}

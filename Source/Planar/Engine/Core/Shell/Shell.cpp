#include "Planar/Engine/Core/Shell/Shell.hpp"
#include "Planar/Engine/Core/Constants/Links.hpp"

#include <Windows.h>
#include <shellapi.h>

namespace Planar::Engine::Core::Shell
{
    void open_link(const std::string& link)
    {
        ShellExecute(nullptr, nullptr, link.c_str(),
            nullptr, nullptr, SW_SHOW);
    }

    void open_planar_website()
    {
        open_link(Constants::PLANAR_WEBSITE_LINK);
    }
}

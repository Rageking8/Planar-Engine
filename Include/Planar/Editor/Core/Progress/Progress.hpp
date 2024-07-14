#pragma once

#include "Planar/Editor/Core/Utils/Macros/DeclarationMacros.hpp"

#include <string>
#include <functional>

PLANAR_EDITOR_FORWARD_DECLARE_CLASS(Core::Progress, ProgressHandler)

namespace Planar::Editor::Core::Progress
{
    void task(const std::function<void()>& run,
        bool dry_run, unsigned& tasks, unsigned amount = 1);

    void task(const std::string& text,
        const std::function<void()>& run,
        const ProgressHandler& progress_handler,
        bool dry_run, unsigned& tasks, unsigned amount = 1);
}

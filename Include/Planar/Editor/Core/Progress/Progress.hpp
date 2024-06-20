#pragma once

#include "Planar/Editor/Core/Progress/ProgressHandler.hpp"

#include <string>
#include <functional>

namespace Planar::Editor::Core::Progress
{
    void task(const std::function<void()>& run,
        bool dry_run, unsigned& tasks, unsigned amount = 1);

    void task(const std::string& text,
        const std::function<void()>& run,
        const ProgressHandler& progress_handler,
        bool dry_run, unsigned& tasks, unsigned amount = 1);
}

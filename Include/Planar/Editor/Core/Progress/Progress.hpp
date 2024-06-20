#pragma once

#include <functional>

namespace Planar::Editor::Core::Progress
{
    void dry_run_helper(const std::function<void()>& run,
        bool dry_run, unsigned& tasks, unsigned amount = 1);
}

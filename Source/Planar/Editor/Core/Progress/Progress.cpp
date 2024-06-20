#include "Planar/Editor/Core/Progress/Progress.hpp"

namespace Planar::Editor::Core::Progress
{
    void dry_run_helper(const std::function<void()>& run,
        bool dry_run, unsigned& tasks, unsigned amount)
    {
        if (!dry_run)
        {
            run();
        }
        else
        {
            tasks += amount;
        }
    }
}

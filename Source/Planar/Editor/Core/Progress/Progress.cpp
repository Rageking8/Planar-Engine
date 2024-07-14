#include "Planar/Editor/Core/Progress/Progress.hpp"
#include "Planar/Editor/Core/Progress/ProgressHandler.hpp"

namespace Planar::Editor::Core::Progress
{
    void task(const std::function<void()>& run,
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

    void task(const std::string& text,
        const std::function<void()>& run,
        const ProgressHandler& progress_handler,
        bool dry_run, unsigned& tasks, unsigned amount)
    {
        task([&]
            {
                progress_handler(text);
                run();
                progress_handler();
            }, dry_run, tasks, amount);
    }
}

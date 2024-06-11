#include "Planar/Editor/Core/Progress/Progress.hpp"
#include "Planar/Engine/Core/Utils/Checks/Assert.hpp"

namespace Planar::Editor::Core::Progress
{
    ProgressHandler::ProgressHandler(
        const ProgressCallback& progress_callback) :
        progress_callback{ progress_callback }
    {

    }

    void ProgressHandler::operator()(unsigned amount) const
    {
        PLANAR_ASSERT(progress_callback,
            "`progress_callback` cannot be empty");

        progress_callback(amount, "");
    }

    void ProgressHandler::operator()(const std::string& text,
        unsigned amount) const
    {
        PLANAR_ASSERT(progress_callback,
            "`progress_callback` cannot be empty");

        progress_callback(amount, text + "...");
    }
}

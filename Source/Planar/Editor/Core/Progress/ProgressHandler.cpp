#include "Planar/Editor/Core/Progress/ProgressHandler.hpp"

namespace Planar::Editor::Core::Progress
{
    ProgressHandler::ProgressHandler(
        const ProgressCallback& progress_callback) :
        progress_callback{ progress_callback }
    {

    }

    void ProgressHandler::operator()(unsigned amount) const
    {
        if (!progress_callback)
        {
            return;
        }

        progress_callback(amount, "");
    }

    void ProgressHandler::operator()(const std::string& text,
        unsigned amount) const
    {
        if (!progress_callback)
        {
            return;
        }

        progress_callback(amount, text + "...");
    }
}

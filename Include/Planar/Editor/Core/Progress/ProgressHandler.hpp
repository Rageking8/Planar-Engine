#pragma once

#include <string>
#include <functional>

namespace Planar::Editor::Core::Progress
{
    class ProgressHandler
    {
    public:
        using ProgressCallback =
            std::function<void(unsigned, const std::string&)>;

        ProgressHandler(const ProgressCallback& progress_callback = {});

        void operator()(unsigned amount = 1) const;
        void operator()(const std::string& text,
            unsigned amount = 0) const;

    private:
        const ProgressCallback& progress_callback;
    };
}

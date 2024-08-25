#pragma once

namespace Planar::Editor::Core::Console
{
    class ProcessResult
    {
    public:
        enum class Action
        {
            CONTINUE,

            RETURN,
        };

        ProcessResult();
        ProcessResult(int return_value);

        Action get_action() const;
        int get_return_value() const;

    private:
        Action action;
        int return_value;
    };
}

#include "Planar/Editor/Core/Console/ProcessResult.hpp"
#include "Planar/Engine/Core/Utils/Checks/Assert.hpp"

namespace Planar::Editor::Core::Console
{
    ProcessResult::ProcessResult() : action{ Action::CONTINUE },
        return_value{}
    {

    }

    ProcessResult::ProcessResult(int return_value) :
        action{ Action::RETURN }, return_value{ return_value }
    {

    }

    ProcessResult::Action ProcessResult::get_action() const
    {
        return action;
    }

    int ProcessResult::get_return_value() const
    {
        PLANAR_ASSERT(action == Action::RETURN,
            "Return value does not exist");

        return return_value;
    }
}

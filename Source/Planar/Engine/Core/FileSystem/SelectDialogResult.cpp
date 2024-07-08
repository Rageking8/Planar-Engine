#include "Planar/Engine/Core/FileSystem/SelectDialogResult.hpp"
#include "Planar/Engine/Core/Utils/Checks/Assert.hpp"

namespace Planar::Engine::Core::FileSystem
{
    SelectDialogResult::SelectDialogResult(Type type,
        const std::string& path_or_error) : type{ type },
        path_or_error{ path_or_error }
    {

    }

    SelectDialogResult::operator bool() const
    {
        return type == Type::OKAY;
    }

    SelectDialogResult::Type SelectDialogResult::get_type() const
    {
        return type;
    }

    std::filesystem::path SelectDialogResult::get_path() const
    {
        PLANAR_ASSERT(type == Type::OKAY, "Path does not exist");

        return path_or_error;
    }

    bool SelectDialogResult::has_error() const
    {
        return type == Type::ERROR;
    }

    std::string SelectDialogResult::get_error() const
    {
        PLANAR_ASSERT(type == Type::ERROR, "Error does not exist");

        return path_or_error;
    }
}

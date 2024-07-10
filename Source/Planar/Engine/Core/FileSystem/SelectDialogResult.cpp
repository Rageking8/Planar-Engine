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

    bool SelectDialogResult::check(const std::string& extension) const
    {
        return type == Type::OKAY &&
            get_path().extension().string() == extension;
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

    std::string SelectDialogResult::get_filename(bool include_extension)
        const
    {
        std::filesystem::path path = get_path();

        return include_extension ? path.filename().string() :
            path.stem().string();
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

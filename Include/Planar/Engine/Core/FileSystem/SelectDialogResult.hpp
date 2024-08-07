#pragma once

#include "Planar/Engine/Export/ExportMacros.hpp"

#include <string>
#include <filesystem>

#undef ERROR

namespace Planar::Engine::Core::FileSystem
{
    class PLANAR_API SelectDialogResult
    {
    public:
        enum class Type
        {
            NONE,

            OKAY,

            CANCEL,

            ERROR,
        };

        SelectDialogResult(Type type = Type::NONE,
            const std::string& path_or_error = {});

        explicit operator bool() const;

        bool check(const std::string& extension) const;

        Type get_type() const;

        std::filesystem::path get_path() const;
        std::string get_filename(bool include_extension = true) const;

        bool has_error() const;
        std::string get_error() const;

    private:
        Type type;
        std::string path_or_error;
    };
}

#include "Planar/Engine/Core/Archive/Archive.hpp"
#include "Planar/Engine/Asset/LoadAssetMacros.hpp"
#include "Planar/Engine/Core/FileSystem/FileSystem.hpp"
#include "Planar/Engine/Core/Execute/Execute.hpp"

#include <filesystem>

PLANAR_LOAD_UNSIGNED_CHAR_ARRAY_ASSET(Engine, _7zr)

namespace Planar::Engine::Core::Archive
{
    void extract_7z(std::filesystem::path program_path,
        const std::filesystem::path& input_path)
    {
        program_path /= "7zr.exe";
        if (!std::filesystem::exists(program_path))
        {
            FileSystem::clear_file(program_path);
            PLANAR_APPEND_ARRAY_TO_FILE(program_path,
                Engine, _7zr);
        }

        Execute::run_program(program_path.parent_path(), program_path,
            { "x", std::filesystem::absolute(input_path).string() });
    }
}

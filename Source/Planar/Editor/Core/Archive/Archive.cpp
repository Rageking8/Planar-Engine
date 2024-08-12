#include "Planar/Editor/Core/Archive/Archive.hpp"
#include "Planar/Engine/Asset/LoadAssetMacros.hpp"
#include "Planar/Engine/Core/FileSystem/FileSystem.hpp"
#include "Planar/Engine/Core/Execute/Execute.hpp"

PLANAR_LOAD_UNSIGNED_CHAR_ARRAY_ASSET(Editor::Archive, _7zr)

namespace Planar::Editor::Core::Archive
{
    void extract_7z(std::filesystem::path program_path,
        const std::filesystem::path& input_path)
    {
        program_path /= "7zr.exe";
        if (!std::filesystem::exists(program_path))
        {
            Engine::Core::FileSystem::clear_file(program_path);
            PLANAR_APPEND_ARRAY_TO_FILE(program_path,
                Editor::Archive, _7zr);
        }

        Engine::Core::Execute::run_program(program_path, { "x",
            std::filesystem::absolute(input_path).string() },
            program_path.parent_path());
    }
}

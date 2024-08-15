#include "Planar/Editor/Build/Compression/Compression.hpp"
#include "Planar/Editor/Core/Execute/Execute.hpp"
#include "Planar/Engine/Asset/LoadAssetMacros.hpp"
#include "Planar/Engine/Core/FileSystem/FileSystem.hpp"

#include <string>

PLANAR_LOAD_UNSIGNED_CHAR_ARRAY_ASSET(Editor::Build, upx)

namespace Planar::Editor::Build::Compression
{
    void compress(std::filesystem::path program_path,
        const std::filesystem::path& input_path,
        unsigned compression_level)
    {
        program_path /= "upx.exe";
        if (!std::filesystem::exists(program_path))
        {
            Engine::Core::FileSystem::clear_file(program_path);
            PLANAR_APPEND_ARRAY_TO_FILE(program_path,
                Editor::Build, upx);
        }

        Core::Execute::run_program(program_path,
            { ("-" + std::to_string(compression_level)),
            std::filesystem::absolute(input_path).string() });
    }
}

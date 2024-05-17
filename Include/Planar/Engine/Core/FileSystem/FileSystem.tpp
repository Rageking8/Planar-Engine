#include <fstream>

namespace Planar::Engine::Core::FileSystem
{
    template <typename T, std::size_t N>
    void append_array_to_file(const std::filesystem::path& path,
        T(&array)[N])
    {
        append_array_to_file(path, array, N);
    }

    template <typename T>
    void append_array_to_file(const std::filesystem::path& path,
        T* array, std::size_t size)
    {
        std::ofstream output_stream;
        output_stream.open(path, std::ios::binary | std::ios::app);

        output_stream.write((char*)array, size);
    }
}

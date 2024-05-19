#include "Planar/Engine/Core/Archive/Archive.hpp"

#include "ThirdParty/libzip/zip.h"

#include <fstream>
#include <vector>
#include <cstring>
#include <filesystem>

namespace Planar::Engine::Core::Archive
{
    bool extract_zip(const std::filesystem::path& input_zip,
        const std::filesystem::path& output_path, unsigned buffer_size)
    {
        zip_t* zip{};
        int error{};
        std::vector<char> buffer(buffer_size);

        zip = zip_open(input_zip.string().c_str(), 0, &error);
        if (!zip)
        {
            return false;
        }

        for (zip_int64_t i = 0; i < zip_get_num_entries(zip, 0); ++i)
        {
            zip_stat_t zip_stat{};
            if (zip_stat_index(zip, i, 0, &zip_stat) == 0)
            {
                if (zip_stat.name &&
                    zip_stat.name[strlen(zip_stat.name) - 1] == '/')
                {
                    std::filesystem::create_directories(
                        output_path / zip_stat.name);
                }
                else
                {
                    zip_file_t* zip_file = zip_fopen_index(zip, i, 0);

                    if (!zip_file)
                    {
                        return false;
                    }

                    std::ofstream output(output_path / zip_stat.name,
                        std::ios_base::binary);

                    zip_uint64_t sum = 0;
                    while (sum != zip_stat.size)
                    {
                        zip_int64_t length = zip_fread(zip_file,
                            buffer.data(), buffer_size);

                        if (length < 0)
                        {
                            return false;
                        }

                        output.write(buffer.data(), length);
                        sum += length;
                    }

                    zip_fclose(zip_file);
                }
            }
        }

        if (zip_close(zip) == -1)
        {
            return false;
        }

        return true;
    }
}

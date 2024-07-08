#include "Planar/Engine/Core/FileSystem/FileSystem.hpp"

#include "ThirdParty/nativefiledialog-extended/nfd.hpp"

#include <cctype>
#include <fstream>
#include <algorithm>

namespace Planar::Engine::Core::FileSystem
{
    std::wstring select_folder_dialog()
    {
        NFD::UniquePath path;

        nfdresult_t result = NFD::PickFolder(path);
        if (result == NFD_OKAY)
        {
            std::string path_string = path.get();
            return { path_string.begin(), path_string.end() };
        }
        else
        {
            return L"";
        }
    }

    void create_file(const std::filesystem::path& path,
        const std::string& contents)
    {
        if (path.has_parent_path())
        {
            std::filesystem::create_directories(path.parent_path());
        }

        std::ofstream output(path);
        output << contents;
    }

    std::string read_file(const std::filesystem::path& path)
    {
        std::ifstream file(path);
        std::ostringstream buffer;
        buffer << file.rdbuf();

        return buffer.str();
    }

    void sort_path_vector(std::vector<std::filesystem::path>& path_vector)
    {
        std::sort(path_vector.begin(), path_vector.end(),
            [](const auto& lhs, const auto& rhs)
            {
                std::string lhs_string = lhs.string();
                std::string rhs_string = rhs.string();

                const auto result = std::mismatch(lhs_string.cbegin(),
                    lhs_string.cend(), rhs_string.cbegin(), rhs_string.
                    cend(),
                    [](const auto& lhs, const auto& rhs)
                    {
                        return std::tolower(lhs) == std::tolower(rhs);
                    });

                return result.second != rhs_string.cend() && (result.
                    first == lhs_string.cend() || std::tolower(*result.
                    first) < std::tolower(*result.second));
            });
    }

    std::vector<std::filesystem::path> get_listing(
        const std::filesystem::path& path, ListingSortType sort_type)
    {
        std::vector<std::filesystem::path> listing;

        switch (sort_type)
        {
        case ListingSortType::FOLDER_THEN_FILE_ALPHABETICAL:
            std::vector<std::filesystem::path> folder_vector;
            std::vector<std::filesystem::path> file_vector;

            for (const auto& i :
                std::filesystem::directory_iterator(path))
            {
                if (i.is_directory())
                {
                    folder_vector.push_back(i);
                }
                else if (i.is_regular_file())
                {
                    file_vector.push_back(i);
                }
            }

            sort_path_vector(folder_vector);
            sort_path_vector(file_vector);

            listing.insert(listing.end(), folder_vector.begin(),
                folder_vector.end());
            listing.insert(listing.end(), file_vector.begin(),
                file_vector.end());
            
            break;
        }

        return listing;
    }

    unsigned file_count_with_extension(
        const std::filesystem::path& path,
        const std::string& extension)
    {
        unsigned count = 0;

        for (const auto& i :
            std::filesystem::directory_iterator(path))
        {
            if (i.is_regular_file() &&
                i.path().extension() == "." + extension)
            {
                count++;
            }
        }

        return count;
    }

    std::filesystem::path first_file_with_extension(
        const std::filesystem::path& path,
        const std::string& extension)
    {
        for (const auto& i :
            std::filesystem::directory_iterator(path))
        {
            if (i.is_regular_file() &&
                i.path().extension() == "." + extension)
            {
                return i.path();
            }
        }

        return {};
    }

    void clear_file(const std::filesystem::path& path)
    {
        create_file(path, "");
    }
}

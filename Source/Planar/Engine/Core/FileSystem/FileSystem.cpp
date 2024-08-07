#include "Planar/Engine/Core/FileSystem/FileSystem.hpp"
#include "Planar/Engine/Core/FileSystem/SelectDialogResult.hpp"

#include "ThirdParty/nativefiledialog-extended/nfd.hpp"

#include <cctype>
#include <fstream>
#include <algorithm>

namespace Planar::Engine::Core::FileSystem
{
    SelectDialogResult select_folder_dialog()
    {
        NFD::UniquePath path;

        nfdresult_t result = NFD::PickFolder(path);
        if (result == NFD_OKAY)
        {
            return { SelectDialogResult::Type::OKAY, path.get() };
        }
        else if (result == NFD_CANCEL)
        {
            return { SelectDialogResult::Type::CANCEL };
        }
        else
        {
            return { SelectDialogResult::Type::ERROR, NFD::GetError() };
        }
    }

    SelectDialogResult select_file_dialog(
        std::optional<SelectDialogFilter> filter)
    {
        NFD::UniquePath path;

        nfdresult_t result = NFD::OpenDialog(path, filter ?
            static_cast<const nfdu8filteritem_t*>(
            filter->generate_filter()) : nullptr, filter ?
            filter->get_size() : 0);
        if (result == NFD_OKAY)
        {
            return { SelectDialogResult::Type::OKAY, path.get() };
        }
        else if (result == NFD_CANCEL)
        {
            return { SelectDialogResult::Type::CANCEL };
        }
        else
        {
            return { SelectDialogResult::Type::ERROR, NFD::GetError() };
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

    void iterate_files_recursive(const std::filesystem::path& root,
        const std::function<void(const std::filesystem::path&)>&
        callback, const std::unordered_set<std::string>& skip_folders)
    {
        for (auto i =
            std::filesystem::recursive_directory_iterator(root);
            i != std::filesystem::recursive_directory_iterator();
            ++i)
        {
            if (i->is_directory() && skip_folders.contains(i->path().
                filename().string()))
            {
                i.disable_recursion_pending();

                continue;
            }

            if (!i->is_regular_file())
            {
                continue;
            }

            callback(i->path());
        }
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

    std::filesystem::path replace_extension(std::filesystem::path path,
        const std::string& new_extension)
    {
        return path.replace_extension(new_extension);
    }

    void clear_file(const std::filesystem::path& path)
    {
        create_file(path, "");
    }
}

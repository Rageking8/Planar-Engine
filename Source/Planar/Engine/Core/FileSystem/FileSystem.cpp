#include "Planar/Engine/Core/FileSystem/FileSystem.hpp"

#include "ShObjIdl.h"

#include <cctype>
#include <fstream>
#include <algorithm>

namespace Planar::Engine::Core::FileSystem
{
    std::wstring select_folder_dialog()
    {
        IFileDialog* pfd;
        wchar_t* path;
        bool fail = true;

        if (SUCCEEDED(CoCreateInstance(CLSID_FileOpenDialog, NULL,
            CLSCTX_INPROC_SERVER, IID_PPV_ARGS(&pfd))))
        {
            DWORD dwOptions;
            if (SUCCEEDED(pfd->GetOptions(&dwOptions)))
            {
                pfd->SetOptions(dwOptions | FOS_PICKFOLDERS);
            }

            if (SUCCEEDED(pfd->Show(nullptr)))
            {
                IShellItem* psi;
                if (SUCCEEDED(pfd->GetResult(&psi)))
                {
                    if (SUCCEEDED(psi->GetDisplayName(
                        SIGDN_DESKTOPABSOLUTEPARSING, &path)))
                    {
                        fail = false;
                    }

                    psi->Release();
                }
            }

            pfd->Release();
        }

        return fail ? L"" : path;
    }

    void create_file(const std::filesystem::path& path,
        const std::string& contents)
    {
        if (!path.has_extension())
        {
            return;
        }

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

    void clear_file(const std::filesystem::path& path)
    {
        std::ofstream file(path);
    }
}

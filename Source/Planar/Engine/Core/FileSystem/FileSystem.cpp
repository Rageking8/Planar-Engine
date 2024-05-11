#include "Planar/Engine/Core/FileSystem/FileSystem.hpp"

#include "ShObjIdl.h"

#include <fstream>

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
}

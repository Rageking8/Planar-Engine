#include "Planar/Engine/Core/FileSystem/FileSystem.hpp"

#include "ShObjIdl.h"

namespace Planar::Engine::Core::FileSystem
{
    std::wstring SelectFolderDialog()
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
}

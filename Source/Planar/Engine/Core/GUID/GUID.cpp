#include "Planar/Engine/Core/GUID/GUID.hpp"

#include "guiddef.h"
#include "objbase.h"

#include <format>
#include <string_view>

namespace Planar::Engine::Core::GUID
{
    std::string generate_guid(Representation representation)
    {
        ::GUID guid;
        HRESULT result = CoCreateGuid(&guid);

        if (result != RPC_S_OK)
        {
            return "";
        }

        auto format = [&](std::string_view format_str)
            {
                return std::vformat(format_str, std::make_format_args(
                    guid.Data1, guid.Data2, guid.Data3, guid.Data4[0],
                    guid.Data4[1], guid.Data4[2], guid.Data4[3],
                    guid.Data4[4], guid.Data4[5], guid.Data4[6],
                    guid.Data4[7]));
            };

        switch (representation)
        {
        case Representation::DEFAULT:
            return format("{:08X}-{:04X}-{:04X}-{:02X}{:02X}-"
                "{:02X}{:02X}{:02X}{:02X}{:02X}{:02X}");

        case Representation::DEFAULT_COMPACT:
            return format("{:08X}{:04X}{:04X}{:02X}{:02X}{:02X}"
                "{:02X}{:02X}{:02X}{:02X}{:02X}");
        }

        return "";
    }
}

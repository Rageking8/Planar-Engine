#include "Planar/Engine/Core/FileSystem/SelectDialogFilter.hpp"

#include "ThirdParty/nativefiledialog-extended/nfd.hpp"

#include <cctype>
#include <algorithm>

namespace Planar::Engine::Core::FileSystem
{
    SelectDialogFilter::SelectDialogFilter()
    {

    }

    void SelectDialogFilter::add_filter_item(const std::string& name)
    {
        std::string name_lowercase = name;
        std::transform(name_lowercase.begin(), name_lowercase.end(),
            name_lowercase.begin(), std::tolower);

        filters.push_back({ name, "planar" + name_lowercase });
    }

    const void* SelectDialogFilter::generate_filter() const
    {
        static std::vector<nfdu8filteritem_t> result;
        result.clear();
        result.reserve(get_size());

        for (const auto& filter_item : filters)
        {
            result.push_back({ filter_item.name.c_str(),
                filter_item.spec.c_str() });
        }

        return result.data();
    }

    unsigned SelectDialogFilter::get_size() const
    {
        return static_cast<unsigned>(filters.size());
    }
}

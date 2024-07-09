#pragma once

#include "Planar/Engine/Export/ExportMacros.hpp"

#include <string>
#include <vector>

namespace Planar::Engine::Core::FileSystem
{
    class PLANAR_API SelectDialogFilter
    {
    public:
        SelectDialogFilter();

        void add_filter_item(const std::string& name);

        const void* generate_filter() const;
        unsigned get_size() const;

    private:
        struct FilterItem
        {
            std::string name;
            std::string spec;
        };

        std::vector<FilterItem> filters;
    };
}

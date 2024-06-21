#pragma once

#include <string>
#include <functional>
#include <unordered_map>

namespace Planar::Editor::Core::Save
{
    class SaveHandler
    {
    public:
        SaveHandler();

        void add_save_callback(const std::string& name,
            const std::function<void()>& save_callback);
        void remove_save_callback(const std::string& name);

        bool get_dirty() const;
        void set_dirty();

        void save_all();

    private:
        std::unordered_map<std::string, std::function<void()>>
            save_callbacks;
        bool dirty;
    };
}

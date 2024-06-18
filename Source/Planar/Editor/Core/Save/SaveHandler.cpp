#include "Planar/Editor/Core/Save/SaveHandler.hpp"

namespace Planar::Editor::Core::Save
{
    SaveHandler::SaveHandler() : dirty{}
    {

    }

    void SaveHandler::add_save_callback(const std::string& name,
        const std::function<void()>& save_callback)
    {
        save_callbacks[name] = save_callback;
    }

    bool SaveHandler::get_dirty() const
    {
        return dirty;
    }

    void SaveHandler::set_dirty()
    {
        dirty = true;
    }

    void SaveHandler::save_all()
    {
        for (const auto& i : save_callbacks)
        {
            i.second();
        }

        dirty = false;
    }
}

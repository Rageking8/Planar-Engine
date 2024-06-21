#include "Planar/Editor/Core/Save/SaveHandler.hpp"
#include "Planar/Engine/Core/Utils/Checks/Assert.hpp"

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

    void SaveHandler::remove_save_callback(const std::string& name)
    {
        auto result = save_callbacks.erase(name);

        PLANAR_ASSERT(result,
            "`name` does not exist in `save_callbacks`");
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

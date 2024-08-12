#include "Planar/Editor/UI/Element/Component/Script.hpp"

namespace Planar::Editor::UI::Element::Component
{
    Script::Script()
    {

    }

    bool Script::get_modified(bool reset)
    {
        return modified_helper(reset, active_checkbox);
    }

    void Script::render_content()
    {

    }

    void Script::set_values_impl(ComponentType* script)
    {
        active_checkbox.set_value(script->get_active());
    }

    void Script::write_values_impl(ComponentType* script)
    {
        script->set_active(active_checkbox.get_value());
    }
}

#include "Planar/Editor/UI/Element/Component/Script.hpp"

namespace Planar::Editor::UI::Element::Component
{
    Script::Script() : Component(true, generate_header_text(""))
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
        set_header_text(generate_header_text(script->get_script()));
    }

    void Script::write_values_impl(ComponentType* script)
    {
        script->set_active(active_checkbox.get_value());
    }

    std::string Script::generate_header_text(const std::string& script)
        const
    {
        return script + (script.empty() ? "" : " ") + "(Script)";
    }
}

#include "Planar/Editor/UI/Element/PlayStopToggle.hpp"
#include "Planar/Editor/Asset/LoadAssetMacros.hpp"

PLANAR_LOAD_EDITOR_ICON(PlayIcon)
PLANAR_LOAD_EDITOR_ICON(StopIcon)

namespace Planar::Editor::UI::Element
{
    PlayStopToggle::PlayStopToggle() : ToggleButton(15.f)
    {
        PLANAR_LOAD_EDITOR_ICON_TEXTURE(play_texture, PlayIcon)
        PLANAR_LOAD_EDITOR_ICON_TEXTURE(stop_texture, StopIcon)

        add_state("Play", play_texture.get_id());
        add_state("Stop", stop_texture.get_id());
    }

    PlayStopToggle::State PlayStopToggle::get() const
    {
        return get_current() ? State::PLAY : State::STOP;
    }
}

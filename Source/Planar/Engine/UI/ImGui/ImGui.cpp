#include "Planar/Engine/UI/ImGui/ImGui.hpp"
#include "Planar/Engine/UI/ImGui/Core/Cursor/Cursor.hpp"
#include "Planar/Engine/Core/GUID/GUID.hpp"

#include "ThirdParty/ImGui/imgui.h"
#include "ThirdParty/ImGui/imgui_stdlib.h"

namespace Planar::Engine::UI::ImGui
{
    void set_ini_filename(const std::string& ini_filename)
    {
        ::ImGui::GetIO().IniFilename =
            ini_filename.empty() ? nullptr : ini_filename.c_str();
    }

    void set_config_flags(int config_flags)
    {
        ::ImGui::GetIO().ConfigFlags = config_flags;
    }

    void set_drag_click_to_input(bool drag_click_to_input)
    {
        ::ImGui::GetIO().ConfigDragClickToInputText =
            drag_click_to_input;
    }

    void save_ini()
    {
        const char* ini_filename = ::ImGui::GetIO().IniFilename;
        if (ini_filename)
        {
            ::ImGui::SaveIniSettingsToDisk(ini_filename);
        }
    }

    void load_ini_from_string(const std::string& ini_file)
    {
        ::ImGui::LoadIniSettingsFromMemory(ini_file.c_str());
    }

    void reset_style()
    {
        ::ImGui::GetStyle() = ImGuiStyle();
    }

    void scale_ui(int factor)
    {
        ::ImGui::GetStyle().ScaleAllSizes(
            static_cast<float>(factor));
    }

    float get_font_size()
    {
        return ::ImGui::GetFontSize();
    }

    void set_scrollbar_size(float new_scrollbar_size)
    {
        ::ImGui::GetStyle().ScrollbarSize = new_scrollbar_size;
    }

    Math::Size2Df get_main_viewport_size()
    {
        ImVec2 main_viewport_size = ::ImGui::GetMainViewport()->Size;

        return { main_viewport_size.x, main_viewport_size.y };
    }

    Math::Size2Df get_window_size()
    {
        ImVec2 window_size = ::ImGui::GetWindowSize();

        return { window_size.x, window_size.y };
    }

    Math::Pos2Df get_window_position()
    {
        ImVec2 window_position = ::ImGui::GetWindowPos();

        return { window_position.x, window_position.y };
    }

    Math::Size2Df get_window_content_region_max()
    {
        ImVec2 window_content_region_max =
            ::ImGui::GetWindowContentRegionMax();

        return { window_content_region_max.x,
            window_content_region_max.y };
    }

    Math::Size2Df get_content_region_avail()
    {
        ImVec2 content_region_avail = ::ImGui::GetContentRegionAvail();

        return { content_region_avail.x, content_region_avail.y };
    }

    Math::Size2Df get_item_spacing()
    {
        ImVec2 item_spacing = ::ImGui::GetStyle().ItemSpacing;

        return { item_spacing.x, item_spacing.y };
    }

    Math::Pos2Df get_item_rect_max()
    {
        ImVec2 item_rect_max = ::ImGui::GetItemRectMax();

        return { item_rect_max.x, item_rect_max.y };
    }

    std::string generate_unique_label()
    {
        return "##" + Engine::Core::GUID::generate_guid(
            Engine::Core::GUID::Representation::DEFAULT_COMPACT);
    }

    void text(const std::string& text, bool align_text_to_frame_padding)
    {
        if (align_text_to_frame_padding)
        {
            ::ImGui::AlignTextToFramePadding();
        }

        ::ImGui::Text(text.c_str());
    }

    void text_wrapped(const std::string& text, float wrap_width)
    {
        bool custom_wrap_width = wrap_width != -1.f;

        if (custom_wrap_width)
        {
            ::ImGui::PushTextWrapPos(Core::Cursor::get_x() +
                wrap_width);
        }

        ::ImGui::TextWrapped(text.c_str());

        if (custom_wrap_width)
        {
            ::ImGui::PopTextWrapPos();
        }
    }

    bool input_text(const std::string& label, std::string& text,
        int flags)
    {
        return ::ImGui::InputText(label.c_str(), &text, flags);
    }

    bool input_text(const std::string& label,
        const std::string& placeholder, std::string& text, int flags)
    {
        return ::ImGui::InputTextWithHint(label.c_str(),
            placeholder.c_str(), &text, flags);
    }

    void image(GLuint texture, Math::Size2Df size, bool flip_y)
    {
        ::ImGui::Image((void*)texture, { size.width, size.height },
            flip_y ? ::ImVec2(0.f, 1.f) : ::ImVec2(0.f, 0.f),
            flip_y ? ::ImVec2(1.f, 0.f) : ::ImVec2(1.f, 1.f));
    }

    void newline(unsigned count)
    {
        for (unsigned i = 0; i < count; ++i)
        {
            ::ImGui::NewLine();
        }
    }

    void same_line()
    {
        ::ImGui::SameLine();
    }

    void separator(float extra_height)
    {
        Core::Cursor::move_y(extra_height);
        ::ImGui::Separator();
        Core::Cursor::move_y(extra_height);
    }

    bool is_item_hovered()
    {
        return ::ImGui::IsItemHovered();
    }

    bool is_left_mouse_double_clicked()
    {
        return ::ImGui::IsMouseDoubleClicked(ImGuiMouseButton_Left);
    }
}

#include "Planar/Engine/UI/ImGui/ImGui.hpp"
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

    void set_scrollbar_size(float new_scrollbar_size)
    {
        ::ImGui::GetStyle().ScrollbarSize = new_scrollbar_size;
    }

    Planar::Engine::Math::Size2Df get_window_size()
    {
        ImVec2 window_size = ::ImGui::GetWindowSize();

        return { window_size.x, window_size.y };
    }

    Planar::Engine::Math::Pos2Df get_window_position()
    {
        ImVec2 window_position = ::ImGui::GetWindowPos();

        return { window_position.x, window_position.y };
    }

    Planar::Engine::Math::Size2Df get_window_content_region_max()
    {
        ImVec2 window_content_region_max =
            ::ImGui::GetWindowContentRegionMax();

        return { window_content_region_max.x,
            window_content_region_max.y };
    }

    Planar::Engine::Math::Size2Df get_item_spacing()
    {
        ImVec2 item_spacing = ::ImGui::GetStyle().ItemSpacing;

        return { item_spacing.x, item_spacing.y };
    }

    Planar::Engine::Math::Pos2Df get_item_rect_max()
    {
        ImVec2 item_rect_max = ::ImGui::GetItemRectMax();

        return { item_rect_max.x, item_rect_max.y };
    }

    std::string generate_unique_label()
    {
        return "##" + Planar::Engine::Core::GUID::generate_guid(
            Planar::Engine::Core::GUID::Representation::DEFAULT_COMPACT);
    }

    void text(const std::string& text)
    {
        ::ImGui::Text(text.c_str());
    }

    void text_wrapped(const std::string& text, float wrap_width)
    {
        bool custom_wrap_width = wrap_width != -1.f;

        if (custom_wrap_width)
        {
            ::ImGui::PushTextWrapPos(get_cursor_x() + wrap_width);
        }

        ::ImGui::TextWrapped(text.c_str());

        if (custom_wrap_width)
        {
            ::ImGui::PopTextWrapPos();
        }
    }

    bool button(const std::string& name,
        Planar::Engine::Math::Size2Df size)
    {
        return ::ImGui::Button(name.c_str(),
            { size.width, size.height });
    }

    bool button(const std::string& name, GLuint texture,
        Planar::Engine::Math::Size2Df size)
    {
        return ::ImGui::ImageButton(name.c_str(), (void*)texture,
            { size.width, size.height });
    }

    void input_text(const std::string& label, std::string& text)
    {
        ::ImGui::InputText(label.c_str(), &text);
    }

    void input_text(const std::string& label,
        const std::string& placeholder, std::string& text)
    {
        ::ImGui::InputTextWithHint(label.c_str(),
            placeholder.c_str(), &text);
    }

    void image(GLuint texture, Planar::Engine::Math::Size2Df size,
        bool flip_y)
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

    void dock_space_over_viewport()
    {
        ::ImGui::DockSpaceOverViewport(::ImGui::GetMainViewport());
    }

    float get_cursor_x()
    {
        return ::ImGui::GetCursorPosX();
    }

    float get_cursor_y()
    {
        return ::ImGui::GetCursorPosY();
    }

    void move_cursor(Planar::Engine::Math::Size2Df delta)
    {
        move_cursor_x(delta.width);
        move_cursor_y(delta.height);
    }

    void move_cursor_x(float delta)
    {
        ::ImGui::SetCursorPosX(get_cursor_x() + delta);
    }

    void move_cursor_y(float delta)
    {
        ::ImGui::SetCursorPosY(get_cursor_y() + delta);
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

#include "Planar/Engine/UI/ImGui/Window/Window.hpp"
#include "Planar/Engine/UI/ImGui/Style/StyleVar.hpp"
#include "Planar/Engine/UI/ImGui/Style/StyleColor.hpp"

namespace Planar::Engine::UI::ImGui::Window
{
    Window::Scope::Scope(const char* name,
        ::ImGuiWindowFlags begin_flags, bool* open,
        std::optional<Math::Size2Df> min_size,
        std::optional<Math::Size2Df> padding)
    {
        Style::StyleVar style_var;
        Style::StyleColor style_color;

        if (min_size)
        {
            style_var.set_min_window_size(*min_size);
        }

        if (padding)
        {
            style_var.set_window_padding(*padding);
        }

        style_color.set_resize_grip_all_color({});

        ::ImGui::Begin(name, open, begin_flags);
    }

    Window::Scope::~Scope()
    {
        ::ImGui::End();
    }

    Window::Window(const std::string& name,
        WindowFlags flags, bool active) : Window(name, std::nullopt,
        std::nullopt, std::nullopt, std::nullopt, flags, active)
    {

    }

    Window::Window(const std::string& name,
        std::optional<Math::Pos2Df> position,
        std::optional<Math::Size2Df> size,
        std::optional<Math::Size2Df> min_size,
        std::optional<Math::Size2Df> padding,
        WindowFlags flags, bool active, Graphics::Color
        background_color, bool allow_close) :
        active{ active }, name{ name }, position{ position },
        size{ size }, min_size{ min_size }, padding{ padding },
        begin_flags{}, background_color{ background_color },
        allow_close{ allow_close }, first_render{ true }
    {
        set_flags(flags);
    }

    Window::~Window()
    {

    }

    std::unique_ptr<Window::Scope> Window::render()
    {
        if (!active)
        {
            return nullptr;
        }

        if (first_render)
        {
            if (Core::Utils::EnumClass::has(
                flags, WindowFlags::FIT_TO_WINDOW))
            {
                ImGuiViewport* viewport = ::ImGui::GetMainViewport();
                ::ImGui::SetNextWindowPos(viewport->Pos);
                ::ImGui::SetNextWindowSize(viewport->Size);
            }

            if (Core::Utils::EnumClass::has(
                flags, WindowFlags::VIEWPORT_CENTER))
            {
                ::ImVec2 viewport_center =
                    ::ImGui::GetMainViewport()->GetCenter();
                ::ImGui::SetNextWindowPos(viewport_center, 0,
                    { 0.5f, 0.5f });
            }

            if (position)
            {
                ::ImGui::SetNextWindowPos(
                    { position.value().x, position.value().y });
            }
            
            if (size)
            {
                ::ImGui::SetNextWindowSize(
                    { size.value().width, size.value().height });
            }

            first_render = false;
        }

        ::ImGui::GetStyle().Colors[ImGuiCol_WindowBg] =
            { background_color.r, background_color.g, background_color.b,
            background_color.a };

        return std::make_unique<Window::Scope>(
            name.c_str(), begin_flags,
            allow_close ? &active : nullptr, min_size, padding);
    }

    void Window::set(const std::string& new_name,
        WindowFlags new_flags)
    {
        set_name(new_name);
        set_flags(new_flags);
    }

    void Window::set(const std::string& new_name,
        std::optional<Math::Pos2Df> new_position,
        std::optional<Math::Size2Df> new_size,
        WindowFlags new_flags)
    {
        set_name(new_name);
        set_position(new_position);
        set_size(new_size);
        set_flags(new_flags);
    }

    bool Window::get_active() const
    {
        return active;
    }

    void Window::set_active(bool new_active)
    {
        active = new_active;
    }

    void Window::set_name(const std::string& new_name)
    {
        name = new_name;
    }

    void Window::set_flags(WindowFlags new_flags)
    {
        begin_flags = ImGuiWindowFlags_None;
        flags = new_flags;

        if (Core::Utils::EnumClass::has(
            flags, WindowFlags::MINIMAL))
        {
            begin_flags |= ImGuiWindowFlags_NoDecoration |
                ImGuiWindowFlags_NoMove;
        }

        if (Core::Utils::EnumClass::has(flags,
            WindowFlags::NO_STORE_INI))
        {
            begin_flags |= ImGuiWindowFlags_NoSavedSettings;
        }

        if (Core::Utils::EnumClass::has(flags,
            WindowFlags::ALWAYS_VERTICAL_SCROLLBAR))
        {
            begin_flags |= ImGuiWindowFlags_AlwaysVerticalScrollbar;
        }

        if (Core::Utils::EnumClass::has(flags,
            WindowFlags::MENU_BAR))
        {
            begin_flags |= ImGuiWindowFlags_MenuBar;
        }

        if (Core::Utils::EnumClass::has(flags,
            WindowFlags::HORIZONTAL_SCROLLBAR))
        {
            begin_flags |= ImGuiWindowFlags_HorizontalScrollbar;
        }

        if (Core::Utils::EnumClass::has(flags,
            WindowFlags::NO_BACKGROUND))
        {
            begin_flags |= ImGuiWindowFlags_NoBackground;
        }

        if (Core::Utils::EnumClass::has(flags,
            WindowFlags::ALWAYS_AUTO_RESIZE))
        {
            begin_flags |= ImGuiWindowFlags_AlwaysAutoResize;
        }
    }

    void Window::set_position(
        std::optional<Math::Pos2Df> new_position)
    {
        position = new_position;
    }

    void Window::set_size(
        std::optional<Math::Size2Df> new_size)
    {
        size = new_size;
    }

    void Window::set_min_size(std::optional<Math::Size2Df> new_min_size)
    {
        min_size = new_min_size;
    }

    void Window::set_background_color(
        Graphics::Color new_background_color)
    {
        background_color = new_background_color;
    }

    void Window::set_padding(std::optional<Math::Size2Df> new_padding)
    {
        padding = new_padding;
    }

    void Window::set_allow_close(bool new_allow_close)
    {
        allow_close = new_allow_close;
    }

    void Window::reset_first_render()
    {
        first_render = true;
    }
}

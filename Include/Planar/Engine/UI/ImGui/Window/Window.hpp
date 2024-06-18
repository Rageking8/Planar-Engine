#pragma once

#include "Planar/Engine/Export/ExportMacros.hpp"
#include "Planar/Engine/UI/ImGui/Window/WindowFlags.hpp"
#include "Planar/Engine/Math/Pos2D.hpp"
#include "Planar/Engine/Math/Size2D.hpp"
#include "Planar/Engine/Graphics/Color.hpp"

#include <string>
#include <optional>
#include <memory>

#include "ThirdParty/ImGui/imgui.h"

namespace Planar::Engine::UI::ImGui::Window
{
    class PLANAR_API Window
    {
    public:
        struct PLANAR_API Scope
        {
            Scope(const char* name, ::ImGuiWindowFlags begin_flags,
                bool* open, std::optional<Math::Size2Df> min_size,
                std::optional<Math::Size2Df> padding);
            ~Scope();
        };

        Window(const std::string& name = "",
            WindowFlags flags = WindowFlags::NONE, bool active = true);
        Window(const std::string& name,
            std::optional<Math::Pos2Df> position,
            std::optional<Math::Size2Df> size,
            std::optional<Math::Size2Df> min_size,
            std::optional<Math::Size2Df> padding,
            WindowFlags flags = WindowFlags::NONE,
            bool active = true, Graphics::Color background_color =
            { 0.06f, 0.06f, 0.06f, 1.f }, bool allow_close = true);
        virtual ~Window();

        [[nodiscard("The destructor for this object ends the window")]]
        std::unique_ptr<Scope> render();

        void set(const std::string& new_name = "",
            WindowFlags new_flags = WindowFlags::NONE);
        void set(const std::string& new_name,
            std::optional<Math::Pos2Df> new_position,
            std::optional<Math::Size2Df> new_size,
            WindowFlags new_flags = WindowFlags::NONE);

        bool get_active() const;
        void set_active(bool new_active);

        void set_name(const std::string& new_name);
        void set_flags(WindowFlags new_flags);
        void set_position(std::optional<Math::Pos2Df> new_position);
        void set_size(std::optional<Math::Size2Df> new_size);
        void set_min_size(std::optional<Math::Size2Df> new_min_size);
        void set_background_color(Graphics::Color
            new_background_color);
        void set_padding(std::optional<Math::Size2Df> new_padding);
        void set_allow_close(bool new_allow_close);

        void reset_first_render();

    private:
        bool active;
        std::string name;
        std::optional<Math::Pos2Df> position;
        std::optional<Math::Size2Df> size;
        std::optional<Math::Size2Df> min_size;
        std::optional<Math::Size2Df> padding;
        WindowFlags flags;
        ::ImGuiWindowFlags begin_flags;
        Graphics::Color background_color;
        bool allow_close;
        bool first_render;
    };
}

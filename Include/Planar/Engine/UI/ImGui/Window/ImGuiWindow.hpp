#pragma once

#include "Planar/Engine/Export/ExportMacros.hpp"
#include "Planar/Engine/UI/ImGui/Window/ImGuiWindowFlags.hpp"
#include "Planar/Engine/Math/Pos2D.hpp"
#include "Planar/Engine/Math/Size2D.hpp"
#include "Planar/Engine/Graphics/Color.hpp"

#include <string>
#include <optional>
#include <memory>

#include "ThirdParty/ImGui/imgui.h"

namespace Planar::Engine::UI::ImGui::Window
{
    class PLANAR_API ImGuiWindow
    {
    public:
        struct PLANAR_API Scope
        {
            Scope(const char* name, ::ImGuiWindowFlags begin_flags,
                bool* open);
            ~Scope();
        };

        ImGuiWindow(const std::string& name = "",
            ImGuiWindowFlags flags = ImGuiWindowFlags::NONE);
        ImGuiWindow(const std::string& name,
            std::optional<Planar::Engine::Math::Pos2Df> position,
            std::optional<Planar::Engine::Math::Size2Df> size,
            ImGuiWindowFlags flags = ImGuiWindowFlags::NONE,
            Planar::Engine::Graphics::Color background_color =
            { 0.06f, 0.06f, 0.06f, 1.f }, bool allow_close = true);
        virtual ~ImGuiWindow();

        [[nodiscard("The destructor for this object ends the window")]]
        std::unique_ptr<Scope> render();

        void set(const std::string& new_name = "",
            ImGuiWindowFlags new_flags = ImGuiWindowFlags::NONE);
        void set(const std::string& new_name,
            std::optional<Planar::Engine::Math::Pos2Df> new_position,
            std::optional<Planar::Engine::Math::Size2Df> new_size,
            ImGuiWindowFlags new_flags = ImGuiWindowFlags::NONE);

        void set_active(bool new_active);
        void set_name(const std::string& new_name);
        void set_flags(ImGuiWindowFlags new_flags);
        void set_position(
            std::optional<Planar::Engine::Math::Pos2Df> new_position);
        void set_size(
            std::optional<Planar::Engine::Math::Size2Df> new_size);
        void set_background_color(Planar::Engine::Graphics::Color
            new_background_color);
        void set_allow_close(bool new_allow_close);

        void reset_first_render();

    private:
        bool active;
        std::string name;
        std::optional<Planar::Engine::Math::Pos2Df> position;
        std::optional<Planar::Engine::Math::Size2Df> size;
        ImGuiWindowFlags flags;
        ::ImGuiWindowFlags begin_flags;
        Planar::Engine::Graphics::Color background_color;
        bool allow_close;
        bool first_render;
    };
}
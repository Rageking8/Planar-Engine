#pragma once

#include "Planar/Engine/Core/ExportMacros.hpp"
#include "Planar/Engine/UI/ImGui/ImGuiWindowFlags.hpp"
#include "Planar/Engine/Math/Pos2D.hpp"
#include "Planar/Engine/Math/Size2D.hpp"

#include <string>
#include <optional>
#include <memory>

#include "ThirdParty/ImGui/imgui.h"

namespace Planar::Engine::UI::ImGui
{
    class PLANAR_API ImGuiWindow
    {
    public:
        struct PLANAR_API Scope
        {
            Scope(const char* name, ::ImGuiWindowFlags begin_flags);
            ~Scope();
        };

        ImGuiWindow(const std::string& name = "",
            ImGuiWindowFlags flags = ImGuiWindowFlags::NONE);
        ImGuiWindow(const std::string& name,
            std::optional<Planar::Engine::Math::Pos2Df> position,
            std::optional<Planar::Engine::Math::Size2Df> size,
            ImGuiWindowFlags flags = ImGuiWindowFlags::NONE);

        [[nodiscard("The destructor for this object ends the window")]]
        std::unique_ptr<Scope> render();

        void set(const std::string& new_name = "",
            ImGuiWindowFlags new_flags = ImGuiWindowFlags::NONE);
        void set(const std::string& new_name,
            std::optional<Planar::Engine::Math::Pos2Df> new_position,
            std::optional<Planar::Engine::Math::Size2Df> new_size,
            ImGuiWindowFlags new_flags = ImGuiWindowFlags::NONE);

        void set_name(const std::string& new_name);
        void set_flags(ImGuiWindowFlags new_flags);
        void set_position(
            std::optional<Planar::Engine::Math::Pos2Df> new_position);
        void set_size(
            std::optional<Planar::Engine::Math::Size2Df> new_size);

        void reset_first_render();

    private:
        std::string name;
        std::optional<Planar::Engine::Math::Pos2Df> position;
        std::optional<Planar::Engine::Math::Size2Df> size;
        ImGuiWindowFlags flags;
        ::ImGuiWindowFlags begin_flags;
        bool first_render;
    };
}

#include "Planar/Engine/UI/ImGui/ImGuiWindow.hpp"

namespace Planar::Engine::UI::ImGui
{
    ImGuiWindow::Scope::Scope(const char* name,
        ::ImGuiWindowFlags begin_flags, bool* open)
    {
        ::ImGui::Begin(name, open, begin_flags);
    }

    ImGuiWindow::Scope::~Scope()
    {
        ::ImGui::End();
    }

    ImGuiWindow::ImGuiWindow(const std::string& name,
        ImGuiWindowFlags flags) :
        ImGuiWindow(name, std::nullopt, std::nullopt, flags)
    {

    }

    ImGuiWindow::ImGuiWindow(const std::string& name,
        std::optional<Planar::Engine::Math::Pos2Df> position,
        std::optional<Planar::Engine::Math::Size2Df> size,
        ImGuiWindowFlags flags, bool allow_close) : active{ true },
        name{ name }, position{ position }, size{ size },
        begin_flags{}, allow_close{ allow_close }, first_render{ true }
    {
        set_flags(flags);
    }

    std::unique_ptr<ImGuiWindow::Scope> ImGuiWindow::render()
    {
        if (!active)
        {
            return nullptr;
        }

        if (first_render)
        {
            if (Planar::Engine::Core::Utils::has(
                flags, ImGuiWindowFlags::FIT_TO_WINDOW))
            {
                ImGuiViewport* viewport = ::ImGui::GetMainViewport();
                ::ImGui::SetNextWindowPos(viewport->Pos);
                ::ImGui::SetNextWindowSize(viewport->Size);
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

        return std::make_unique<ImGuiWindow::Scope>(
            name.c_str(), begin_flags,
            allow_close ? &active : nullptr);
    }

    void ImGuiWindow::set(const std::string& new_name,
        ImGuiWindowFlags new_flags)
    {
        set_name(new_name);
        set_flags(new_flags);
    }

    void ImGuiWindow::set(const std::string& new_name,
        std::optional<Planar::Engine::Math::Pos2Df> new_position,
        std::optional<Planar::Engine::Math::Size2Df> new_size,
        ImGuiWindowFlags new_flags)
    {
        set_name(new_name);
        set_position(new_position);
        set_size(new_size);
        set_flags(new_flags);
    }

    void ImGuiWindow::set_active(bool new_active)
    {
        active = new_active;
    }

    void ImGuiWindow::set_name(const std::string& new_name)
    {
        name = new_name;
    }

    void ImGuiWindow::set_flags(ImGuiWindowFlags new_flags)
    {
        begin_flags = ImGuiWindowFlags_None;
        flags = new_flags;

        if (Planar::Engine::Core::Utils::has(
            flags, ImGuiWindowFlags::MINIMAL))
        {
            begin_flags |= ImGuiWindowFlags_NoDecoration |
                ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoBackground;
        }

        if (Planar::Engine::Core::Utils::has(flags,
            ImGuiWindowFlags::NO_STORE_INI))
        {
            begin_flags |= ImGuiWindowFlags_NoSavedSettings;
        }
    }

    void ImGuiWindow::set_position(
        std::optional<Planar::Engine::Math::Pos2Df> new_position)
    {
        position = new_position;
    }

    void ImGuiWindow::set_size(
        std::optional<Planar::Engine::Math::Size2Df> new_size)
    {
        size = new_size;
    }

    void ImGuiWindow::set_allow_close(bool new_allow_close)
    {
        allow_close = new_allow_close;
    }

    void ImGuiWindow::reset_first_render()
    {
        first_render = true;
    }
}

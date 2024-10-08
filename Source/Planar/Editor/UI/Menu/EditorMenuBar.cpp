#include "Planar/Editor/UI/Menu/EditorMenuBar.hpp"
#include "Planar/Editor/UI/Window/InspectorWindow.hpp"
#include "Planar/Editor/UI/Window/Core/EditorWindowManager.hpp"
#include "Planar/Editor/Core/Editor.hpp"
#include "Planar/Engine/Core/Shell/Shell.hpp"
#include "Planar/Engine/UI/ImGui/ImGui.hpp"
#include "Planar/Engine/UI/ImGui/Menu/Menu.hpp"
#include "Planar/Engine/UI/ImGui/Menu/MainMenuBar.hpp"
#include "Planar/Engine/Component/Core/AllComponent.hpp"
#include "Planar/Engine/Component/Core/ComponentType.hpp"

#include <set>
#include <memory>

#define PLANAR_GET_WINDOW(type)                     \
    window_manager.get<Window::type##Window>(#type) \

#define PLANAR_ADD_COMPONENT_MENU_ITEM(type)            \
    add_component_menu_item<Engine::Component::type>(); \

namespace Planar::Editor::UI::Menu
{
    EditorMenuBar::EditorMenuBar(Core::Editor* editor,
        Window::Core::EditorWindowManager& window_manager) :
        editor{ editor }, window_manager{ window_manager }
    {

    }

    void EditorMenuBar::render()
    {
        using namespace Engine::UI;

        ImGui::Menu::MainMenuBar main_menu_bar;
        if (main_menu_bar.start())
        {
            main_menu_bar.add_menu("File",
                [&]()
                {
                    if (ImGui::Menu::menu_item("Select project"))
                    {

                    }

                    ImGui::separator();

                    if (ImGui::Menu::menu_item("Save", "Ctrl + S"))
                    {
                        editor->save_all();
                    }

                    ImGui::separator();

                    if (ImGui::Menu::menu_item("Exit"))
                    {
                        editor->exit();
                    }
                });

            main_menu_bar.add_menu("Build",
                [&]()
                {
                    window_menu_item("Build", "Build Project", true,
                        "Ctrl + B");
                });

            main_menu_bar.add_menu("Component",
                [&]()
                {
                    PLANAR_ALL_COMPONENT(PLANAR_ADD_COMPONENT_MENU_ITEM)

                    const std::set<std::string>& script_names = editor->
                        get_script_database().get_script_names();

                    if (!script_names.empty())
                    {
                        ImGui::separator();
                    }

                    for (const auto& i : script_names)
                    {
                        add_component_menu_item<
                            Engine::Component::Script>(i, i);
                    }
                });

            main_menu_bar.add_menu("Script",
                [&]()
                {
                    window_menu_item("CreateScript", "Create Script",
                        true);
                });

            main_menu_bar.add_menu("Asset",
                [&]()
                {
                    window_menu_item("AssetImport", "Asset Import",
                        true);
                });

            main_menu_bar.add_menu("Window",
                [&]()
                {
                    window_menu_item("Hierarchy");

                    ImGui::separator();

                    window_menu_item("Scene");
                    window_menu_item("Game");

                    ImGui::separator();

                    window_menu_item("Inspector");
                    window_menu_item("Settings");

                    ImGui::separator();

                    window_menu_item("Content");
                    window_menu_item("Console");
                });

            main_menu_bar.add_menu("Help",
                []()
                {
                    if (ImGui::Menu::menu_item("Website"))
                    {
                        Engine::Core::Shell::open_planar_website();
                    }
                });

            play_stop_toggle.render();
        }
    }

    Element::PlayStopToggle& EditorMenuBar::get_play_stop_toggle()
    {
        return play_stop_toggle;
    }

    void EditorMenuBar::window_menu_item(const std::string& name,
        const std::string& label, bool reset_first_render,
        const std::string& shortcut)
    {
        if (Engine::UI::ImGui::Menu::menu_item(
            label.empty() ? name : label, shortcut))
        {
            std::shared_ptr<Window::Core::EditorWindow> window =
                window_manager.get(name);

            window->set_active(true);

            if (reset_first_render)
            {
                window->reset_first_render();
            }
        }
    }

    template <typename ComponentT, typename... Args>
    void EditorMenuBar::add_component_menu_item(
        const std::string& name, Args&... args)
    {
        const std::string label_prefix = "Add ";

        if (Engine::UI::ImGui::Menu::menu_item(label_prefix +
            (name.empty() ? ComponentT::NAME : name)))
        {
            PLANAR_GET_WINDOW(Inspector)->
                add_component<ComponentT>(args...);
        }
    }
}

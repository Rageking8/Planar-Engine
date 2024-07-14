#pragma once

#include "Planar/Editor/UI/Window/EditorWindow.hpp"
#include "Planar/Editor/Core/Utils/Macros/DeclarationMacros.hpp"

#include <string>
#include <memory>
#include <concepts>
#include <unordered_map>

PLANAR_EDITOR_FORWARD_DECLARE_CLASS(Core, Editor)

namespace Planar::Editor::UI::Window
{
    class EditorWindowManager
    {
    public:
        EditorWindowManager(Core::Editor* editor);

        template <typename T>
            requires std::derived_from<T, EditorWindow>
        void create(const std::string& name);

        template <typename T>
            requires std::derived_from<T, EditorWindow>
        std::shared_ptr<T> get(const std::string& name);

        void init();
        void update();
        void render();

    private:
        Core::Editor* editor;

        std::unordered_map<std::string, std::shared_ptr<EditorWindow>>
            window_map;
    };
}

#include "Planar/Editor/UI/Window/EditorWindowManager.tpp"

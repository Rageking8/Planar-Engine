#include "Planar/Editor/Core/Editor.hpp"

int main()
{
    Planar::Editor::Core::Editor editor;

    if (!editor.init())
    {
        return -1;
    }

    editor.run();
}

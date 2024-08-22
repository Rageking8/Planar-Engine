#include "Planar/Editor/Core/Editor.hpp"

int main(int argc, char* argv[])
{
    Planar::Editor::Core::Editor editor;

    if (!editor.init())
    {
        return -1;
    }

    editor.run();
}

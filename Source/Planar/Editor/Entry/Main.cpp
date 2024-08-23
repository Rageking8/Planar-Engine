#include "Planar/Editor/Core/Editor.hpp"

int main(int argc, char* argv[])
{
    Planar::Editor::Core::Editor editor(argc, argv);

    return editor.start();
}

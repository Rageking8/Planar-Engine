#include <iostream>

#include <ThirdParty/GLFW/glfw3.h>

int main()
{
    if (!glfwInit())
    {
        std::cerr << "GLFW init failed\n";
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(1280, 720, "Hello Window",
        nullptr, nullptr);
    if (!window)
    {
        std::cerr << "Window creation failed\n";
    }

    glfwMakeContextCurrent(window);

    glfwSwapInterval(1);

    while (!glfwWindowShouldClose(window))
    {
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
}

#define GLFW_INCLUDE_NONE

#include "GLFW/glfw3.h"
#include "glad/glad.h"
#include <iostream>

int main()
{
    GLFWwindow *window;
    if (!glfwInit())
    {
        std::cout << "Could not initialize glfw" << std::endl;

        return -1;
    }

    window = glfwCreateWindow(800, 600, "Graphics Tinkering", NULL, NULL);

    if (!window)
    {
        std::cout << "Could not create window" << std::endl;

        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    int version = gladLoadGL();

    if (version == 0)
    {
        std::cout << "Failed to initialize OpenGL context\n" << std::endl;
        return -1;
    }

    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
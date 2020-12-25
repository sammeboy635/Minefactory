#include <stdlib.h>
#include <stdio.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <unistd.h>

#define GLFW_DLL

//sudo apt-get install libglfw3 libglfw3-dev
/*
void window_termination()
{
    glfwTerminate();
}

int main(void)
{
    GLFWwindow *window;
    if (!glfwInit())
    {
        return -1;
    }

    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!window)
    {
        window_termination();
    }

    glfwMakeContextCurrent(window);
    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    window_termination();
    return 0;
    printf("test");
}
*/
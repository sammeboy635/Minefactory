#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "linmath.h"
#include <stdio.h>
#include "cube.h"
#include "chunk.h"
int y = 0;
void controls(GLFWwindow *window, int key, int scancode, int action, int mods)
{
    if (action == GLFW_PRESS)
        if (key == GLFW_KEY_ESCAPE)
            glfwSetWindowShouldClose(window, GL_TRUE);
        else if (key == GLFW_KEY_W)
        {
            printf("W was hit");
        }
}

GLFWwindow *initWindow(const int resX, const int resY)
{
    if (!glfwInit())
    {
        fprintf(stderr, "Failed to initialize GLFW\n");
        return NULL;
    }
    glfwWindowHint(GLFW_SAMPLES, 4); // 4x antialiasing

    // Open a window and create its OpenGL context
    GLFWwindow *window = glfwCreateWindow(resX, resY, "TEST", NULL, NULL);

    if (window == NULL)
    {
        fprintf(stderr, "Failed to open GLFW window.\n");
        glfwTerminate();
        return NULL;
    }

    glfwMakeContextCurrent(window);
    glfwSetKeyCallback(window, controls);

    // Get info of GPU and supported OpenGL version
    printf("Renderer: %s\n", glGetString(GL_RENDERER));
    printf("OpenGL version supported %s\n", glGetString(GL_VERSION));

    glEnable(GL_DEPTH_TEST); // Depth Testing
    glDepthFunc(GL_LEQUAL);
    glDisable(GL_CULL_FACE);
    glCullFace(GL_BACK);
    return window;
}

void drawCube()
{
    cubeCalculation cc;
    Chunk chunk;
    cube_set_pos(&cc, 0, y, 0);
    cc.ptr = cube_vertices_calc(&cc.x, &cc.y, &cc.z, &cc.X, &cc.Y, &cc.Z);
    chunk_create_vertices(&chunk, &cc);
    /*GLshort vertices[] =
        {
            -1, -1, -1, -1, -1, 1, -1, 1, 1, -1, 1, -1,
            1, -1, -1, 1, -1, 1, 1, 1, 1, 1, 1, -1,
            -1, -1, -1, -1, -1, 1, 1, -1, 1, 1, -1, -1,
            -1, 1, -1, -1, 1, 1, 1, 1, 1, 1, 1, -1,
            -1, -1, -1, -1, 1, -1, 1, 1, -1, 1, -1, -1,
            -1, -1, 1, -1, 1, 1, 1, 1, 1, 1, -1, 1};
*/
    //cube_console_print(cc.ptr);
    GLfloat colors[] =
        {
            1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0,
            0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0,
            0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1,
            1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1,
            1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
            0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1};

    static float alpha = 0;
    //attempt to rotate cube
    glRotatef(alpha, 0, .5, 0); //Rotates cube
    /*vec4 m;
    mat4x4_identity(m);
    mat4x4_rotate_Y(m, m, (float)glfwGetTime());
    mat4x4_ortho(p, -ratio, ratio, -1.f, 1.f, 1.f, -1.f);
    mat4x4_mul(mvp, p, m);*/
    /* We have a color array and a vertex array */
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);
    glVertexPointer(3, GL_INT, 0, (GLint)chunk.vertices);
    //glColorPointer(3, GL_FLOAT, 0, colors);
    glColor3b(1, 1, 1);
    /* Send data : 24 vertices */
    glDrawArrays(GL_QUADS, 0, sizeof(chunk.vertices) / 12);

    /* Cleanup states */
    glDisableClientState(GL_COLOR_ARRAY);
    glDisableClientState(GL_VERTEX_ARRAY);
    alpha += 1;
}

void display(GLFWwindow *window)
{
    while (!glfwWindowShouldClose(window))
    {
        // Scale to window size
        GLint windowWidth, windowHeight;
        glfwGetWindowSize(window, &windowWidth, &windowHeight);
        glViewport(0, 0, windowWidth, windowHeight);

        // Draw stuff
        glClearColor(0.0, 0.0, 0.0, 0.0);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glMatrixMode(GL_PROJECTION_MATRIX);
        glLoadIdentity();
        gluPerspective(60, (double)windowWidth / (double)windowHeight, 0.1, 100);

        glMatrixMode(GL_MODELVIEW_MATRIX);

        //Changes location
        glTranslatef(0, 0, -5);

        //Enables only one side of the quad to be displayed
        glEnable(GL_CULL_FACE);
        glCullFace(GL_BACK);

        //Drawing cube function
        drawCube();

        // Update Screen
        glfwSwapBuffers(window);

        // Check for any input, or window movement
        glfwPollEvents();
    }
}

int main(int argc, char **argv)
{
    GLFWwindow *window = initWindow(1024, 620);
    if (NULL != window)
    {
        display(window);
    }
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}
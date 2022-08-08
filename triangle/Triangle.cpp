#include "Triangle.hpp"
#include <GLFW/glfw3.h>

#define WIDTH 1280
#define HEIGHT 720

GLFWwindow* InitDisplay(int width, int height)
{
        /* Initialize GLFW */
        glfwInit();
        /* Create and verify a GLFW window */
        GLFWwindow* window = glfwCreateWindow(width, height, "Triangle Test", nullptr, nullptr);
        assert(window != NULL);

        /* Make the window current, aka attach an OpenGL context to it */
        glfwMakeContextCurrent(window);
        return window;
}

void ExitProgram()
{
        /* Deattach the OpenGL context */
        glfwMakeContextCurrent(NULL);
        /* Terminate GLFW */
        glfwTerminate();
}

int main(int argc, char** argv)
{
        GLFWwindow* window = InitDisplay(WIDTH, HEIGHT);
        glewInit(); /* Initialize OpenGL functions */

        /* Our triangle buffer coordinates */
        float positions[] = {
                -0.5f, -0.5f, 0.0f,
                 0.0f,  0.5f, 0.0f,
                 0.5f, -0.5f, 0.0f,
        };

        /* Generating and selecting the buffer */
        unsigned int buffer;
        glGenBuffers(1, &buffer);
        glBindBuffer(GL_ARRAY_BUFFER, buffer);

        /* Supplying the buffer with the required data */
        glBufferData(GL_ARRAY_BUFFER, sizeof(positions), positions, GL_STATIC_DRAW);
        glEnableVertexAttribArray(0);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(positions) / 3, nullptr);

        /* Setting the cleanup color */
        glClearColor(1.0f, 0.0f, 0.0f, 1.0f);

        /*
         * Normally we would add here a shader to
         * ensure our triangle displays everywhere,
         * but it isn't required yet so we will avoid it.
        */

        /* Polling for events */
        while (!glfwWindowShouldClose(window))
        {
                glClear(GL_COLOR_BUFFER_BIT);

                glDrawArrays(GL_TRIANGLES, 0, 3);

                glfwSwapBuffers(window);
                glfwPollEvents();
        }

}
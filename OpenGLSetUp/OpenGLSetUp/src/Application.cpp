#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>




int main(void)
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;



    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(1200, 1200, "House Outline", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);
    /*Always call glewInit functions after this line of code*/



    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);
        glClearColor(1, 1, 1, 1);

       



        

        glBegin(GL_LINE_LOOP);
        glColor3f(0, 0, 0);
        glVertex2f(-0.8f, 0.2f);
        glVertex2f(-0.8f, 0.0f);
        glVertex2f(-0.7f, 0.0f);
        glVertex2f(-0.7f, -0.9f);
        glVertex2f(0.6f, -0.9f);
        glVertex2f(0.6f, -0.0f);
        glVertex2f(0.7f, 0.0f);
        glVertex2f(0.7f, 0.2f);
        glEnd();

        glBegin(GL_POINTS); // render with points
        glVertex2i(50, 40); //display a point
        glEnd();
        glPointSize(10.0);




        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
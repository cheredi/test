#include<glew.h>
#include<GLFW/glfw3.h>
#include<math.h>

#include <iostream>




int main(void)
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;



    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(700, 500, "Crescent", NULL, NULL);
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
        glBegin(GL_POLYGON);
        glColor3f(1.0, 1.0, 0); // Middle circle
        double radius = 0.45;
        double ori_x = 0.15;                         // the origin or center of circle
        double ori_y = 0.3;
        for (int i = 0; i <= 500; i++) {
            double angle = 2 * 3.412 * i / 500;
            double x = cos(angle) * radius;
            double y = sin(angle) * radius;
            glVertex2d(ori_x + x, ori_y + y);
        }
        glEnd();

        glBegin(GL_POLYGON);
        glColor3f(0, 0, 0); // Middle circle
        double radius1 = 0.5;
        double ori_x1 = 0.45;                         // the origin or center of circle
        double ori_y1 = 0.3;
        for (int i = 0; i <= 300; i++) {
            double angle = 2 * 3.412 * i / 300;
            double x1 = cos(angle) * radius1;
            double y1 = sin(angle) * radius1;
            glVertex2d(ori_x1 + x1, ori_y1 + y1);
        }
        glEnd();

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }
    glfwTerminate();
    return 0;
}

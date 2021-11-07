#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <math.h>
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
        
         glLineWidth(3);
        glBegin(GL_LINE_LOOP);
        glClearColor(1, 1, 1, 1);
        glVertex2f(-0.25f, -0.2f);
        glVertex2f(0.1f, -0.2f);
        glVertex2f(0.1f, -0.8f);
        glVertex2f(-0.25f, -0.8f);
        glEnd();
        
        glBegin(GL_POLYGON);
        glColor3f( 0, 0, 1 ); // Middle circle
        double radius = 0.02;
        double ori_x = 0.05;                         // the origin or center of circle
        double ori_y = -0.5;
        for (int i = 0; i <= 300; i++) {
            double angle = 2 * 3.412 * i / 300;
            double x = cos(angle) * radius;
            double y = sin(angle) * radius;
            glVertex2d(ori_x + x, ori_y + y);
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

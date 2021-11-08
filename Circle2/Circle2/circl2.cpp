#include<glew.h>
#include<glfw3.h>
#include<math.h>

#include<iostream>

int main(void)
{
	GLFWwindow* window;

	/* Initialize the library */
	if (!glfwInit())
		return -1;



	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(700, 500, "Circle", NULL, NULL);
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

		void circle();
		{
			glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);
			int number = 40;//number of vertices
			float radius = 0.4f;
			float twopi = 2.0 * 3.1452423;
			glMatrixMode(GL_MODELVIEW);
			glLoadIdentity();

			glBegin(GL_TRIANGLE_FAN);
			glColor3f(1.0f, 1.0f, 1.0f);
			glVertex2f(0.0f, 0.0f);
			for (int i = 0; i <= 20; i++)
				glVertex2f(radius * cosf(i * twopi / number), radius * sinf(i * twopi / number));
			glEnd();
			glFlush();

			/* Swap front and back buffers */
			glfwSwapBuffers(window);

			/* Poll for and process events */
			glfwPollEvents();
		}


	}
	glfwTerminate();
	return 0;
}
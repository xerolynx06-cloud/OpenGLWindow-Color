#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

using namespace std;

int main(void) {

	if (!glfwInit()) {

		cout << "Failed to Initialize";

		return -1;
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);  
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	glfwWindow* window = glfwCreateWindow(800, 800, "OpenGL Window",NULL,NULL); 

	if (window == NULL) {

		cout << "Window Creation Failed";

		glfwTerminate();

		return -1;

		}
	glfwMakeContextCurrent(window);
	
	if (!gladLoadGLLoader((GLADloadProc)glfwGetProcAddress)) {

		cout << "GLAD Initialization Failed";

		return -1;

	}
	glViewport(0, 0, 800, 800);

	while (!glfwWindowShouldClose(window)) {

		glfwPollEvents();

		glClearColor(0.0f, 0.0f, 1.0f, 1.0f);//Blue Colour

		glClear(GL_COLOR_BUFFER_BIT);

		glfwSwapBuffers(window);
	}

	glfwDestroyWindow(window);

	glfwTerminate();

	return 0;

}

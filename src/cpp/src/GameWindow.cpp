#include "GameWindow.h"

GameWindow::GameWindow()
{
	width = 640;
	height = 480;
	title = "Nytram Window";

	// Initialise GLFW
	if( !glfwInit() )
	{
		cerr << "Failed to initialize GLFW." << endl;
		// Throw an exception...
	}

	glfwWindowHint(GLFW_SAMPLES, 4);
	glfwWindowHint(GLFW_RESIZABLE,GL_FALSE);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}

int GameWindow::open()
{
	window = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);
	if( window == NULL ){
		cerr << "Failed to open GLFW window." << endl;
		glfwTerminate();
		// Throw an exception...
		return -1;
	}
	glfwMakeContextCurrent(window);
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	return 0;
}

void GameWindow::clear()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void GameWindow::swapBuffers()
{
	glfwSwapBuffers(window);
}

int GameWindow::shouldClose()
{
	return glfwWindowShouldClose(window);
}

void GameWindow::quit()
{
    glfwSetWindowShouldClose(window, true);
}

void GameWindow::setTitle(const char* newTitle)
{
	title = newTitle;
}

void GameWindow::setSize(int newWidth, int newHeight)
{
    width = newWidth;
	height = newHeight;
}
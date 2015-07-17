#include "GameLoop.h"

GameLoop::GameLoop(GameWindow* window, InputHandler* inputHandler)
{
	this->gameWindow = window;
	this->inputHandler = inputHandler;
}

void GameLoop::run(Scene& scene)
{
	frameLimiter.start();
	
	while (!gameWindow->shouldClose())
    {
		gameWindow->clear();
		inputHandler->processEvents();
		scene.update();
		scene.draw();
		gameWindow->swapBuffers();
		frameLimiter.enforceFrameLimit();
    }
	glfwTerminate();
}

void GameLoop::stop()
{
	gameWindow->quit();
}
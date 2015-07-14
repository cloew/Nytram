#include "GameLoop.h"

GameLoop::GameLoop(GameWindow* window, InputHandler* inputHandler)
{
	this->gameWindow = window;
	this->inputHandler = inputHandler;
}

void GameLoop::run(GameLoop_Callback callback, Scene& scene)
{
	frameLimiter.start();
	
	while (!gameWindow->shouldClose())
    {
		callback();
		scene.draw();
		gameWindow->swapBuffers();
		inputHandler->processEvents();
		frameLimiter.enforceFrameLimit();
    }
	glfwTerminate();
}

void GameLoop::stop()
{
	gameWindow->quit();
}
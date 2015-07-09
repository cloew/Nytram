#include "GameLoop.h"

GameLoop::GameLoop(GameWindow* window, InputHandler* inputHandler)
{
	this->gameWindow = window;
	this->inputHandler = inputHandler;
}

void GameLoop::run(GameLoop_Callback callback)
{
	gameWindow->open();
	inputHandler->bindCallbacks();
	frameLimiter.start();
	
	while (!gameWindow->shouldClose())
    {
		callback();
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
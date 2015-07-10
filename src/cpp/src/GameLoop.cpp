#include "GameLoop.h"

GameLoop::GameLoop(GameWindow* window, Graphics* graphics, InputHandler* inputHandler)
{
	this->gameWindow = window;
	this->graphics = graphics;
	this->inputHandler = inputHandler;
}

void GameLoop::run(GameLoop_Callback callback)
{
	gameWindow->open();
	graphics->initialize();
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
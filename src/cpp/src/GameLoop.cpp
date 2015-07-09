#include "GameLoop.h"

GameLoop::GameLoop(GameWindow* window)
{
	gameWindow = window;
}

void GameLoop::run(GameLoop_Callback callback)
{
	gameWindow->open();
	frameLimiter.start();
	
	while (!gameWindow->shouldClose())
    {
		callback();
		gameWindow->processEvents();
		frameLimiter.enforceFrameLimit();
    }
	glfwTerminate();
}

void GameLoop::stop()
{
	gameWindow->quit();
}
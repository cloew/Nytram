#include "GameEngine.h"

GameEngine::GameEngine()
{
	inputHandler = InputHandler(&gameWindow);
	loop = GameLoop(&gameWindow, &graphics, &inputHandler);
}

void GameEngine::run(GameLoop_Callback callback)
{
	gameWindow.open();
	graphics.initialize();
	inputHandler.bindCallbacks();

	shaderManager.compileShaders();

	loop.run(callback);
}

void GameEngine::stop()
{
	loop.stop();
}
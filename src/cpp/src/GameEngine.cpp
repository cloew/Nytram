#include "GameEngine.h"

GameEngine::GameEngine()
{
	inputHandler = InputHandler(&gameWindow);
	loop = GameLoop(&gameWindow, &inputHandler);
}

void GameEngine::run(GameLoop_Callback callback)
{
	gameWindow.open();
	graphics.initialize();
	inputHandler.bindCallbacks();

	loop.run(callback, scene);
}

void GameEngine::stop()
{
	loop.stop();
}

GLuint GameEngine::addRendererToEntity(GLuint entityId)
{
	return graphics.addRendererToEntity(scene.getEntity(entityId));
}
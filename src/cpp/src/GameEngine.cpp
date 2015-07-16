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
	scene.initialize();
	inputHandler.bindCallbacks();

	loop.run(callback, scene);
}

void GameEngine::stop()
{
	loop.stop();
}

void GameEngine::addRendererToEntity(GLuint entityId, GLuint rendererId)
{
	graphics.addRendererToEntity(scene.getEntity(entityId), rendererId);
}
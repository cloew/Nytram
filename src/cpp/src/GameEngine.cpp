#include "GameEngine.h"

GameEngine::GameEngine()
{
	inputHandler = InputHandler(&gameWindow);
	loop = GameLoop(&gameWindow, &inputHandler);
}

void GameEngine::run()
{
	gameWindow.open();
	graphics.initialize();
	scene.initialize();
	inputHandler.bindCallbacks();

	loop.run(scene);
}

void GameEngine::stop()
{
	loop.stop();
}

void GameEngine::translateEntity(GLuint entityId, const vec3& translation)
{
	scene.getEntity(entityId).translate(translation);
}

void GameEngine::addRendererToEntity(GLuint entityId, GLuint rendererId)
{
	graphics.addRendererToEntity(scene.getEntity(entityId), rendererId);
}
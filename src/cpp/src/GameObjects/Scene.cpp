#include "Scene.h"

GLuint Scene::addEntity()
{
	entities.push_back(Entity());
	return entities.size();
}

void Scene:: initialize()
{
	camera.initialize();
	
	if (startCallback)
	{
		startCallback();
	}

	for (auto &entity : entities)
	{
		entity.start();
	}
}

void Scene::update()
{
	if (updateCallback)
	{
		updateCallback();
	}

	for (auto &entity : entities)
	{
		entity.update();
	}
}

void Scene::draw()
{
	for (auto &entity : entities)
	{
		entity.draw(camera.getVP());
	}
}
#include "Scene.h"

GLuint Scene::addEntity()
{
	entities.push_back(Entity());
	return entities.size();
}

void Scene::draw()
{
	for (auto &entity : entities)
	{
		entity.draw();
	}
}
#pragma once

#include "Entity.h"

#include <vector>
using namespace std;

class Scene
{
public:
	GLuint addEntity();
	void draw();

	// Getters
	Entity& getEntity(GLuint entityId) {return entities[entityId-1];}

private:
	vector<Entity> entities;
};


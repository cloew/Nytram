#include "Entity.h"

void Entity::update()
{
	updateCallback();
}

void Entity::draw(const mat4& vp)
{
	drawCallback(vp*transform.getModelMatrix());
}
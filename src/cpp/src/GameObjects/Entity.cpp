#include "Entity.h"

void Entity::draw(const mat4& vp)
{
	drawCallback(vp*model);
}
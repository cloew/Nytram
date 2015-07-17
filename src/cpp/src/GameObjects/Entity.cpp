#include "Entity.h"

void Entity::start()
{
	if (startCallback)
	{
		startCallback();
	}
}

void Entity::update()
{
	if (updateCallback)
	{
		updateCallback();
	}
}

void Entity::draw(const mat4& vp)
{
	if (drawCallback)
	{
		drawCallback(vp*transform.getModelMatrix());
	}
}
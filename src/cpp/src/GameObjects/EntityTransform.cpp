#include "EntityTransform.h"

void EntityTransform::translate(const vec3& translation)
{
	model = glm::translate(translation);
}
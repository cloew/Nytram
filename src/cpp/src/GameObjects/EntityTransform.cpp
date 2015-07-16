#include "EntityTransform.h"

void EntityTransform::rotateInXY(GLfloat angleInDegrees)
{
	this->rotation.z = angleInDegrees;
	buildModelMatrix();
}

void EntityTransform::rotateInYZ(GLfloat angleInDegrees)
{
	this->rotation.x = angleInDegrees;
	buildModelMatrix();
}

void EntityTransform::rotateInXZ(GLfloat angleInDegrees)
{
	this->rotation.y = angleInDegrees;
	buildModelMatrix();
}

void EntityTransform::translate(const vec3& translation)
{
	this->translation = translation;
	buildModelMatrix();
}

void EntityTransform::buildModelMatrix()
{
	model = mat4(1.0f);
	model = glm::translate(model, translation);
	model = glm::rotate(model, rotation.x, vec3(1, 0, 0));
	model = glm::rotate(model, rotation.y, vec3(0, 1, 0));
	model = glm::rotate(model, rotation.z, vec3(0, 0, 1));
}
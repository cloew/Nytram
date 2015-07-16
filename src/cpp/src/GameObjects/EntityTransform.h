#pragma once

#include "IncludeGL.h"

#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/matrix_transform.hpp>

using namespace glm;

class EntityTransform
{
public:
	
	void rotateInXY(GLfloat angleInDegrees);
	void rotateInYZ(GLfloat angleInDegrees);
	void rotateInXZ(GLfloat angleInDegrees);
	void translate(const vec3& translation);

	// Getters
	const mat4& getModelMatrix() {return model;}

private:
	mat4 model;
	vec3 rotation;
	vec3 translation;

	void buildModelMatrix();
};


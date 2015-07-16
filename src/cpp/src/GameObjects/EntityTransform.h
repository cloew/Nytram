#pragma once

#include "IncludeGL.h"

#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/matrix_transform.hpp>

using namespace glm;
using namespace std;

class EntityTransform
{
public:
	EntityTransform() {scaling = vec3(1, 1, 1);}

	void rotateInXY(GLfloat angleInDegrees);
	void rotateInYZ(GLfloat angleInDegrees);
	void rotateInXZ(GLfloat angleInDegrees);
	void scale(const vec3& translation);
	void translate(const vec3& translation);

	// Getters
	const mat4& getModelMatrix() {return model;}

private:
	mat4 model;
	vec3 rotation;
	vec3 scaling;
	vec3 translation;

	void buildModelMatrix();
};
#pragma once

#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/matrix_transform.hpp>

using namespace glm;

class EntityTransform
{
public:

	void translate(const vec3& translation);

	// Getters
	const mat4& getModelMatrix() {return model;}

private:
	mat4 model;
};


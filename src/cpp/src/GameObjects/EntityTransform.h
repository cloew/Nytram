#pragma once

#include <glm/glm.hpp>

using namespace glm;

class EntityTransform
{
public:
	const mat4& getModelMatrix() {return model;}

private:
	mat4 model;
};


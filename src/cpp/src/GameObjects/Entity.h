#pragma once

#include "EntityTransform.h"
#include "Graphics/GLVertexArray.h"
#include "Shaders/ShaderProgram.h"

#include <functional>

#include <glm/glm.hpp>

using namespace glm;
using namespace std;

typedef std::function<void(const mat4&)> Draw_Callback;

class Entity
{
public:
	void draw(const mat4& vp);
	
	// Transform
	void translate(const vec3& translation) {transform.translate(translation);}

	// Setters
	void setDrawCallback(Draw_Callback drawCallback) {this->drawCallback = drawCallback;}

private:
	EntityTransform transform;
	Draw_Callback drawCallback;
};


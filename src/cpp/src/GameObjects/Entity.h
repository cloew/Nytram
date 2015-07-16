#pragma once

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
	Entity() {model = mat4(1.0f);}

	void draw(const mat4& vp);
	
	// Setters
	void setDrawCallback(Draw_Callback drawCallback) {this->drawCallback = drawCallback;}

private:
	mat4 model;
	Draw_Callback drawCallback;
};


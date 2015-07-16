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
	void rotateInXY(GLfloat angleInDegrees) {transform.rotateInXY(angleInDegrees);}
	void rotateInYZ(GLfloat angleInDegrees) {transform.rotateInYZ(angleInDegrees);}
	void rotateInXZ(GLfloat angleInDegrees) {transform.rotateInXZ(angleInDegrees);}
	void scale(const vec3& scaling) {transform.scale(scaling);}
	void translate(const vec3& translation) {transform.translate(translation);}

	// Setters
	void setDrawCallback(Draw_Callback drawCallback) {this->drawCallback = drawCallback;}

private:
	EntityTransform transform;
	Draw_Callback drawCallback;
};


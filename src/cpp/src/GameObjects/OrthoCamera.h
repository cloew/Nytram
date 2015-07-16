#pragma once

#include "IncludeGL.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/transform.hpp>
using namespace glm;

class OrthoCamera
{
public:
	OrthoCamera();

	void initialize();

	// Getters
	const mat4& getVP() {return vp;}

	// Setters
	void setEye(const vec3& eye) {this->eye = eye;}
	void setProjection(GLfloat width, GLfloat height, GLfloat nearClip, GLfloat farClip);

private:
	vec3 eye;
	GLfloat width;
	GLfloat height;
	GLfloat nearClip;
	GLfloat farClip;

	mat4 projection;
	mat4 view;
	mat4 vp;
};


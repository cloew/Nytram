#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/transform.hpp>
using namespace glm;

class OrthoCamera
{
public:
	void initialize();

	// Getters
	const mat4& getVP() {return vp;}

private:
	mat4 projection;
	mat4 view;
	mat4 vp;
};


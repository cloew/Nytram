#pragma once

#include "Entity.h"
#include "OrthoCamera.h"

#include <vector>
using namespace std;

class Scene
{
public:
	GLuint addEntity();
	void initialize();
	void draw();

	// Getters
	Entity& getEntity(GLuint entityId) {return entities[entityId-1];}

	// Setters
	void setEye(const vec3& eye) {camera.setEye(eye);}
	void setProjection(GLfloat width, GLfloat height, GLfloat nearClip, GLfloat farClip) {camera.setProjection(width, height, nearClip, farClip);}

private:
	vector<Entity> entities;
	OrthoCamera camera;
};
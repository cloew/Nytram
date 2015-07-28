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
	void update();
	void draw();

	// Getters
	Entity& getEntity(GLuint entityId) {return entities[entityId-1];}

	// Setters
	void setStartCallback(Start_Callback startCallback) {this->startCallback = startCallback;}
	void setUpdateCallback(Update_Callback updateCallback) {this->updateCallback = updateCallback;}
	void setEye(const vec3& eye) {camera.setEye(eye);}
	void setProjection(GLfloat width, GLfloat height, GLfloat nearClip, GLfloat farClip) {camera.setProjection(width, height, nearClip, farClip);}

private:
	vector<Entity> entities;
	OrthoCamera camera;
	Start_Callback startCallback;
	Update_Callback updateCallback;
};
#pragma once

#include "EntityTransform.h"
#include "Graphics/GLVertexArray.h"
#include "Shaders/ShaderProgram.h"

#include <functional>

#include <glm/glm.hpp>

using namespace glm;
using namespace std;

typedef std::function<void(const mat4&)> Draw_Callback;
typedef std::function<void()> Start_Callback;
typedef std::function<void()> Update_Callback;

class Entity
{
public:
	void start();
	void update();
	void draw(const mat4& vp);
	
	// Transform
	void rotateInXY(GLfloat angleInDegrees) {transform.rotateInXY(angleInDegrees);}
	void rotateInYZ(GLfloat angleInDegrees) {transform.rotateInYZ(angleInDegrees);}
	void rotateInXZ(GLfloat angleInDegrees) {transform.rotateInXZ(angleInDegrees);}
	void scale(const vec3& scaling) {transform.scale(scaling);}
	void translate(const vec3& translation) {transform.translate(translation);}

	// Setters
	void setDrawCallback(Draw_Callback drawCallback) {this->drawCallback = drawCallback;}
	void setStartCallback(Start_Callback startCallback) {this->startCallback = startCallback;}
	void setUpdateCallback(Update_Callback updateCallback) {this->updateCallback = updateCallback;}

private:
	EntityTransform transform;
	Draw_Callback drawCallback;
	Update_Callback startCallback;
	Update_Callback updateCallback;
};
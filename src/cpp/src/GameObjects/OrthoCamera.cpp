#include "OrthoCamera.h"

OrthoCamera::OrthoCamera()
{
	setEye(vec3(0, 0, 10));
	setProjection(2, 2, 1, 100);
}

void OrthoCamera::initialize()
{
	projection = ortho(-width/2, width/2, -height/2, height/2, nearClip, farClip);
	view = lookAt(
		eye,
		vec3(eye.x, eye.y, 0),
		vec3(0,1,0)
	);
	vp = projection*view;
}

void OrthoCamera::setProjection(GLfloat width, GLfloat height, GLfloat nearClip, GLfloat farClip)
{
	this->width = width;
	this->height = height;
	this->nearClip = nearClip;
	this->farClip = farClip;
}
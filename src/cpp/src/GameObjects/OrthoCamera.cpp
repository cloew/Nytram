#include "OrthoCamera.h"

void OrthoCamera::initialize()
{
	projection = ortho(-2.0f, 2.0f, -2.0f, 2.0f, 1.0f, 100.0f);
	view = lookAt(
		vec3(0,0,10),
		vec3(0,0,0),
		vec3(0,1,0)
	);
	vp = projection*view;
}
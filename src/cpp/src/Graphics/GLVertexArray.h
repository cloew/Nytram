#pragma once

#include "IncludeGL.h"

class GLVertexArray
{
public:
	GLVertexArray();
	~GLVertexArray();

	void makeCurrent();

private:
	GLuint vertexArrayId;
};


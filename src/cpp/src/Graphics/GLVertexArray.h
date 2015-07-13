#pragma once

#include "IncludeGL.h"

class GLVertexArray
{
public:
	GLVertexArray();
	~GLVertexArray();

	void initialize();
	bool isInitialized() {return vertexArrayId != NULL;}
	void makeCurrent();

private:
	GLuint vertexArrayId;
};


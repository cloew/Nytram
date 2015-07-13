#include "GLVertexArray.h"

GLVertexArray::GLVertexArray()
{
	vertexArrayId = NULL;
}

GLVertexArray::~GLVertexArray()
{
	if (isInitialized())
	{
		glDeleteVertexArrays(1, &vertexArrayId);
	}
}

void GLVertexArray::initialize()
{
	glGenVertexArrays(1, &vertexArrayId);
}

void GLVertexArray::makeCurrent()
{
	if (!isInitialized())
	{
		initialize();
	}
	glBindVertexArray(vertexArrayId);
}
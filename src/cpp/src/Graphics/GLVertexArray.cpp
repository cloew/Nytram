#include "GLVertexArray.h"

GLVertexArray::GLVertexArray()
{
	glGenVertexArrays(1, &vertexArrayId);
}

GLVertexArray::~GLVertexArray()
{
	glDeleteVertexArrays(1, &vertexArrayId);
}

void GLVertexArray::makeCurrent()
{
	glBindVertexArray(vertexArrayId);
}
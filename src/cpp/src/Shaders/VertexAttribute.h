#pragma once

#include "IncludeGL.h"
#include "Graphics/GLBuffer.h"

class VertexAttribute
{
public:
	VertexAttribute(GLuint index);

	void bind(GLBuffer& buffer, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const GLvoid* pointer);

private:
	GLuint index;
};


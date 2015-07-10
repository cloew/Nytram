#include "VertexAttribute.h"

VertexAttribute::VertexAttribute()
{
	index = 0;
}

VertexAttribute::VertexAttribute(GLuint index)
{
	this->index = index;
}

void VertexAttribute::bind(GLBuffer& buffer, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const GLvoid* pointer)
{
	buffer.makeCurrent();
	glVertexAttribPointer(index, size, type, normalized, stride, pointer);
	glEnableVertexAttribArray(index);
}
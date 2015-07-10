#include "GLBuffer.h"

GLBuffer::GLBuffer(GLenum target)
{
	this->target = target;
	glGenBuffers(1, &bufferId);
}

GLBuffer::~GLBuffer()
{
	glDeleteBuffers(1, &bufferId);
}

void GLBuffer::setData(GLsizeiptr size, const GLvoid* data, GLenum usage)
{
	glBindBuffer(target, bufferId);
	glBufferData(target, size, data, usage);
}
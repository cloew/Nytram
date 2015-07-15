#include "GLBuffer.h"

GLBuffer::GLBuffer(GLenum target)
{
	bufferId = NULL;
	this->target = target;
}

GLBuffer::~GLBuffer()
{
	if (isInitialized())
	{
		glDeleteBuffers(1, &bufferId);
	}
}

void GLBuffer::initialize()
{
	glGenBuffers(1, &bufferId);
}

void GLBuffer::makeCurrent()
{
	if (!isInitialized())
	{
		initialize();
	}
	glBindBuffer(target, bufferId);
}

void GLBuffer::setData(GLsizeiptr size, const GLvoid* data, GLenum usage)
{
	makeCurrent();
	glBufferData(target, size, data, usage);
}
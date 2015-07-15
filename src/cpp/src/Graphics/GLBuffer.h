#pragma once

#include "IncludeGL.h"

#include <iostream>
#include <vector>

using namespace std;

class GLBuffer
{
public:
	GLBuffer(GLenum target);
	~GLBuffer();
	
	void initialize();
	bool isInitialized() {return bufferId != NULL;}
	void makeCurrent();
	void setData(vector<GLfloat> data, GLenum usage); // Note: This will cause this buffer to become the current buffer for its target
	void setData(GLsizeiptr size, const GLvoid* data, GLenum usage); // Note: This will cause this buffer to become the current buffer for its target

	// Getters
	GLuint getId() {return bufferId;}

private:
	GLuint bufferId;
	GLenum target;
};


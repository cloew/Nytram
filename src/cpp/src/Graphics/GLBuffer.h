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
	void setData(GLsizeiptr size, const GLvoid* data, GLenum usage); // Note: This will cause this buffer to become the current buffer for its target

	template <typename T> // Note: This will cause this buffer to become the current buffer for its target
	void setData(vector<T> data, GLenum usage)
	{
		setData(data.size() * sizeof(T), &data[0], usage);
	}

	// Getters
	GLuint getId() {return bufferId;}

private:
	GLuint bufferId;
	GLenum target;
};


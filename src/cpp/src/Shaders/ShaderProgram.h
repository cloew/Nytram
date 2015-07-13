#pragma once

#include "IncludeGL.h"
#include "Shader.h"
#include "VertexAttribute.h"

#include <map>
#include <vector>

using namespace std;

class ShaderProgram
{
public:
	ShaderProgram() {programId = NULL;}
	~ShaderProgram();

	void initialize(vector<Shader*> shaders);
	void use();
	VertexAttribute* getAttribute(GLuint index);
	void setUniformValue(const char* name, GLfloat x, GLfloat y, GLfloat z);

private:
	GLuint programId;
	map<GLuint, VertexAttribute> indexToAttribute;
};
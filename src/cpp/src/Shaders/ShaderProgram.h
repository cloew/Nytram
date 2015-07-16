#pragma once

#include "IncludeGL.h"
#include "Shader.h"
#include "VertexAttribute.h"

#include <map>
#include <vector>
#include <glm/glm.hpp>

using namespace glm;
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
	void setUniformValue(const char* name, const mat4& matrix);

private:
	GLuint programId;
	map<GLuint, VertexAttribute> indexToAttribute;
};
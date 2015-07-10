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
	ShaderProgram(vector<Shader*> shaders);
	~ShaderProgram();

	void use();
	VertexAttribute* getAttribute(GLuint index);

private:
	GLuint programId;
	map<GLuint, VertexAttribute> indexToAttribute;
};
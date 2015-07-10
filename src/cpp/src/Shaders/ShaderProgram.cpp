#include "ShaderProgram.h"

ShaderProgram::ShaderProgram(vector<Shader*> shaders)
{
	programId = glCreateProgram();
	for (GLuint i = 0; i < shaders.size(); i++)
	{
		glAttachShader(programId, shaders[i]->getShaderId());
	}
	glLinkProgram(programId);
}

ShaderProgram::~ShaderProgram()
{
	glDeleteProgram(programId);
}

void ShaderProgram::use()
{
	glUseProgram(programId);
}

VertexAttribute* ShaderProgram::getAttribute(GLuint index)
{
	if (indexToAttribute.find(index) == indexToAttribute.end())
	{
		VertexAttribute newAttribute(index);
		indexToAttribute[index] = newAttribute;
	}

	return &indexToAttribute[index];
}
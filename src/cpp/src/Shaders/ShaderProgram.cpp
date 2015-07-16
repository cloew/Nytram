#include "ShaderProgram.h"

ShaderProgram::~ShaderProgram()
{
	if (programId != NULL)
	{
		glDeleteProgram(programId);
	}
}

void ShaderProgram::initialize(vector<Shader*> shaders)
{
	programId = glCreateProgram();
	for (GLuint i = 0; i < shaders.size(); i++)
	{
		glAttachShader(programId, shaders[i]->getShaderId());
	}
	glLinkProgram(programId);
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

void ShaderProgram::setUniformValue(const char* name, GLfloat x, GLfloat y, GLfloat z)
{
	GLint uniformId = glGetUniformLocation(programId, name);
	glUniform3f(uniformId, x, y, z);
}

void ShaderProgram::setUniformValue(const char* name, const mat4& matrix)
{
	GLint uniformId = glGetUniformLocation(programId, name);
	glUniformMatrix4fv(uniformId, 1, GL_FALSE, &matrix[0][0]);
}
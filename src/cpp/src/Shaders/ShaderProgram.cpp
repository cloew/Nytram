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
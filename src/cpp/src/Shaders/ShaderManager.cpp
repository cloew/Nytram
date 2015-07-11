#include "ShaderManager.h"

void ShaderManager::addShader(GLuint id, const char* filePath, GLenum shaderType)
{
	idToShader[id] = Shader(filePath, shaderType);
}

void ShaderManager::compileShaders()
{
	map<GLuint, Shader>::iterator it;
	for (it = idToShader.begin(); it != idToShader.end(); it++)
    {
		it->second.compile();
    }
}